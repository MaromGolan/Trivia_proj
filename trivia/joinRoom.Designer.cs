
namespace trivia
{
    partial class joinRoom
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

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.currrooms = new System.Windows.Forms.Panel();
            this.tojoin = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // currrooms
            // 
            this.currrooms.Location = new System.Drawing.Point(172, 76);
            this.currrooms.Name = "currrooms";
            this.currrooms.Size = new System.Drawing.Size(222, 149);
            this.currrooms.TabIndex = 0;
            // 
            // tojoin
            // 
            this.tojoin.Location = new System.Drawing.Point(533, 373);
            this.tojoin.Name = "tojoin";
            this.tojoin.Size = new System.Drawing.Size(80, 34);
            this.tojoin.TabIndex = 1;
            this.tojoin.Text = "Join";
            this.tojoin.UseVisualStyleBackColor = true;
            this.tojoin.Click += new System.EventHandler(this.tojoin_Click_1);
            // 
            // joinRoom
            // 
            this.ClientSize = new System.Drawing.Size(625, 419);
            this.Controls.Add(this.tojoin);
            this.Controls.Add(this.currrooms);
            this.Name = "joinRoom";
            this.Load += new System.EventHandler(this.joinRoom_Load_2);
            this.ResumeLayout(false);

        }

        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ListBox roomlist;
        private System.Windows.Forms.Panel currrooms;
        private System.Windows.Forms.Button tojoin;
    }
}