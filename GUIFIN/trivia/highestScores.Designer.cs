
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
            this.top5 = new System.Windows.Forms.TextBox();
            this.exit = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // top5
            // 
            this.top5.Location = new System.Drawing.Point(111, 125);
            this.top5.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.top5.Name = "top5";
            this.top5.Size = new System.Drawing.Size(241, 20);
            this.top5.TabIndex = 1;
            this.top5.TextChanged += new System.EventHandler(this.top5_TextChanged);
            // 
            // exit
            // 
            this.exit.Location = new System.Drawing.Point(9, 261);
            this.exit.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.exit.Name = "exit";
            this.exit.Size = new System.Drawing.Size(99, 23);
            this.exit.TabIndex = 2;
            this.exit.Text = "Exit";
            this.exit.UseVisualStyleBackColor = true;
            this.exit.Click += new System.EventHandler(this.exit_Click_1);
            // 
            // highestScores
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(533, 292);
            this.Controls.Add(this.exit);
            this.Controls.Add(this.top5);
            this.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Name = "highestScores";
            this.Text = "highestScores";
            this.Load += new System.EventHandler(this.highestScores_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.TextBox top5;
        private System.Windows.Forms.Button exit;
    }
}