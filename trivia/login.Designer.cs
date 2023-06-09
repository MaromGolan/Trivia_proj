
namespace trivia
{
    partial class login
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
            this.un = new System.Windows.Forms.TextBox();
            this.pa = new System.Windows.Forms.TextBox();
            this.lb = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // un
            // 
            this.un.Location = new System.Drawing.Point(335, 160);
            this.un.Name = "un";
            this.un.Size = new System.Drawing.Size(130, 20);
            this.un.TabIndex = 8;
            this.un.Text = "Username";
            this.un.TextChanged += new System.EventHandler(this.room_TextChanged);
            // 
            // pa
            // 
            this.pa.Location = new System.Drawing.Point(335, 216);
            this.pa.Name = "pa";
            this.pa.Size = new System.Drawing.Size(130, 20);
            this.pa.TabIndex = 6;
            this.pa.Text = "Password";
            this.pa.TextChanged += new System.EventHandler(this.num_TextChanged);
            // 
            // lb
            // 
            this.lb.Location = new System.Drawing.Point(357, 274);
            this.lb.Name = "lb";
            this.lb.Size = new System.Drawing.Size(75, 23);
            this.lb.TabIndex = 5;
            this.lb.Text = "Login";
            this.lb.UseVisualStyleBackColor = true;
            this.lb.Click += new System.EventHandler(this.lb_Click);
            // 
            // login
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.un);
            this.Controls.Add(this.pa);
            this.Controls.Add(this.lb);
            this.Name = "login";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.login_Load_1);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox un;
        private System.Windows.Forms.TextBox pa;
        private System.Windows.Forms.Button lb;
    }
}

