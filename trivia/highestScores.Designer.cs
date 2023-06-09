
namespace trivia
{
    partial class highestScores
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
            this.top3 = new System.Windows.Forms.TextBox();
            this.exit = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // top3
            // 
            this.top3.Location = new System.Drawing.Point(338, 192);
            this.top3.Name = "top3";
            this.top3.Size = new System.Drawing.Size(100, 26);
            this.top3.TabIndex = 1;
            // 
            // exit
            // 
            this.exit.Location = new System.Drawing.Point(13, 402);
            this.exit.Name = "exit";
            this.exit.Size = new System.Drawing.Size(149, 36);
            this.exit.TabIndex = 2;
            this.exit.Text = "Exit";
            this.exit.UseVisualStyleBackColor = true;
            // 
            // highestScores
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.exit);
            this.Controls.Add(this.top3);
            this.Name = "highestScores";
            this.Text = "highestScores";
            this.Load += new System.EventHandler(this.highestScores_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.TextBox top3;
        private System.Windows.Forms.Button exit;
    }
}