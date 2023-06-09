
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
            this.roomslist = new System.Windows.Forms.ListBox();
            this.SuspendLayout();
            // 
            // roomslist
            // 
            this.roomslist.FormattingEnabled = true;
            this.roomslist.Location = new System.Drawing.Point(155, 55);
            this.roomslist.Name = "roomslist";
            this.roomslist.Size = new System.Drawing.Size(207, 238);
            this.roomslist.TabIndex = 0;
            this.roomslist.SelectedIndexChanged += new System.EventHandler(this.roomslist_SelectedIndexChanged);
            // 
            // joinRoom
            // 
            this.ClientSize = new System.Drawing.Size(625, 419);
            this.Controls.Add(this.roomslist);
            this.Name = "joinRoom";
            this.Load += new System.EventHandler(this.joinRoom_Load_2);
            this.ResumeLayout(false);

        }

        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ListBox roomlist;
        private System.Windows.Forms.ListBox roomslist;
    }
}