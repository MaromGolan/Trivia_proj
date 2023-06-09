using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace trivia
{
    public partial class login : Form
    {
        public string Username { get; private set; }
        public string Password { get; private set; }

        List<user> users;
        public login(List<user> u)
        {
            InitializeComponent();
            users = u;
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
                    Close();
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
                    Close();
                }
                else
                {
                    MessageBox.Show("Please enter a Password");
                }
            }
            //if(getfromdbthepasswordandcheck);
            user u = new user();
            u.Username = username;
            u.Password = password;
            users.Add(u);
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
