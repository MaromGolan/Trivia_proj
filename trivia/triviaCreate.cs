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
            
namespace trivia
{
    public partial class triviaCreate : Form
    {
        private string currentPlayer;
        private string currentRoom;
        public List<user> users;
        public List<room> rooms;
        TcpClient usersock;
        public triviaCreate()
        {
            InitializeComponent();
            this.users = new List<user>();
            this.rooms = new List<room>();
            currentPlayer = String.Empty;
            try
            {
                string serverIP = "127.0.0.1"; 
                int serverPort = 8826;

                usersock = new TcpClient();
                usersock.Connect(serverIP, serverPort);

                if (usersock.Connected)
                {
                    Console.WriteLine("Connected to the server.");

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

        private void exitButton_Click_1(object sender, EventArgs e)
        {
            Application.Exit();

        }

        
    }

}