using System;
using System.Windows.Forms;
//using System.Data.SQLite;
namespace trivia
{
    public partial class stats : Form
    {
        public stats()
        {
            InitializeComponent();
        }

        private void statisticsButton_Click(object sender, EventArgs e)
        {
            //getting the stats from the db
            /*string username = "JohnDoe";

            string connectionString = "Data Source=STATISTICS.db;Version=3;";

            using (SQLiteConnection connection = new SQLiteConnection(connectionString))
            {
                connection.Open();

                string query = "SELECT CORRECT_ANSWERS, WRONG_ANSWERS FROM USERS WHERE USERNAME = @Username";

                using (SQLiteCommand command = new SQLiteCommand(query, connection))
                {
                    command.Parameters.AddWithValue("@Username", username);

                    using (SQLiteDataReader reader = command.ExecuteReader())
                    {
                        if (reader.Read())
                        {
                            int correctAnswers = reader.GetInt32(0);
                            int wrongAnswers = reader.GetInt32(1);

                            Console.WriteLine("Correct Answers: " + correctAnswers);
                            Console.WriteLine("Wrong Answers: " + wrongAnswers);
                        }
                        else
                        {
                            Console.WriteLine("User not found.");
                        }
                    }
                }

                connection.Close();
            }
            */
            //getting stats from the database with the connection to cpp
            highestScores highScoresForm = new highestScores();
            highScoresForm.ShowDialog();
            //DB.GetSTATSOFUSER
        }

        private void stats_Load(object sender, EventArgs e)
        {
            ustats.Text = "stats from server";
        }
        private void exit_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
