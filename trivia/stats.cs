using System;
using System.Windows.Forms;
using System.Net.Http;
using System.Net.Sockets;
using System.Net;
using Newtonsoft.Json;

namespace trivia
{
    public partial class stats : Form
    {
        TcpClient usersocket;
        public stats(TcpClient usock)
        {
            InitializeComponent();
            usersocket = usock;
        }
        private void stats_Load(object sender, EventArgs e)
        {
            Message m = new Message(7, "getuserstats");
            string JSONmessage = JsonConvert.SerializeObject(m, Formatting.Indented);
            NetworkStream stream = usersocket.GetStream();
            byte[] data = System.Text.Encoding.ASCII.GetBytes(JSONmessage);
            stream.Write(data, 0, data.Length);
            byte[] buffer = new byte[1024];
            int bytesRead = stream.Read(buffer, 0, buffer.Length);
            string response = System.Text.Encoding.ASCII.GetString(buffer, 0, bytesRead);
            Message JSONresponse = JsonConvert.DeserializeObject<Message>(response);
            textBox1.Text = JSONresponse.message;
        }
        private void exit_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
