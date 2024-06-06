namespace Pizza_Project_Requirments
{
    partial class Form1
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
            this.label1 = new System.Windows.Forms.Label();
            this.grSizeBox = new System.Windows.Forms.GroupBox();
            this.rdSizeLarg = new System.Windows.Forms.RadioButton();
            this.rdSizeMedium = new System.Windows.Forms.RadioButton();
            this.rdSizeSmall = new System.Windows.Forms.RadioButton();
            this.grToppingsBox = new System.Windows.Forms.GroupBox();
            this.chToppingsGreenPapers = new System.Windows.Forms.CheckBox();
            this.chToppingsOlives = new System.Windows.Forms.CheckBox();
            this.chToppingsOnion = new System.Windows.Forms.CheckBox();
            this.chToppingsTomatoes = new System.Windows.Forms.CheckBox();
            this.chToppingsMushrooms = new System.Windows.Forms.CheckBox();
            this.chToppingsExtraChees = new System.Windows.Forms.CheckBox();
            this.grCrustTypebox = new System.Windows.Forms.GroupBox();
            this.rdCrustThink = new System.Windows.Forms.RadioButton();
            this.rdCrustThin = new System.Windows.Forms.RadioButton();
            this.grWhereToEatBox = new System.Windows.Forms.GroupBox();
            this.rdTakeOut = new System.Windows.Forms.RadioButton();
            this.rdEatin = new System.Windows.Forms.RadioButton();
            this.fileSystemWatcher1 = new System.IO.FileSystemWatcher();
            this.Lable = new System.Windows.Forms.Label();
            this.grOrderSummary = new System.Windows.Forms.GroupBox();
            this.TotalPrice = new System.Windows.Forms.Label();
            this.TotalPriceLable = new System.Windows.Forms.Label();
            this.WhereToEatCheck = new System.Windows.Forms.Label();
            this.WhateToEateLable = new System.Windows.Forms.Label();
            this.CrustLable = new System.Windows.Forms.Label();
            this.ToopingsCheck = new System.Windows.Forms.Label();
            this.ToppingsLable = new System.Windows.Forms.Label();
            this.OrderCheckSize = new System.Windows.Forms.Label();
            this.btnOrderPizza = new System.Windows.Forms.Button();
            this.btnResetFrom = new System.Windows.Forms.Button();
            this.CrustType = new System.Windows.Forms.Label();
            this.grSizeBox.SuspendLayout();
            this.grToppingsBox.SuspendLayout();
            this.grCrustTypebox.SuspendLayout();
            this.grWhereToEatBox.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.fileSystemWatcher1)).BeginInit();
            this.grOrderSummary.SuspendLayout();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.label1.Font = new System.Drawing.Font("Elephant", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.Red;
            this.label1.Location = new System.Drawing.Point(203, 25);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(396, 41);
            this.label1.TabIndex = 0;
            this.label1.Text = "MAKE YOUR PIZZA";
            // 
            // grSizeBox
            // 
            this.grSizeBox.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.grSizeBox.Controls.Add(this.rdSizeLarg);
            this.grSizeBox.Controls.Add(this.rdSizeMedium);
            this.grSizeBox.Controls.Add(this.rdSizeSmall);
            this.grSizeBox.ForeColor = System.Drawing.SystemColors.ControlText;
            this.grSizeBox.Location = new System.Drawing.Point(32, 94);
            this.grSizeBox.Name = "grSizeBox";
            this.grSizeBox.Size = new System.Drawing.Size(128, 133);
            this.grSizeBox.TabIndex = 1;
            this.grSizeBox.TabStop = false;
            this.grSizeBox.Tag = "10";
            this.grSizeBox.Text = "Size";
            // 
            // rdSizeLarg
            // 
            this.rdSizeLarg.AutoSize = true;
            this.rdSizeLarg.Location = new System.Drawing.Point(34, 93);
            this.rdSizeLarg.Name = "rdSizeLarg";
            this.rdSizeLarg.Size = new System.Drawing.Size(46, 17);
            this.rdSizeLarg.TabIndex = 4;
            this.rdSizeLarg.Tag = "50";
            this.rdSizeLarg.Text = "Larg";
            this.rdSizeLarg.UseVisualStyleBackColor = true;
            this.rdSizeLarg.CheckedChanged += new System.EventHandler(this.rdSizeLarg_CheckedChanged);
            // 
            // rdSizeMedium
            // 
            this.rdSizeMedium.AutoSize = true;
            this.rdSizeMedium.Location = new System.Drawing.Point(34, 60);
            this.rdSizeMedium.Name = "rdSizeMedium";
            this.rdSizeMedium.Size = new System.Drawing.Size(62, 17);
            this.rdSizeMedium.TabIndex = 3;
            this.rdSizeMedium.Tag = "30";
            this.rdSizeMedium.Text = "Meduim";
            this.rdSizeMedium.UseVisualStyleBackColor = true;
            this.rdSizeMedium.CheckedChanged += new System.EventHandler(this.rdSizeMedium_CheckedChanged);
            // 
            // rdSizeSmall
            // 
            this.rdSizeSmall.AutoSize = true;
            this.rdSizeSmall.Location = new System.Drawing.Point(34, 28);
            this.rdSizeSmall.Name = "rdSizeSmall";
            this.rdSizeSmall.Size = new System.Drawing.Size(50, 17);
            this.rdSizeSmall.TabIndex = 2;
            this.rdSizeSmall.Tag = "15";
            this.rdSizeSmall.Text = "Small";
            this.rdSizeSmall.UseVisualStyleBackColor = true;
            this.rdSizeSmall.UseWaitCursor = true;
            this.rdSizeSmall.CheckedChanged += new System.EventHandler(this.rdSizeSmall_CheckedChanged);
            // 
            // grToppingsBox
            // 
            this.grToppingsBox.Controls.Add(this.chToppingsGreenPapers);
            this.grToppingsBox.Controls.Add(this.chToppingsOlives);
            this.grToppingsBox.Controls.Add(this.chToppingsOnion);
            this.grToppingsBox.Controls.Add(this.chToppingsTomatoes);
            this.grToppingsBox.Controls.Add(this.chToppingsMushrooms);
            this.grToppingsBox.Controls.Add(this.chToppingsExtraChees);
            this.grToppingsBox.ForeColor = System.Drawing.SystemColors.ControlText;
            this.grToppingsBox.Location = new System.Drawing.Point(250, 94);
            this.grToppingsBox.Name = "grToppingsBox";
            this.grToppingsBox.Size = new System.Drawing.Size(265, 145);
            this.grToppingsBox.TabIndex = 5;
            this.grToppingsBox.TabStop = false;
            this.grToppingsBox.Text = "Toppings";
            // 
            // chToppingsGreenPapers
            // 
            this.chToppingsGreenPapers.AutoSize = true;
            this.chToppingsGreenPapers.Location = new System.Drawing.Point(144, 110);
            this.chToppingsGreenPapers.Name = "chToppingsGreenPapers";
            this.chToppingsGreenPapers.Size = new System.Drawing.Size(88, 17);
            this.chToppingsGreenPapers.TabIndex = 11;
            this.chToppingsGreenPapers.Tag = "5";
            this.chToppingsGreenPapers.Text = "GreenPapers";
            this.chToppingsGreenPapers.UseVisualStyleBackColor = true;
            this.chToppingsGreenPapers.CheckedChanged += new System.EventHandler(this.chToppingsGreenPapers_CheckedChanged);
            // 
            // chToppingsOlives
            // 
            this.chToppingsOlives.AutoSize = true;
            this.chToppingsOlives.Location = new System.Drawing.Point(144, 73);
            this.chToppingsOlives.Name = "chToppingsOlives";
            this.chToppingsOlives.Size = new System.Drawing.Size(55, 17);
            this.chToppingsOlives.TabIndex = 10;
            this.chToppingsOlives.Tag = "5";
            this.chToppingsOlives.Text = "Olives";
            this.chToppingsOlives.UseVisualStyleBackColor = true;
            this.chToppingsOlives.CheckedChanged += new System.EventHandler(this.chToppingsOlives_CheckedChanged);
            // 
            // chToppingsOnion
            // 
            this.chToppingsOnion.AutoSize = true;
            this.chToppingsOnion.Location = new System.Drawing.Point(144, 40);
            this.chToppingsOnion.Name = "chToppingsOnion";
            this.chToppingsOnion.Size = new System.Drawing.Size(54, 17);
            this.chToppingsOnion.TabIndex = 9;
            this.chToppingsOnion.Tag = "5";
            this.chToppingsOnion.Text = "Onion";
            this.chToppingsOnion.UseVisualStyleBackColor = true;
            this.chToppingsOnion.CheckedChanged += new System.EventHandler(this.chToppingsOnion_CheckedChanged);
            // 
            // chToppingsTomatoes
            // 
            this.chToppingsTomatoes.AutoSize = true;
            this.chToppingsTomatoes.Location = new System.Drawing.Point(30, 110);
            this.chToppingsTomatoes.Name = "chToppingsTomatoes";
            this.chToppingsTomatoes.Size = new System.Drawing.Size(73, 17);
            this.chToppingsTomatoes.TabIndex = 8;
            this.chToppingsTomatoes.Tag = "5";
            this.chToppingsTomatoes.Text = "Tomatoes";
            this.chToppingsTomatoes.UseVisualStyleBackColor = true;
            this.chToppingsTomatoes.CheckedChanged += new System.EventHandler(this.chToppingsTomatoes_CheckedChanged);
            // 
            // chToppingsMushrooms
            // 
            this.chToppingsMushrooms.AutoSize = true;
            this.chToppingsMushrooms.Location = new System.Drawing.Point(30, 73);
            this.chToppingsMushrooms.Name = "chToppingsMushrooms";
            this.chToppingsMushrooms.Size = new System.Drawing.Size(80, 17);
            this.chToppingsMushrooms.TabIndex = 7;
            this.chToppingsMushrooms.Tag = "5";
            this.chToppingsMushrooms.Text = "Mushrooms";
            this.chToppingsMushrooms.UseVisualStyleBackColor = true;
            this.chToppingsMushrooms.CheckedChanged += new System.EventHandler(this.chToppingsMushrooms_CheckedChanged);
            // 
            // chToppingsExtraChees
            // 
            this.chToppingsExtraChees.AutoSize = true;
            this.chToppingsExtraChees.Location = new System.Drawing.Point(30, 40);
            this.chToppingsExtraChees.Name = "chToppingsExtraChees";
            this.chToppingsExtraChees.Size = new System.Drawing.Size(83, 17);
            this.chToppingsExtraChees.TabIndex = 6;
            this.chToppingsExtraChees.Tag = "5";
            this.chToppingsExtraChees.Text = "Extra Chees";
            this.chToppingsExtraChees.UseVisualStyleBackColor = true;
            this.chToppingsExtraChees.CheckedChanged += new System.EventHandler(this.chToppingsExtraChees_CheckedChanged);
            // 
            // grCrustTypebox
            // 
            this.grCrustTypebox.Controls.Add(this.rdCrustThink);
            this.grCrustTypebox.Controls.Add(this.rdCrustThin);
            this.grCrustTypebox.ForeColor = System.Drawing.SystemColors.ControlText;
            this.grCrustTypebox.Location = new System.Drawing.Point(32, 271);
            this.grCrustTypebox.Name = "grCrustTypebox";
            this.grCrustTypebox.Size = new System.Drawing.Size(138, 110);
            this.grCrustTypebox.TabIndex = 12;
            this.grCrustTypebox.TabStop = false;
            this.grCrustTypebox.Text = "Crust Type";
            // 
            // rdCrustThink
            // 
            this.rdCrustThink.AutoSize = true;
            this.rdCrustThink.Location = new System.Drawing.Point(34, 67);
            this.rdCrustThink.Name = "rdCrustThink";
            this.rdCrustThink.Size = new System.Drawing.Size(79, 17);
            this.rdCrustThink.TabIndex = 14;
            this.rdCrustThink.TabStop = true;
            this.rdCrustThink.Tag = "10";
            this.rdCrustThink.Text = "Think Crust";
            this.rdCrustThink.UseVisualStyleBackColor = true;
            this.rdCrustThink.CheckedChanged += new System.EventHandler(this.rdCrustThink_CheckedChanged);
            // 
            // rdCrustThin
            // 
            this.rdCrustThin.AutoSize = true;
            this.rdCrustThin.Location = new System.Drawing.Point(34, 28);
            this.rdCrustThin.Name = "rdCrustThin";
            this.rdCrustThin.Size = new System.Drawing.Size(73, 17);
            this.rdCrustThin.TabIndex = 13;
            this.rdCrustThin.TabStop = true;
            this.rdCrustThin.Tag = "10";
            this.rdCrustThin.Text = "Thin Crust";
            this.rdCrustThin.UseVisualStyleBackColor = true;
            this.rdCrustThin.UseWaitCursor = true;
            this.rdCrustThin.CheckedChanged += new System.EventHandler(this.rdCrustThin_CheckedChanged);
            // 
            // grWhereToEatBox
            // 
            this.grWhereToEatBox.Controls.Add(this.rdTakeOut);
            this.grWhereToEatBox.Controls.Add(this.rdEatin);
            this.grWhereToEatBox.ForeColor = System.Drawing.SystemColors.ControlText;
            this.grWhereToEatBox.Location = new System.Drawing.Point(250, 271);
            this.grWhereToEatBox.Name = "grWhereToEatBox";
            this.grWhereToEatBox.Size = new System.Drawing.Size(265, 56);
            this.grWhereToEatBox.TabIndex = 4;
            this.grWhereToEatBox.TabStop = false;
            this.grWhereToEatBox.Text = "Where To Eat";
            // 
            // rdTakeOut
            // 
            this.rdTakeOut.AutoSize = true;
            this.rdTakeOut.Location = new System.Drawing.Point(128, 28);
            this.rdTakeOut.Name = "rdTakeOut";
            this.rdTakeOut.Size = new System.Drawing.Size(70, 17);
            this.rdTakeOut.TabIndex = 1;
            this.rdTakeOut.TabStop = true;
            this.rdTakeOut.Tag = "5";
            this.rdTakeOut.Text = "Take Out";
            this.rdTakeOut.UseVisualStyleBackColor = true;
            this.rdTakeOut.CheckedChanged += new System.EventHandler(this.rdTakeOut_CheckedChanged);
            // 
            // rdEatin
            // 
            this.rdEatin.AutoCheck = false;
            this.rdEatin.AutoSize = true;
            this.rdEatin.Location = new System.Drawing.Point(34, 28);
            this.rdEatin.Name = "rdEatin";
            this.rdEatin.Size = new System.Drawing.Size(53, 17);
            this.rdEatin.TabIndex = 0;
            this.rdEatin.TabStop = true;
            this.rdEatin.Tag = "5";
            this.rdEatin.Text = "Eat In";
            this.rdEatin.UseVisualStyleBackColor = true;
            this.rdEatin.UseWaitCursor = true;
            this.rdEatin.CheckedChanged += new System.EventHandler(this.rdEatin_CheckedChanged);
            // 
            // fileSystemWatcher1
            // 
            this.fileSystemWatcher1.EnableRaisingEvents = true;
            this.fileSystemWatcher1.SynchronizingObject = this;
            // 
            // Lable
            // 
            this.Lable.AutoSize = true;
            this.Lable.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Lable.Location = new System.Drawing.Point(24, 32);
            this.Lable.Name = "Lable";
            this.Lable.Size = new System.Drawing.Size(39, 13);
            this.Lable.TabIndex = 0;
            this.Lable.Text = "Size: ";
            // 
            // grOrderSummary
            // 
            this.grOrderSummary.Controls.Add(this.CrustType);
            this.grOrderSummary.Controls.Add(this.TotalPrice);
            this.grOrderSummary.Controls.Add(this.TotalPriceLable);
            this.grOrderSummary.Controls.Add(this.WhereToEatCheck);
            this.grOrderSummary.Controls.Add(this.WhateToEateLable);
            this.grOrderSummary.Controls.Add(this.CrustLable);
            this.grOrderSummary.Controls.Add(this.ToopingsCheck);
            this.grOrderSummary.Controls.Add(this.ToppingsLable);
            this.grOrderSummary.Controls.Add(this.OrderCheckSize);
            this.grOrderSummary.Controls.Add(this.Lable);
            this.grOrderSummary.Location = new System.Drawing.Point(558, 94);
            this.grOrderSummary.Name = "grOrderSummary";
            this.grOrderSummary.Size = new System.Drawing.Size(200, 287);
            this.grOrderSummary.TabIndex = 5;
            this.grOrderSummary.TabStop = false;
            this.grOrderSummary.Text = "Order Summary";
            // 
            // TotalPrice
            // 
            this.TotalPrice.AutoSize = true;
            this.TotalPrice.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.TotalPrice.Font = new System.Drawing.Font("Kristen ITC", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TotalPrice.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.TotalPrice.ImageIndex = 10;
            this.TotalPrice.Location = new System.Drawing.Point(112, 239);
            this.TotalPrice.Name = "TotalPrice";
            this.TotalPrice.Size = new System.Drawing.Size(39, 44);
            this.TotalPrice.TabIndex = 10;
            this.TotalPrice.Text = "0";
            this.TotalPrice.Click += new System.EventHandler(this.TotalPrice_Click);
            // 
            // TotalPriceLable
            // 
            this.TotalPriceLable.AutoSize = true;
            this.TotalPriceLable.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TotalPriceLable.Location = new System.Drawing.Point(23, 239);
            this.TotalPriceLable.Name = "TotalPriceLable";
            this.TotalPriceLable.Size = new System.Drawing.Size(73, 13);
            this.TotalPriceLable.TabIndex = 9;
            this.TotalPriceLable.Text = "Total Price:";
            // 
            // WhereToEatCheck
            // 
            this.WhereToEatCheck.AutoSize = true;
            this.WhereToEatCheck.Location = new System.Drawing.Point(128, 209);
            this.WhereToEatCheck.Name = "WhereToEatCheck";
            this.WhereToEatCheck.Size = new System.Drawing.Size(10, 13);
            this.WhereToEatCheck.TabIndex = 8;
            this.WhereToEatCheck.Text = " ";
            // 
            // WhateToEateLable
            // 
            this.WhateToEateLable.AutoSize = true;
            this.WhateToEateLable.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.WhateToEateLable.Location = new System.Drawing.Point(23, 209);
            this.WhateToEateLable.Name = "WhateToEateLable";
            this.WhateToEateLable.Size = new System.Drawing.Size(90, 13);
            this.WhateToEateLable.TabIndex = 7;
            this.WhateToEateLable.Text = "Where To Eat:";
            // 
            // CrustLable
            // 
            this.CrustLable.AutoSize = true;
            this.CrustLable.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.CrustLable.Location = new System.Drawing.Point(24, 177);
            this.CrustLable.Name = "CrustLable";
            this.CrustLable.Size = new System.Drawing.Size(72, 13);
            this.CrustLable.TabIndex = 4;
            this.CrustLable.Text = "Crust Type:";
            // 
            // ToopingsCheck
            // 
            this.ToopingsCheck.AutoSize = true;
            this.ToopingsCheck.Location = new System.Drawing.Point(28, 77);
            this.ToopingsCheck.Name = "ToopingsCheck";
            this.ToopingsCheck.Size = new System.Drawing.Size(13, 13);
            this.ToopingsCheck.TabIndex = 3;
            this.ToopingsCheck.Text = "  ";
            // 
            // ToppingsLable
            // 
            this.ToppingsLable.AutoSize = true;
            this.ToppingsLable.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ToppingsLable.Location = new System.Drawing.Point(24, 60);
            this.ToppingsLable.Name = "ToppingsLable";
            this.ToppingsLable.Size = new System.Drawing.Size(63, 13);
            this.ToppingsLable.TabIndex = 2;
            this.ToppingsLable.Text = "Toppings:";
            // 
            // OrderCheckSize
            // 
            this.OrderCheckSize.AutoSize = true;
            this.OrderCheckSize.Location = new System.Drawing.Point(77, 32);
            this.OrderCheckSize.Name = "OrderCheckSize";
            this.OrderCheckSize.Size = new System.Drawing.Size(10, 13);
            this.OrderCheckSize.TabIndex = 1;
            this.OrderCheckSize.Text = " ";
            // 
            // btnOrderPizza
            // 
            this.btnOrderPizza.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.btnOrderPizza.Location = new System.Drawing.Point(250, 358);
            this.btnOrderPizza.Name = "btnOrderPizza";
            this.btnOrderPizza.Size = new System.Drawing.Size(103, 33);
            this.btnOrderPizza.TabIndex = 15;
            this.btnOrderPizza.Text = "Order Pizza";
            this.btnOrderPizza.UseVisualStyleBackColor = false;
            this.btnOrderPizza.Click += new System.EventHandler(this.btnOrderPizza_Click);
            // 
            // btnResetFrom
            // 
            this.btnResetFrom.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.btnResetFrom.Location = new System.Drawing.Point(420, 358);
            this.btnResetFrom.Name = "btnResetFrom";
            this.btnResetFrom.Size = new System.Drawing.Size(95, 33);
            this.btnResetFrom.TabIndex = 16;
            this.btnResetFrom.Text = "Reset Form";
            this.btnResetFrom.UseVisualStyleBackColor = false;
            this.btnResetFrom.Click += new System.EventHandler(this.btnResetFrom_Click);
            // 
            // CrustType
            // 
            this.CrustType.AutoSize = true;
            this.CrustType.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.CrustType.Location = new System.Drawing.Point(102, 177);
            this.CrustType.Name = "CrustType";
            this.CrustType.Size = new System.Drawing.Size(10, 13);
            this.CrustType.TabIndex = 11;
            this.CrustType.Text = " ";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.btnResetFrom);
            this.Controls.Add(this.btnOrderPizza);
            this.Controls.Add(this.grOrderSummary);
            this.Controls.Add(this.grWhereToEatBox);
            this.Controls.Add(this.grCrustTypebox);
            this.Controls.Add(this.grToppingsBox);
            this.Controls.Add(this.grSizeBox);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Pizza Order";
            this.grSizeBox.ResumeLayout(false);
            this.grSizeBox.PerformLayout();
            this.grToppingsBox.ResumeLayout(false);
            this.grToppingsBox.PerformLayout();
            this.grCrustTypebox.ResumeLayout(false);
            this.grCrustTypebox.PerformLayout();
            this.grWhereToEatBox.ResumeLayout(false);
            this.grWhereToEatBox.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.fileSystemWatcher1)).EndInit();
            this.grOrderSummary.ResumeLayout(false);
            this.grOrderSummary.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox grSizeBox;
        private System.Windows.Forms.RadioButton rdSizeLarg;
        private System.Windows.Forms.RadioButton rdSizeMedium;
        private System.Windows.Forms.RadioButton rdSizeSmall;
        private System.Windows.Forms.GroupBox grToppingsBox;
        private System.Windows.Forms.CheckBox chToppingsTomatoes;
        private System.Windows.Forms.CheckBox chToppingsMushrooms;
        private System.Windows.Forms.CheckBox chToppingsExtraChees;
        private System.Windows.Forms.CheckBox chToppingsGreenPapers;
        private System.Windows.Forms.CheckBox chToppingsOlives;
        private System.Windows.Forms.CheckBox chToppingsOnion;
        private System.Windows.Forms.GroupBox grCrustTypebox;
        private System.Windows.Forms.RadioButton rdCrustThink;
        private System.Windows.Forms.RadioButton rdCrustThin;
        private System.Windows.Forms.GroupBox grWhereToEatBox;
        private System.Windows.Forms.RadioButton rdTakeOut;
        private System.Windows.Forms.RadioButton rdEatin;
        private System.IO.FileSystemWatcher fileSystemWatcher1;
        private System.Windows.Forms.GroupBox grOrderSummary;
        private System.Windows.Forms.Label ToppingsLable;
        private System.Windows.Forms.Label OrderCheckSize;
        private System.Windows.Forms.Label Lable;
        private System.Windows.Forms.Label CrustLable;
        private System.Windows.Forms.Label ToopingsCheck;
        private System.Windows.Forms.Label TotalPrice;
        private System.Windows.Forms.Label TotalPriceLable;
        private System.Windows.Forms.Label WhereToEatCheck;
        private System.Windows.Forms.Label WhateToEateLable;
        private System.Windows.Forms.Button btnOrderPizza;
        private System.Windows.Forms.Button btnResetFrom;
        private System.Windows.Forms.Label CrustType;
    }
}

