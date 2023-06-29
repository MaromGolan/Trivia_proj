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
    public partial class login : Form
    {
        public string Username { get; private set; }
        public string Password { get; private set; }
        TcpClient usersock;

        public login(TcpClient usersock)
        {
            InitializeComponent();
            this.usersock = usersock;
        }

        private void lb_Click(object sender, EventArgs e)
        {
            string username = String.Empty;
            while (string.IsNullOrEmpty(username))
            {
                username = un.Text.Trim();
                if (!string.IsNullOrEmpty(username))
                {
                    Username = username;
                    DialogResult = DialogResult.OK;
                    break;    
                }
                else
                {
                    MessageBox.Show("Please enter a username.");
                }
            }
            string password = String.Empty;
            while (string.IsNullOrEmpty(username))
            {
                password = pa.Text.Trim();
                if (!string.IsNullOrEmpty(username))
                {
                    Password = password;
                    DialogResult = DialogResult.OK;
                    break;
                }
                else
                {
                    MessageBox.Show("Please enter a Password");
                }
            }
            Message message = new Message(1, "," + username + "," + password);
            string JSONmessage = JsonConvert.SerializeObject(message, Formatting.Indented);
            NetworkStream stream = usersock.GetStream();
            byte[] data = System.Text.Encoding.ASCII.GetBytes(JSONmessage);
            stream.Write(data, 0, data.Length);
            Close();
             
        }
        private void login_Load(object sender, EventArgs e)
        {
        }

        private void room_TextChanged(object sender, EventArgs e)
        {

        }

        private void time_TextChanged(object sender, EventArgs e)
        {

        }

        private void num_TextChanged(object sender, EventArgs e)
        {

        }


        private void login_Load_1(object sender, EventArgs e)
        {

        }
    }
}
