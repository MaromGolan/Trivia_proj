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
    public partial class createRoom : Form
    {
        public room r;
        public List<user> users;
        public createRoom(List<user> u)
        {
            InitializeComponent();
            this.users = u;
        }

        private void Create_Click(object sender, EventArgs e)
        {
            string RoomName = room.Text.Trim();
            string creatorname = cn.Text.Trim();
            int TimePerQuestion = Int32.Parse(time.Text.Trim());
            int NumberOfPlayers = Int32.Parse(num.Text.Trim());
            this.r = new trivia.room(RoomName,TimePerQuestion,NumberOfPlayers,creatorname,users);
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
