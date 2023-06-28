using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Net.Http;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Newtonsoft.Json;
using System.Net;
namespace trivia
{//TO ADD A START BUTTON TO FOR THE ADMIN THAT MOVES HIM TO THIS PAGE, AND A PROMPT THAT WHEN PRESSING YES MOVES THE USER TO THIS PAGE
    public partial class Rooms : Form
    {
        public int numQuestion { get; set; }
        public List<Question> questions { get; set; }
        public int time { get; set; }
        public int max { get; set; }
        public string name{ get; set; }
        public string admin { get; set; }
        public string thisuser { get; set; }
        static public bool started { get; set; }
        static public user[] ingame { get; set; }
        TcpClient usersocket;
        int correct;
        int totaltime;



        public Rooms(room r,TcpClient usock)
        {
            InitializeComponent();
            this.questions = new List<Question>();
            ingame = r.ingame;
            this.time = r.TimePerQuestion;
            this.max = r.NumberOfPlayers;
            this.name = r.RoomName;
            this.admin = r.ingame[0].Username;
            this.thisuser = r.ingame[r.ingame.Length-1].Username;
            started = false;
            usersocket = usock;
            correct = 0;
            totaltime = 0;
            numQuestion = 0;
        }
        private void GameStarter()
        {
            if (thisuser == admin)
            {
                NetworkStream stream = usersocket.GetStream();
                byte[] buffer = new byte[1024];
                int bytesRead;
                string response;
                Task wait = QuestionSetter();
                for (int i = 10; i > 0; i--)
                {
                    string JSONmessage = JsonConvert.SerializeObject(questions[i], Formatting.Indented);
                    stream = usersocket.GetStream();
                    byte[] data = System.Text.Encoding.ASCII.GetBytes(JSONmessage);
                    stream.Write(data, 0, data.Length);
                }
                MessageBox.Show("Game is Starting");
            }
            else
            {
                for (int i = 0; i < 10; i++)
                {
                    NetworkStream stream = usersocket.GetStream();
                    byte[] buffer = new byte[1024];
                    int bytesRead = stream.Read(buffer, 0, buffer.Length);
                    string response = System.Text.Encoding.ASCII.GetString(buffer, 0, bytesRead);
                    questions.Add(JsonConvert.DeserializeObject<Question>(response));
                }
                MessageBox.Show("Game is Starting");
            }
            nextButton.Enabled = true;
            nextButton.Visible = true;
            DisplayQuestion();
        }
        private void Rooms_Load(object sender, EventArgs e)
        {
            if (thisuser == admin)
            {
                nextButton.Enabled = true;
                nextButton.Visible = true;
                nextButton.Text = "Start";
            }
            questionLabel.Text = "Welcome To " + name;
            answerOptionsPanel.Visible = false;
            while (!started)
            {
                NetworkStream stream = usersocket.GetStream();
                byte[] buffer = new byte[1024];
                int bytesRead = stream.Read(buffer, 0, buffer.Length);
                string response = System.Text.Encoding.ASCII.GetString(buffer, 0, bytesRead);
                Message JSONresponse = JsonConvert.DeserializeObject<Message>(response);
                if (String.Equals(JSONresponse.message, "started"))
                    started = true;
            }
            GameStarter();
        }

        public async Task<string> GetChatCompletion(string apiKey, string query)//i got chatgpt to give me a random question each time
        {
            using (HttpClient usersock = new HttpClient())
            {
                usersock.BaseAddress = new Uri("https://api.openai.com/");
                usersock.DefaultRequestHeaders.Add("Authorization", $"Bearer {apiKey}");
                usersock.DefaultRequestHeaders.Add("Content-Type", "application/json");

                string requestBody = $@"{{
            ""model"": ""gpt-3.5-turbo"",
            ""query"": ""{query}"",
            ""max_tokens"": 100
        }}";

                HttpResponseMessage response = await usersock.PostAsync("v1/chat/completions", new StringContent(requestBody, Encoding.UTF8, "application/json"));
                string responseBody = await response.Content.ReadAsStringAsync();

