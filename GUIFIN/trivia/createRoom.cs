using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Newtonsoft.Json;
using System.Net.Http;
using System.Net.Sockets;
using System.Net;
namespace trivia
{
    public partial class createRoom : Form
    {
        public room r;
        public user u;
        TcpClient usersocket;
        public createRoom(TcpClient usock, user u)
        {
            InitializeComponent();
            usersocket = usock;
            this.u = u;
        }

        private void Create_Click(object sender, EventArgs e)
        {
            string RoomName = room.Text.Trim();
            int TimePerQuestion = Int32.Parse(time.Text.Trim());
            int NumberOfPlayers = Int32.Parse(num.Text.Trim());
            r = new room(RoomName,TimePerQuestion,NumberOfPlayers,u);
            Message m = new Message(3, RoomName + "," + TimePerQuestion + "," + NumberOfPlayers);
            string JSONmessage = JsonConvert.SerializeObject(m, Formatting.Indented);
            NetworkStream stream = usersocket.GetStream();
            byte[] data = System.Text.Encoding.ASCII.GetBytes(JSONmessage);
            stream.Write(data, 0, data.Length);
            DialogResult = DialogResult.OK;
            Close();
        }

        private void createRoom_Load(object sender, EventArgs e)
        {
            
        }

        private void maskedTextBox1_MaskInputRejected(object sender, MaskInputRejectedEventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged_1(object sender, EventArgs e)
        {

        }

        private void time_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged_2(object sender, EventArgs e)
        {

        }
    }
}
