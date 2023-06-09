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
    public partial class joinRoom : Form
    {
        public string SelectedRoom { get; private set; }
        List<room> rooms;

        public joinRoom(List<room> r)
        {
            InitializeComponent();
            rooms = r;
        }

        private void joinRoom_Load(object sender, EventArgs e)
        {

            
        }

        private void joinRoomButton_Click(object sender, EventArgs e)
        {
            roomslist.DataSource = rooms;


            /*if (roomListBox.SelectedItem != null)
            {

                SelectedRoom = roomListBox.SelectedItem.ToString();
                DialogResult = DialogResult.OK;
                Close();
            }
            else
            {
                MessageBox.Show("Please select a room to join.");
            }*/
        }

        private void checkedroomslist_SelectedIndexChanged(object sender, EventArgs e)
        {
        }

        private void joinRoom_Load_1(object sender, EventArgs e)
        {

        }


        private void joinRoom_Load_2(object sender, EventArgs e)
        {

        }

        private void roomslist_SelectedIndexChanged(object sender, EventArgs e)
        {
            roomslist.DataSource = rooms;

        }
    }
}
