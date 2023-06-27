
namespace trivia
{
    partial class stats
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
            this.ustats = new System.Windows.Forms.TextBox();
            this.exit = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // ustats
            // 
            this.ustats.Location = new System.Drawing.Point(482, 238);
            this.ustats.Name = "ustats";
            this.ustats.Size = new System.Drawing.Size(148, 26);
            this.ustats.TabIndex = 0;
            this.ustats.TextChanged += new System.EventHandler(this.ustats_TextChanged);
            // 
            // exit
            // 
            this.exit.Location = new System.Drawing.Point(12, 647);
            this.exit.Name = "exit";
            this.exit.Size = new System.Drawing.Size(161, 33);
            this.exit.TabIndex = 1;
            this.exit.Text = "Exit";
            this.exit.UseVisualStyleBackColor = true;
            // 
            // stats
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1200, 692);
            this.Controls.Add(this.exit);
            this.Controls.Add(this.ustats);
            this.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.Name = "stats";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.stats_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox ustats;
        private System.Windows.Forms.Button exit;
    }
}