                return responseBody;
            }
        }
        public async Task QuestionSetter()
        {
            string key = "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";
            for (int j = 0; j < 10; j++)
            {
                string question = String.Empty;
                string correct = String.Empty;

                string response = await GetChatCompletion(key, "please generate a random question followed up by 4 answers(one of them being the correct answer and the rest being wrong)");
                string[] sorted = response.Split('\n');
                List<string> answers = new List<string>();
                for (int i = 0; i < sorted.Length; i++)
                {
                    if (sorted[i].Contains("(Correct Answer)"))
                    {
                        sorted[i].Replace("(Correct Answer)", "");
                        correct = sorted[i];
                    }
                    if(i == 0)
                    {
                        question = sorted[i];
                    }
                    else
                    {
                        answers.Add(sorted[i]);
                    }
                }
                Question q = new Question(question,answers,correct);
                questions.Add(q);
            }
        }
        private void gameEnded()
        {
            MessageBox.Show("Game Over! Winner will be shown when everyone finishes!");
            Message message = new Message(17, "user finished game");
            string JSONmessage = JsonConvert.SerializeObject(message, Formatting.Indented);
            NetworkStream stream = usersocket.GetStream();
            byte[] data = System.Text.Encoding.ASCII.GetBytes(JSONmessage);
            stream.Write(data, 0, data.Length);

            byte[] buffer = new byte[1024];
            int bytesRead = stream.Read(buffer, 0, buffer.Length);
            string response = System.Text.Encoding.ASCII.GetString(buffer, 0, bytesRead);
            Message JSONresponse = JsonConvert.DeserializeObject<Message>(response);
            MessageBox.Show("The Winner Is: " + JSONresponse.message);
            if (thisuser == admin)
            {
                nextButton.Enabled = true;
                nextButton.Visible = true;
                nextButton.Text = "Start";
            }
            else
            {
                nextButton.Enabled = false;
                nextButton.Visible = false;
            }
            buffer = new byte[1024];
            bytesRead = stream.Read(buffer, 0, buffer.Length);
            response = System.Text.Encoding.ASCII.GetString(buffer, 0, bytesRead);
            JSONresponse = JsonConvert.DeserializeObject<Message>(response);
            if (String.Equals(JSONresponse.message, "start"))
            {
                GameStarter();
            }
            else if (String.Equals(JSONresponse.message, "admin left"))
            {
                MessageBox.Show("Admin has left please press exit");
            }
        }
        private void DisplayQuestion()
        {
            if (numQuestion < 10)
            {
                answerOptionsPanel.Visible = true;
                // Update the question label
                DateTime startTime = DateTime.UtcNow;
                TimeSpan breakDuration = TimeSpan.FromSeconds(this.time);
                nextButton.Enabled = true;
                nextButton.Visible = true;
                while (DateTime.UtcNow - startTime < breakDuration)
                {
                    Question currentQuestion = questions[numQuestion];
                    questionLabel.Text = currentQuestion.question;
                    answerOptionsPanel.Controls.Clear();
                    foreach (string option in currentQuestion.AnswerOptions)
                    {
                        RadioButton radioButton = new RadioButton();
                        radioButton.Text = option;
                        radioButton.AutoSize = true;
                        radioButton.Font = new Font("Arial", 12);
                        answerOptionsPanel.Controls.Add(radioButton);
                    }
                    totaltime += (int)(DateTime.UtcNow - startTime).TotalSeconds;
                }
                MessageBox.Show("times up, Please Press Next");
            }
            else
            {
                gameEnded();
            }
        }
        private void nextButton_Click(object sender, EventArgs e)
        {
            if (String.Equals(nextButton.Text, "next"))
            {
                // Check the selected answer
                Question currentQuestion = questions[numQuestion];
                RadioButton selectedRadioButton = answerOptionsPanel.Controls.OfType<RadioButton>().FirstOrDefault(r => r.Checked);

                if (selectedRadioButton != null)
                {
                    string selectedAnswer = selectedRadioButton.Text;
                    if (selectedAnswer == currentQuestion.CorrectAnswer)
                    {
                        // Correct answer
                        MessageBox.Show("Correct!");
                        correct++;
                    }
                    else
                    {
                        // Incorrect answer
                        MessageBox.Show($"Incorrect! The correct answer is: {currentQuestion.CorrectAnswer}");
                    }
                }
                else
                {
                    MessageBox.Show($"Incorrect! The correct answer is: {currentQuestion.CorrectAnswer}");
                }

                // Move to the next question
                numQuestion++;
                NetworkStream stream = usersocket.GetStream();
                Message message = new Message(16, questions[numQuestion].question + "," + correct + "," + (numQuestion - correct) + "," + totaltime/numQuestion);
                string JSONmessage = JsonConvert.SerializeObject(message, Formatting.Indented);
                byte[] data = System.Text.Encoding.ASCII.GetBytes(JSONmessage);
                stream.Write(data, 0, data.Length);

                DisplayQuestion();
            }
            else
            {
                started = true;
                nextButton.Text = "next";
                NetworkStream stream = usersocket.GetStream();
                Message message = new Message(11, "start");
                string JSONmessage = JsonConvert.SerializeObject(message, Formatting.Indented);
                byte[] data = System.Text.Encoding.ASCII.GetBytes(JSONmessage);
                stream.Write(data, 0, data.Length);
                DisplayQuestion();
            }
        }
        private void exit_Click(object sender, EventArgs e)
        {
            if (thisuser == admin)
            {
                NetworkStream stream = usersocket.GetStream();
                Message message = new Message(10, "admin left");
                string JSONmessage = JsonConvert.SerializeObject(message, Formatting.Indented);
                byte[] data = System.Text.Encoding.ASCII.GetBytes(JSONmessage);
                stream.Write(data, 0, data.Length);
            }
            else
            {
                NetworkStream stream = usersocket.GetStream();
                Message message = new Message(13, "user left");
                string JSONmessage = JsonConvert.SerializeObject(message, Formatting.Indented);
                byte[] data = System.Text.Encoding.ASCII.GetBytes(JSONmessage);
                stream.Write(data, 0, data.Length);
            }
            MessageBox.Show("Leaving room");
            Close();
        }

        private void nextButton_Click_1(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {

        }
    }
    public class Question
    {
        public string question { get; }
        public List<string> AnswerOptions { get; }
        public string CorrectAnswer { get; }

        public Question(string question, List<string> answerOptions, string correctAnswer)
        {
            this.question = question;
            AnswerOptions = answerOptions;
            CorrectAnswer = correctAnswer;
        }
    }
}