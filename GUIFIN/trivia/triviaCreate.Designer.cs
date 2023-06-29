
namespace trivia
{
    partial class triviaCreate
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.createRoomButton = new System.Windows.Forms.Button();
            this.joinRoomButton = new System.Windows.Forms.Button();
            this.loginButton = new System.Windows.Forms.Button();
            this.SignunButton = new System.Windows.Forms.Button();
            this.exitButton = new System.Windows.Forms.Button();
            this.statisticsButton = new System.Windows.Forms.Button();
            this.top3stats = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // createRoomButton
            // 
            this.createRoomButton.Location = new System.Drawing.Point(669, 12);
            this.createRoomButton.Name = "createRoomButton";
            this.createRoomButton.Size = new System.Drawing.Size(130, 23);
            this.createRoomButton.TabIndex = 0;
            this.createRoomButton.Text = "Create A Room";
            this.createRoomButton.UseVisualStyleBackColor = true;
            this.createRoomButton.Click += new System.EventHandler(this.createRoomButton_Click);
            // 
            // joinRoomButton
            // 
            this.joinRoomButton.Location = new System.Drawing.Point(658, 415);
            this.joinRoomButton.Name = "joinRoomButton";
            this.joinRoomButton.Size = new System.Drawing.Size(130, 23);
            this.joinRoomButton.TabIndex = 1;
            this.joinRoomButton.Text = "Join A Room";
            this.joinRoomButton.UseVisualStyleBackColor = true;
            this.joinRoomButton.Click += new System.EventHandler(this.joinRoomButton_Click);
            // 
            // loginButton
            // 
            this.loginButton.Location = new System.Drawing.Point(331, 180);
            this.loginButton.Name = "loginButton";
            this.loginButton.Size = new System.Drawing.Size(130, 23);
            this.loginButton.TabIndex = 2;
            this.loginButton.Text = "Login";
            this.loginButton.UseVisualStyleBackColor = true;
            this.loginButton.Click += new System.EventHandler(this.loginButton_Click);
            // 
            // SignunButton
            // 
            this.SignunButton.Location = new System.Drawing.Point(331, 222);
            this.SignunButton.Name = "SignunButton";
            this.SignunButton.Size = new System.Drawing.Size(130, 23);
            this.SignunButton.TabIndex = 3;
            this.SignunButton.Text = "Signup";
            this.SignunButton.UseVisualStyleBackColor = true;
            this.SignunButton.Click += new System.EventHandler(this.SignunButton_Click);
            // 
            // exitButton
            // 
            this.exitButton.Location = new System.Drawing.Point(2, 415);
            this.exitButton.Name = "exitButton";
            this.exitButton.Size = new System.Drawing.Size(130, 23);
            this.exitButton.TabIndex = 4;
            this.exitButton.Text = "Exit";
            this.exitButton.UseVisualStyleBackColor = true;
            this.exitButton.Click += new System.EventHandler(this.exitButton_Click);
            // 
            // statisticsButton
            // 
            this.statisticsButton.Location = new System.Drawing.Point(2, 12);
            this.statisticsButton.Name = "statisticsButton";
            this.statisticsButton.Size = new System.Drawing.Size(130, 23);
            this.statisticsButton.TabIndex = 5;
            this.statisticsButton.Text = "Your Stats";
            this.statisticsButton.UseVisualStyleBackColor = true;
            this.statisticsButton.Click += new System.EventHandler(this.statisticsButton_Click_1);
            // 
            // top3stats
            // 
            this.top3stats.Location = new System.Drawing.Point(2, 49);
            this.top3stats.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.top3stats.Name = "top3stats";
            this.top3stats.Size = new System.Drawing.Size(130, 23);
            this.top3stats.TabIndex = 6;
            this.top3stats.Text = "Top 3 Users";
            this.top3stats.UseVisualStyleBackColor = true;
            this.top3stats.Click += new System.EventHandler(this.top3stats_Click);
            // 
            // triviaCreate
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.top3stats);
            this.Controls.Add(this.statisticsButton);
            this.Controls.Add(this.exitButton);
            this.Controls.Add(this.SignunButton);
            this.Controls.Add(this.loginButton);
            this.Controls.Add(this.joinRoomButton);
            this.Controls.Add(this.createRoomButton);
            this.Name = "triviaCreate";
            this.Text = "triviaCreate";
            this.Load += new System.EventHandler(this.triviaCreate_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button createRoomButton;
        private System.Windows.Forms.Button joinRoomButton;
        private System.Windows.Forms.Button loginButton;
        private System.Windows.Forms.Button SignunButton;
        private System.Windows.Forms.Button exitButton;
        private System.Windows.Forms.Button statisticsButton;
        private System.Windows.Forms.Button top3stats;
    }
}