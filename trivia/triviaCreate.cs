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

namespace trivia
{
    public partial class triviaCreate : Form
    {
        private string currentPlayer;
        private string currentRoom;
        public List<user> users;
        public List<room> rooms;
        public triviaCreate()
        {
            InitializeComponent();
            this.users = new List<user>();
            this.rooms = new List<room>();
            currentPlayer = String.Empty;
        }

        private void TriviaGameForm_Load(object sender, EventArgs e)
        {
            
        }
        private void signupButton_Click(object sender, EventArgs e)
        {
            signup signup = new signup(users);
            signup.ShowDialog();
            currentPlayer = signup.Username;
        }

        private void loginButton_Click(object sender, EventArgs e)
        {
            login login = new login(users);
            login.ShowDialog();
            currentPlayer = login.Username;
        }

        private void createRoomButton_Click(object sender, EventArgs e)
        {
            createRoom createRoomForm = new createRoom(users);
            if (createRoomForm.ShowDialog() == DialogResult.OK)
            {
                string roomName = createRoomForm.r.RoomName;
                int timePerQuestion = createRoomForm.r.TimePerQuestion;
                int numberOfPlayers = createRoomForm.r.NumberOfPlayers;
                rooms.Add(createRoomForm.r);
                currentRoom = roomName;
                MessageBox.Show($"Room created:\nName: {roomName}\nTime per question: {timePerQuestion} seconds\nNumber of players: {numberOfPlayers}\n\nPlayer: {currentPlayer}");
                Rooms newroom = new Rooms(createRoomForm.r);
                newroom.Show();
            }
        }

        private void joinRoomButton_Click(object sender, EventArgs e)
        {
            joinRoom joinRoom = new joinRoom(rooms);
            if (joinRoom.ShowDialog() == DialogResult.OK)
            {
                currentRoom = joinRoom.SelectedRoom;
                MessageBox.Show($"Joined Room:\nRoom: {currentRoom}\n\nPlayer: {currentPlayer}");
                foreach(room r in rooms)
                {
                    if (String.Equals(r.RoomName, currentRoom))
                    {
                        Rooms newroom = new Rooms(r);
                        break;
                    }
                }

            }
        }

        private void statisticsButton_Click(object sender, EventArgs e)
        {
            stats ustats = new stats();
            ustats.Show();
        }

        private void exitButton_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void triviaCreate_Load(object sender, EventArgs e)
        {

        }

        private void top3stats_Click(object sender, EventArgs e)
        {
            highestScores h = new highestScores();
            h.Show();
        }
    }

}