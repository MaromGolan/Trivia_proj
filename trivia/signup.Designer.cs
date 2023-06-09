
namespace trivia
{
    partial class signup
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
            this.em = new System.Windows.Forms.TextBox();
            this.pa = new System.Windows.Forms.TextBox();
            this.sb = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // un
            // 
            this.un.Location = new System.Drawing.Point(502, 218);
            this.un.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.un.Name = "un";
            this.un.Size = new System.Drawing.Size(193, 26);
            this.un.TabIndex = 12;
            this.un.Text = "Username";
            this.un.TextChanged += new System.EventHandler(this.un_TextChanged);
            // 
            // em
            // 
            this.em.Location = new System.Drawing.Point(502, 366);
            this.em.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.em.Name = "em";
            this.em.Size = new System.Drawing.Size(193, 26);
            this.em.TabIndex = 11;
            this.em.Text = "Email";
            this.em.TextChanged += new System.EventHandler(this.em_TextChanged);
            // 
            // pa
            // 
            this.pa.Location = new System.Drawing.Point(502, 292);
            this.pa.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.pa.Name = "pa";
            this.pa.Size = new System.Drawing.Size(193, 26);
            this.pa.TabIndex = 10;
            this.pa.Text = "Password";
            this.pa.TextChanged += new System.EventHandler(this.pa_TextChanged);
            // 
            // sb
            // 
            this.sb.Location = new System.Drawing.Point(536, 440);
            this.sb.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.sb.Name = "sb";
            this.sb.Size = new System.Drawing.Size(112, 35);
            this.sb.TabIndex = 9;
            this.sb.Text = "Signup";
            this.sb.UseVisualStyleBackColor = true;
            this.sb.Click += new System.EventHandler(this.sb_Click);
            // 
            // signup
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1200, 692);
            this.Controls.Add(this.un);
            this.Controls.Add(this.em);
            this.Controls.Add(this.pa);
            this.Controls.Add(this.sb);
            this.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.Name = "signup";
            this.Text = "Form2";
            this.Load += new System.EventHandler(this.signup_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox un;
        private System.Windows.Forms.TextBox em;
        private System.Windows.Forms.TextBox pa;
        private System.Windows.Forms.Button sb;
    }
}