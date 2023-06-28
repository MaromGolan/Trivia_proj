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
    public partial class signup : Form
    {
        public string Username { get; private set; }
        public string Password { get; private set; }
        public string Email { get; private set; }
        TcpClient usersock;

        public List<user> users;
        public signup(TcpClient usock)
        {
            InitializeComponent();
            usersock = usock;
        }

        private void sb_Click(object sender, EventArgs e)
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
            while (string.IsNullOrEmpty(password))
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
                    MessageBox.Show("Please enter a password.");
                }
            }
            string email = String.Empty;
            while (string.IsNullOrEmpty(password))
            {
                email = em.Text.Trim();
                if (!string.IsNullOrEmpty(username))
                {
                    Email = email;
                    DialogResult = DialogResult.OK;
                    break;
                }
                else
                {
                    MessageBox.Show("Please enter an email.");
                }
            }
            Message message = new Message(2, "," + username + "," + password + "," + email);
            string JSONmessage = JsonConvert.SerializeObject(message, Formatting.Indented);
            NetworkStream stream = usersock.GetStream();
            byte[] data = System.Text.Encoding.ASCII.GetBytes(JSONmessage);
            stream.Write(data, 0, data.Length);
        }
        private void un_TextChanged(object sender, EventArgs e)
        {

        }

        private void pa_TextChanged(object sender, EventArgs e)
        {

        }

        private void em_TextChanged(object sender, EventArgs e)
        {

        }

        private void signup_Load(object sender, EventArgs e)
        {

        }
    }

}
