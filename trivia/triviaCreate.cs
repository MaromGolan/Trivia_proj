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
    public partial class triviaCreate : Form
    {
        private string currentPlayer;
        private string currentRoom;
        public List<room> rooms;
        public List<user> users;
        user user;
        TcpClient usersock;
        public triviaCreate()
        {
            InitializeComponent();
            currentPlayer = String.Empty;
            buttonChanger(false);
            string serverIP = "127.0.0.1";
            int serverPort = 8826;
            usersock = new TcpClient();
            usersock.Connect(serverIP, serverPort);
        }


        private void TriviaGameForm_Load(object sender, EventArgs e)
        {
            
        }
        private void signupButton_Click(object sender, EventArgs e)
        {
            if (String.Equals(this.currentPlayer, String.Empty))
            { 
                signup signup = new signup(this.usersock);
                signup.ShowDialog();
                currentPlayer = signup.Username;
                user = new user(currentPlayer, signup.Password, signup.Email);
                buttonChanger(true);
            }
        }
        private void loginButton_Click(object sender, EventArgs e)
        {
            if (String.Equals(this.currentPlayer, String.Empty))
            {
                login login = new login(this.usersock);
                login.ShowDialog();
                currentPlayer = login.Username;
                user = new user(currentPlayer, login.Password, "dmiga@gmail.com");
                buttonChanger(true);
            }
        }

        private void createRoomButton_Click(object sender, EventArgs e)
        {
            createRoom createRoomForm = new createRoom(usersock,user);
            if (createRoomForm.ShowDialog() == DialogResult.OK)
            {
                MessageBox.Show($"Room created:\nName: {createRoomForm.r.RoomName}\nTime per question: {createRoomForm.r.TimePerQuestion} seconds\nNumber of players: {createRoomForm.r.NumberOfPlayers}\n\nPlayer: {currentPlayer}");
                Rooms newroom = new Rooms(createRoomForm.r,usersock);
                newroom.Show();
            }
        }

        private void joinRoomButton_Click(object sender, EventArgs e)
        {
            joinRoom joinRoom = new joinRoom(this.usersock);
            if (joinRoom.ShowDialog() == DialogResult.OK)
            {
                currentRoom = joinRoom.SelectedRoom;
                MessageBox.Show($"Joined Room:\nRoom: {currentRoom}\n\nPlayer: {currentPlayer}");
                foreach(room r in rooms)
                {
                    if (String.Equals(r.RoomName, currentRoom))
                    {
                        Rooms newroom = new Rooms(r,usersock);
                        break;
                    }
                }

            }
        }

        private void statisticsButton_Click(object sender, EventArgs e)
        {
            stats ustats = new stats(usersock);
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

        private void exitButton_Click_1(object sender, EventArgs e)
        {
            Application.Exit();

        }

        private void buttonChanger(bool t)
        {
            createRoomButton.Visible = t;
            top3stats.Visible = t;
            joinRoomButton.Visible = t;
            statisticsButton.Visible = t;
            top3stats.Enabled = t;
            statisticsButton.Enabled = t;
            joinRoomButton.Enabled = t;
            createRoomButton.Enabled = t;
            SignunButton.Enabled = !t;
            SignunButton.Visible= !t;
            loginButton.Enabled = !t;
            loginButton.Visible = !t;

        }
    }
    
}

/*try
            {
                string serverIP = "127.0.0.1"; 
                int serverPort = 8826;

                usersock = new TcpClient();
                usersock.Connect(serverIP, serverPort);

                if (usersock.Connected)
                {
                

                    NetworkStream stream = usersock.GetStream();

                    // Send data to the server
                    string message = "Hello, server!";
                    byte[] data = System.Text.Encoding.ASCII.GetBytes(message);
                    stream.Write(data, 0, data.Length);

                    // Receive data from the server
                    byte[] buffer = new byte[1024];
                    int bytesRead = stream.Read(buffer, 0, buffer.Length);
                    string response = System.Text.Encoding.ASCII.GetString(buffer, 0, bytesRead);
                    Console.WriteLine("Server response: " + response);
                    MessageBox.Show("Server said: " + response);
                    //stream.Close();
                    //usersock.Close();
                }
                else
                {
                    Console.WriteLine("Failed to connect to the server.");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("An error occurred: " + ex.Message);
            }
*/