using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Net.Http;
using System.Net.Sockets;
using System.Net;
using Newtonsoft.Json;

namespace trivia
{
    public partial class joinRoom : Form
    {
        public string SelectedRoom { get; private set; }
        TcpClient usersock;
        List<room> rooms;

        public joinRoom(TcpClient usersock)
        {
            InitializeComponent();
            this.usersock = usersock;
        }

        private void joinRoom_Load(object sender, EventArgs e)
        {
            while (true)
            {
                GetRooms();
                DateTime startTime = DateTime.UtcNow;
                TimeSpan breakDuration = TimeSpan.FromSeconds(3);
                while (DateTime.UtcNow - startTime < breakDuration)
                {
                    foreach (room r in rooms)
                    {
                        RadioButton radioButton = new RadioButton();
                        radioButton.Text = r.RoomName;
                        radioButton.AutoSize = true;
                        radioButton.Font = new Font("Arial", 12);
                        currrooms.Controls.Add(radioButton);
                    }
                }
            }
        }
        private void tojoin_Click(object sender, EventArgs e)
        {
            RadioButton selectedRadioButton = currrooms.Controls.OfType<RadioButton>().FirstOrDefault(r => r.Checked);
            if (selectedRadioButton != null)
            {
                SelectedRoom = selectedRadioButton.Text;
                Message m = new Message(1, SelectedRoom);
                string JSONmessage = JsonConvert.SerializeObject(m, Formatting.Indented);
                NetworkStream stream = usersock.GetStream();
                byte[] data = System.Text.Encoding.ASCII.GetBytes(JSONmessage);
                stream.Write(data, 0, data.Length);
                DialogResult = DialogResult.OK;
                Close();
            }
        }
        private void GetRooms()
        {
            List<room> newrooms = new List<room>();
            rooms = newrooms;
            Message m = new Message(9, "getamountrooms");
            string JSONmessage = JsonConvert.SerializeObject(m, Formatting.Indented);
            NetworkStream stream = usersock.GetStream();
            byte[] data = System.Text.Encoding.ASCII.GetBytes(JSONmessage);
            stream.Write(data, 0, data.Length);
            byte[] buffer = new byte[1024];
            int bytesRead = stream.Read(buffer, 0, buffer.Length);
            string response = System.Text.Encoding.ASCII.GetString(buffer, 0, bytesRead);
            Message JSONresponse = JsonConvert.DeserializeObject<Message>(response);
            int numrooms = int.Parse(m.message);
            for (int i = 0; i < numrooms; i++)
            {
                bytesRead = stream.Read(buffer, 0, buffer.Length);
                response = System.Text.Encoding.ASCII.GetString(buffer, 0, bytesRead);
                room r = JsonConvert.DeserializeObject<room>(response);
                rooms.Add(r);
            }
        }
    }
}
