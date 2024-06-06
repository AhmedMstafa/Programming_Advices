namespace First_Windows_Forms_Application
{
    partial class FrmMain
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
            this.btnshowpart1 = new System.Windows.Forms.Button();
            this.btnShowFormDialoge = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnshowpart1
            // 
            this.btnshowpart1.BackColor = System.Drawing.SystemColors.ControlText;
            this.btnshowpart1.ForeColor = System.Drawing.Color.Chartreuse;
            this.btnshowpart1.Location = new System.Drawing.Point(319, 23);
            this.btnshowpart1.Name = "btnshowpart1";
            this.btnshowpart1.Size = new System.Drawing.Size(149, 45);
            this.btnshowpart1.TabIndex = 0;
            this.btnshowpart1.Text = "ShowForm";
            this.btnshowpart1.UseVisualStyleBackColor = false;
            this.btnshowpart1.Click += new System.EventHandler(this.btnshowpart1_Click);
            // 
            // btnShowFormDialoge
            // 
            this.btnShowFormDialoge.BackColor = System.Drawing.Color.Blue;
            this.btnShowFormDialoge.ForeColor = System.Drawing.Color.Chartreuse;
            this.btnShowFormDialoge.Location = new System.Drawing.Point(319, 100);
            this.btnShowFormDialoge.Name = "btnShowFormDialoge";
            this.btnShowFormDialoge.Size = new System.Drawing.Size(149, 45);
            this.btnShowFormDialoge.TabIndex = 1;
            this.btnShowFormDialoge.Text = "Show Form As Dialoge";
            this.btnShowFormDialoge.UseVisualStyleBackColor = false;
            this.btnShowFormDialoge.Click += new System.EventHandler(this.btnShowFormDialoge_Click);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(32, 26);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(146, 42);
            this.button1.TabIndex = 2;
            this.button1.Text = "btnMessageBoxFrom";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(32, 101);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(146, 42);
            this.button2.TabIndex = 3;
            this.button2.Text = "btnCheckBoxFrom";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // FrmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.btnShowFormDialoge);
            this.Controls.Add(this.btnshowpart1);
            this.Name = "FrmMain";
            this.Text = "Form2";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnshowpart1;
        private System.Windows.Forms.Button btnShowFormDialoge;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
    }
}