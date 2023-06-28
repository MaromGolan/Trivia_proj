
using System;

namespace trivia
{
    partial class createRoom
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
            this.Create = new System.Windows.Forms.Button();
            this.num = new System.Windows.Forms.TextBox();
            this.time = new System.Windows.Forms.TextBox();
            this.room = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // Create
            // 
            this.Create.Location = new System.Drawing.Point(311, 245);
            this.Create.Name = "Create";
            this.Create.Size = new System.Drawing.Size(130, 23);
            this.Create.TabIndex = 0;
            this.Create.Text = "Create Room";
            this.Create.UseVisualStyleBackColor = true;
            this.Create.Click += new System.EventHandler(this.Create_Click);
            // 
            // num
            // 
            this.num.Location = new System.Drawing.Point(311, 152);
            this.num.Name = "num";
            this.num.Size = new System.Drawing.Size(130, 20);
            this.num.TabIndex = 2;
            this.num.Text = "Max Number Of Players";
            // 
            // time
            // 
            this.time.Location = new System.Drawing.Point(311, 200);
            this.time.Name = "time";
            this.time.Size = new System.Drawing.Size(130, 20);
            this.time.TabIndex = 3;
            this.time.Text = "Time Per Question";
            this.time.TextChanged += new System.EventHandler(this.time_TextChanged);
            // 
            // room
            // 
            this.room.Location = new System.Drawing.Point(311, 104);
            this.room.Name = "room";
            this.room.Size = new System.Drawing.Size(130, 20);
            this.room.TabIndex = 4;
            this.room.Text = "Room Name";
            this.room.TextChanged += new System.EventHandler(this.textBox1_TextChanged_1);
            // 
            // createRoom
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.room);
            this.Controls.Add(this.time);
            this.Controls.Add(this.num);
            this.Controls.Add(this.Create);
            this.Name = "createRoom";
            this.Text = "Create Room";
            this.Load += new System.EventHandler(this.createRoom_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        
        #endregion

        private System.Windows.Forms.Button Create;
        private System.Windows.Forms.TextBox num;
        private System.Windows.Forms.TextBox time;
        private System.Windows.Forms.TextBox room;
    }
}