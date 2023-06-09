
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
            this.createRoomButton.Location = new System.Drawing.Point(1004, 18);
            this.createRoomButton.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.createRoomButton.Name = "createRoomButton";
            this.createRoomButton.Size = new System.Drawing.Size(195, 35);
            this.createRoomButton.TabIndex = 0;
            this.createRoomButton.Text = "Create A Room";
            this.createRoomButton.UseVisualStyleBackColor = true;
            // 
            // joinRoomButton
            // 
            this.joinRoomButton.Location = new System.Drawing.Point(987, 638);
            this.joinRoomButton.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.joinRoomButton.Name = "joinRoomButton";
            this.joinRoomButton.Size = new System.Drawing.Size(195, 35);
            this.joinRoomButton.TabIndex = 1;
            this.joinRoomButton.Text = "Join A Room";
            this.joinRoomButton.UseVisualStyleBackColor = true;
            // 
            // loginButton
            // 
            this.loginButton.Location = new System.Drawing.Point(496, 277);
            this.loginButton.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.loginButton.Name = "loginButton";
            this.loginButton.Size = new System.Drawing.Size(195, 35);
            this.loginButton.TabIndex = 2;
            this.loginButton.Text = "Login";
            this.loginButton.UseVisualStyleBackColor = true;
            // 
            // SignunButton
            // 
            this.SignunButton.Location = new System.Drawing.Point(496, 341);
            this.SignunButton.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.SignunButton.Name = "SignunButton";
            this.SignunButton.Size = new System.Drawing.Size(195, 35);
            this.SignunButton.TabIndex = 3;
            this.SignunButton.Text = "Signup";
            this.SignunButton.UseVisualStyleBackColor = true;
            // 
            // exitButton
            // 
            this.exitButton.Location = new System.Drawing.Point(3, 638);
            this.exitButton.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.exitButton.Name = "exitButton";
            this.exitButton.Size = new System.Drawing.Size(195, 35);
            this.exitButton.TabIndex = 4;
            this.exitButton.Text = "Exit";
            this.exitButton.UseVisualStyleBackColor = true;
            // 
            // statisticsButton
            // 
            this.statisticsButton.Location = new System.Drawing.Point(3, 18);
            this.statisticsButton.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.statisticsButton.Name = "statisticsButton";
            this.statisticsButton.Size = new System.Drawing.Size(195, 35);
            this.statisticsButton.TabIndex = 5;
            this.statisticsButton.Text = "Your Stats";
            this.statisticsButton.UseVisualStyleBackColor = true;
            // 
            // top3stats
            // 
            this.top3stats.Location = new System.Drawing.Point(3, 76);
            this.top3stats.Name = "top3stats";
            this.top3stats.Size = new System.Drawing.Size(195, 36);
            this.top3stats.TabIndex = 6;
            this.top3stats.Text = "Top 3 Users";
            this.top3stats.UseVisualStyleBackColor = true;
            this.top3stats.Click += new System.EventHandler(this.top3stats_Click);
            // 
            // triviaCreate
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.ClientSize = new System.Drawing.Size(1200, 692);
            this.Controls.Add(this.top3stats);
            this.Controls.Add(this.statisticsButton);
            this.Controls.Add(this.exitButton);
            this.Controls.Add(this.SignunButton);
            this.Controls.Add(this.loginButton);
            this.Controls.Add(this.joinRoomButton);
            this.Controls.Add(this.createRoomButton);
            this.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
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