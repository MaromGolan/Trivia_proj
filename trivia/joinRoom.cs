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
            while (true)
            {
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
                tojoin_Click(sender, e);
            }
        }
        private void tojoin_Click(object sender, EventArgs e)
        {
            RadioButton selectedRadioButton = currrooms.Controls.OfType<RadioButton>().FirstOrDefault(r => r.Checked);

            if (selectedRadioButton != null)
            {
                SelectedRoom = selectedRadioButton.Text;
                DialogResult = DialogResult.OK;
                Close();
            }
            else
            {
                return;
            }
        }
        

        private void joinRoom_Load_1(object sender, EventArgs e)
        {

        }


        private void joinRoom_Load_2(object sender, EventArgs e)
        {

        }

        private void tojoin_Click_1(object sender, EventArgs e)
        {

        }
    }
}
