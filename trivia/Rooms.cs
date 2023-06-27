using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Net.Http;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

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
        

        public Rooms(room r)
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
                //waiting for admin to start
                //waiting to get started from the server  
            }
            //call for question setter and send the request to server
            nextButton.Enabled = true;
            nextButton.Visible = true;
            DisplayQuestion(sender, e);
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
        private void DisplayQuestion(object sender, EventArgs e)
        {
            if (numQuestion < 10)
            {
                answerOptionsPanel.Visible = true;
                // Update the question label
                DateTime startTime = DateTime.UtcNow;
                TimeSpan breakDuration = TimeSpan.FromSeconds(this.time);

                // option 1
                while (DateTime.UtcNow - startTime < breakDuration)
                {
                    // do some work

                    Question currentQuestion = questions[numQuestion];
                    questionLabel.Text = currentQuestion.Text;

                    // Clear any previous answer options
                    answerOptionsPanel.Controls.Clear();

                    // Create and add radio buttons for each answer option
                    foreach (string option in currentQuestion.AnswerOptions)
                    {
                        RadioButton radioButton = new RadioButton();
                        radioButton.Text = option;
                        radioButton.AutoSize = true;
                        radioButton.Font = new Font("Arial", 12);
                        answerOptionsPanel.Controls.Add(radioButton);
                    }
                    // Enable the next button
                    nextButton.Enabled = true;
                    nextButton.Visible = true;
                }
                MessageBox.Show("times up");
                nextButton_Click(sender, e); 
            }
            else
            {
                // No more questions, game over
                MessageBox.Show("Game Over!");
                Close();
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
                    return;
                }

                // Move to the next question
                numQuestion++;
                DisplayQuestion(sender, e);
            }
            else
            {
                started = true;
                nextButton.Text = "next";
                DisplayQuestion(sender, e);
            }
        }
        private void exit_Click(object sender, EventArgs e)
        {
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
        public string Text { get; }
        public List<string> AnswerOptions { get; }
        public string CorrectAnswer { get; }

        public Question(string text, List<string> answerOptions, string correctAnswer)
        {
            Text = text;
            AnswerOptions = answerOptions;
            CorrectAnswer = correctAnswer;
        }
    }
}