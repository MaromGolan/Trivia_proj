namespace trivia
{
    partial class Rooms
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
            this.questionLabel = new System.Windows.Forms.Label();
            this.answerOptionsPanel = new System.Windows.Forms.Panel();
            this.nextButton = new System.Windows.Forms.Button();
            this.exit = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // questionLabel
            // 
            this.questionLabel.AutoSize = true;
            this.questionLabel.Location = new System.Drawing.Point(310, 138);
            this.questionLabel.Name = "questionLabel";
            this.questionLabel.Size = new System.Drawing.Size(149, 20);
            this.questionLabel.TabIndex = 0;
            this.questionLabel.Text = "questionwillbnehere";
            // 
            // answerOptionsPanel
            // 
            this.answerOptionsPanel.Enabled = false;
            this.answerOptionsPanel.Location = new System.Drawing.Point(287, 201);
            this.answerOptionsPanel.Name = "answerOptionsPanel";
            this.answerOptionsPanel.Size = new System.Drawing.Size(200, 100);
            this.answerOptionsPanel.TabIndex = 1;
            this.answerOptionsPanel.Visible = false;
            // 
            // nextButton
            // 
            this.nextButton.Enabled = false;
            this.nextButton.Location = new System.Drawing.Point(638, 384);
            this.nextButton.Name = "nextButton";
            this.nextButton.Size = new System.Drawing.Size(119, 38);
            this.nextButton.TabIndex = 2;
            this.nextButton.Text = "Next";
            this.nextButton.UseVisualStyleBackColor = true;
            this.nextButton.Visible = false;
            this.nextButton.Click += new System.EventHandler(this.nextButton_Click_1);
            // 
            // exit
            // 
            this.exit.Location = new System.Drawing.Point(12, 384);
            this.exit.Name = "exit";
            this.exit.Size = new System.Drawing.Size(119, 38);
            this.exit.TabIndex = 3;
            this.exit.Text = "Leave Room";
            this.exit.UseVisualStyleBackColor = true;
            // 
            // Rooms
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.exit);
            this.Controls.Add(this.nextButton);
            this.Controls.Add(this.answerOptionsPanel);
            this.Controls.Add(this.questionLabel);
            this.Name = "Rooms";
            this.Text = "Rooms";
            this.Load += new System.EventHandler(this.Rooms_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label questionLabel;
        private System.Windows.Forms.Panel answerOptionsPanel;
        private System.Windows.Forms.Button nextButton;
        private System.Windows.Forms.Button exit;
    }
}