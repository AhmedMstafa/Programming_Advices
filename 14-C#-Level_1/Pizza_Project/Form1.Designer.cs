namespace Pizza_Project
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.Title = new System.Windows.Forms.Label();
            this.rdThin = new System.Windows.Forms.RadioButton();
            this.rdThink = new System.Windows.Forms.RadioButton();
            this.grCrustType = new System.Windows.Forms.GroupBox();
            this.rdSmall = new System.Windows.Forms.RadioButton();
            this.rdMeduim = new System.Windows.Forms.RadioButton();
            this.rdLarg = new System.Windows.Forms.RadioButton();
            this.grSize = new System.Windows.Forms.GroupBox();
            this.grToppings = new System.Windows.Forms.GroupBox();
            this.chOlives = new System.Windows.Forms.CheckBox();
            this.chGreenPeppers = new System.Windows.Forms.CheckBox();
            this.chOnion = new System.Windows.Forms.CheckBox();
            this.chMushrooms = new System.Windows.Forms.CheckBox();
            this.chTomatoes = new System.Windows.Forms.CheckBox();
            this.chExtraChees = new System.Windows.Forms.CheckBox();
            this.grWhereToEat = new System.Windows.Forms.GroupBox();
            this.rdTakeOut = new System.Windows.Forms.RadioButton();
            this.rdEatIn = new System.Windows.Forms.RadioButton();
            this.grOrderSummary = new System.Windows.Forms.GroupBox();
            this.OTotalPrice = new System.Windows.Forms.Label();
            this.LbTotalPrice = new System.Windows.Forms.Label();
            this.OWhareToEat = new System.Windows.Forms.Label();
            this.LbWhareToEat = new System.Windows.Forms.Label();
            this.OCrustType = new System.Windows.Forms.Label();
            this.LbCrustType = new System.Windows.Forms.Label();
            this.OSize = new System.Windows.Forms.Label();
            this.LbSize = new System.Windows.Forms.Label();
            this.OToppings = new System.Windows.Forms.TextBox();
            this.LbToppings = new System.Windows.Forms.Label();
            this.btnOrderPizza = new System.Windows.Forms.Button();
            this.btnRestForm = new System.Windows.Forms.Button();
            this.grCrustType.SuspendLayout();
            this.grSize.SuspendLayout();
            this.grToppings.SuspendLayout();
            this.grWhereToEat.SuspendLayout();
            this.grOrderSummary.SuspendLayout();
            this.SuspendLayout();
            // 
            // Title
            // 
            this.Title.AutoSize = true;
            this.Title.Font = new System.Drawing.Font("Showcard Gothic", 26.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Title.ForeColor = System.Drawing.Color.Red;
            this.Title.ImageAlign = System.Drawing.ContentAlignment.BottomLeft;
            this.Title.Location = new System.Drawing.Point(245, 19);
            this.Title.Name = "Title";
            this.Title.Size = new System.Drawing.Size(345, 44);
            this.Title.TabIndex = 0;
            this.Title.Text = "MAKE YOUR PIZZA";
            // 
            // rdThin
            // 
            this.rdThin.AutoSize = true;
            this.rdThin.Location = new System.Drawing.Point(32, 25);
            this.rdThin.Name = "rdThin";
            this.rdThin.Size = new System.Drawing.Size(46, 17);
            this.rdThin.TabIndex = 1;
            this.rdThin.Tag = "0";
            this.rdThin.Text = "Thin";
            this.rdThin.UseVisualStyleBackColor = true;
            this.rdThin.CheckedChanged += new System.EventHandler(this.rdThin_CheckedChanged);
            // 
            // rdThink
            // 
            this.rdThink.AutoSize = true;
            this.rdThink.Location = new System.Drawing.Point(32, 58);
            this.rdThink.Name = "rdThink";
            this.rdThink.Size = new System.Drawing.Size(52, 17);
            this.rdThink.TabIndex = 2;
            this.rdThink.Tag = "5";
            this.rdThink.Text = "Think";
            this.rdThink.UseVisualStyleBackColor = true;
            this.rdThink.CheckedChanged += new System.EventHandler(this.rdThink_CheckedChanged);
            // 
            // grCrustType
            // 
            this.grCrustType.Controls.Add(this.rdThink);
            this.grCrustType.Controls.Add(this.rdThin);
            this.grCrustType.Location = new System.Drawing.Point(43, 260);
            this.grCrustType.Name = "grCrustType";
            this.grCrustType.Size = new System.Drawing.Size(109, 88);
            this.grCrustType.TabIndex = 1;
            this.grCrustType.TabStop = false;
            this.grCrustType.Text = "Crust Type";
            // 
            // rdSmall
            // 
            this.rdSmall.AutoSize = true;
            this.rdSmall.Location = new System.Drawing.Point(32, 25);
            this.rdSmall.Name = "rdSmall";
            this.rdSmall.Size = new System.Drawing.Size(50, 17);
            this.rdSmall.TabIndex = 2;
            this.rdSmall.Tag = "20";
            this.rdSmall.Text = "Small";
            this.rdSmall.UseVisualStyleBackColor = true;
            this.rdSmall.CheckedChanged += new System.EventHandler(this.rdSmall_CheckedChanged);
            // 
            // rdMeduim
            // 
            this.rdMeduim.AutoSize = true;
            this.rdMeduim.Location = new System.Drawing.Point(32, 58);
            this.rdMeduim.Name = "rdMeduim";
            this.rdMeduim.Size = new System.Drawing.Size(62, 17);
            this.rdMeduim.TabIndex = 3;
            this.rdMeduim.Tag = "30";
            this.rdMeduim.Text = "Meduim";
            this.rdMeduim.UseVisualStyleBackColor = true;
            this.rdMeduim.CheckedChanged += new System.EventHandler(this.rdMeduim_CheckedChanged);
            // 
            // rdLarg
            // 
            this.rdLarg.AutoSize = true;
            this.rdLarg.Location = new System.Drawing.Point(32, 91);
            this.rdLarg.Name = "rdLarg";
            this.rdLarg.Size = new System.Drawing.Size(46, 17);
            this.rdLarg.TabIndex = 4;
            this.rdLarg.Tag = "50";
            this.rdLarg.Text = "Larg";
            this.rdLarg.UseVisualStyleBackColor = true;
            this.rdLarg.CheckedChanged += new System.EventHandler(this.rdLarg_CheckedChanged);
            // 
            // grSize
            // 
            this.grSize.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.grSize.Controls.Add(this.rdLarg);
            this.grSize.Controls.Add(this.rdMeduim);
            this.grSize.Controls.Add(this.rdSmall);
            this.grSize.ImeMode = System.Windows.Forms.ImeMode.NoControl;
            this.grSize.Location = new System.Drawing.Point(43, 103);
            this.grSize.Name = "grSize";
            this.grSize.Size = new System.Drawing.Size(133, 121);
            this.grSize.TabIndex = 0;
            this.grSize.TabStop = false;
            this.grSize.Text = "Size";
            // 
            // grToppings
            // 
            this.grToppings.Controls.Add(this.chOlives);
            this.grToppings.Controls.Add(this.chGreenPeppers);
            this.grToppings.Controls.Add(this.chOnion);
            this.grToppings.Controls.Add(this.chMushrooms);
            this.grToppings.Controls.Add(this.chTomatoes);
            this.grToppings.Controls.Add(this.chExtraChees);
            this.grToppings.Location = new System.Drawing.Point(238, 103);
            this.grToppings.Name = "grToppings";
            this.grToppings.Size = new System.Drawing.Size(237, 95);
            this.grToppings.TabIndex = 2;
            this.grToppings.TabStop = false;
            this.grToppings.Text = "Toppings";
            // 
            // chOlives
            // 
            this.chOlives.AutoSize = true;
            this.chOlives.Location = new System.Drawing.Point(133, 43);
            this.chOlives.Name = "chOlives";
            this.chOlives.Size = new System.Drawing.Size(55, 17);
            this.chOlives.TabIndex = 4;
            this.chOlives.Tag = "5";
            this.chOlives.Text = "Olives";
            this.chOlives.UseVisualStyleBackColor = true;
            this.chOlives.CheckedChanged += new System.EventHandler(this.chOlives_CheckedChanged);
            // 
            // chGreenPeppers
            // 
            this.chGreenPeppers.AutoSize = true;
            this.chGreenPeppers.Location = new System.Drawing.Point(133, 66);
            this.chGreenPeppers.Name = "chGreenPeppers";
            this.chGreenPeppers.Size = new System.Drawing.Size(97, 17);
            this.chGreenPeppers.TabIndex = 5;
            this.chGreenPeppers.Tag = "5";
            this.chGreenPeppers.Text = "Green Peppers";
            this.chGreenPeppers.UseVisualStyleBackColor = true;
            this.chGreenPeppers.CheckedChanged += new System.EventHandler(this.chGreenPeppers_CheckedChanged);
            // 
            // chOnion
            // 
            this.chOnion.AutoSize = true;
            this.chOnion.Location = new System.Drawing.Point(133, 20);
            this.chOnion.Name = "chOnion";
            this.chOnion.Size = new System.Drawing.Size(54, 17);
            this.chOnion.TabIndex = 3;
            this.chOnion.Tag = "5";
            this.chOnion.Text = "Onion";
            this.chOnion.UseVisualStyleBackColor = true;
            this.chOnion.CheckedChanged += new System.EventHandler(this.chOnion_CheckedChanged);
            // 
            // chMushrooms
            // 
            this.chMushrooms.AutoSize = true;
            this.chMushrooms.Location = new System.Drawing.Point(16, 43);
            this.chMushrooms.Name = "chMushrooms";
            this.chMushrooms.Size = new System.Drawing.Size(80, 17);
            this.chMushrooms.TabIndex = 1;
            this.chMushrooms.Tag = "5";
            this.chMushrooms.Text = "Mushrooms";
            this.chMushrooms.UseVisualStyleBackColor = true;
            this.chMushrooms.CheckedChanged += new System.EventHandler(this.chMushrooms_CheckedChanged);
            // 
            // chTomatoes
            // 
            this.chTomatoes.AutoSize = true;
            this.chTomatoes.Location = new System.Drawing.Point(16, 66);
            this.chTomatoes.Name = "chTomatoes";
            this.chTomatoes.Size = new System.Drawing.Size(73, 17);
            this.chTomatoes.TabIndex = 2;
            this.chTomatoes.Tag = "5";
            this.chTomatoes.Text = "Tomatoes";
            this.chTomatoes.UseVisualStyleBackColor = true;
            this.chTomatoes.CheckedChanged += new System.EventHandler(this.chTomatoes_CheckedChanged);
            // 
            // chExtraChees
            // 
            this.chExtraChees.AutoSize = true;
            this.chExtraChees.Location = new System.Drawing.Point(16, 20);
            this.chExtraChees.Name = "chExtraChees";
            this.chExtraChees.Size = new System.Drawing.Size(83, 17);
            this.chExtraChees.TabIndex = 0;
            this.chExtraChees.Tag = "5";
            this.chExtraChees.Text = "Extra Chees";
            this.chExtraChees.UseVisualStyleBackColor = true;
            this.chExtraChees.CheckedChanged += new System.EventHandler(this.chExtraChees_CheckedChanged);
            // 
            // grWhereToEat
            // 
            this.grWhereToEat.Controls.Add(this.rdTakeOut);
            this.grWhereToEat.Controls.Add(this.rdEatIn);
            this.grWhereToEat.Location = new System.Drawing.Point(238, 260);
            this.grWhereToEat.Name = "grWhereToEat";
            this.grWhereToEat.Size = new System.Drawing.Size(165, 56);
            this.grWhereToEat.TabIndex = 3;
            this.grWhereToEat.TabStop = false;
            this.grWhereToEat.Text = "Where To Eat";
            this.grWhereToEat.Enter += new System.EventHandler(this.grWhereToEat_Enter);
            // 
            // rdTakeOut
            // 
            this.rdTakeOut.AutoSize = true;
            this.rdTakeOut.Location = new System.Drawing.Point(81, 25);
            this.rdTakeOut.Name = "rdTakeOut";
            this.rdTakeOut.Size = new System.Drawing.Size(70, 17);
            this.rdTakeOut.TabIndex = 1;
            this.rdTakeOut.Tag = "5";
            this.rdTakeOut.Text = "Take Out";
            this.rdTakeOut.UseVisualStyleBackColor = true;
            // 
            // rdEatIn
            // 
            this.rdEatIn.AutoSize = true;
            this.rdEatIn.Location = new System.Drawing.Point(11, 25);
            this.rdEatIn.Name = "rdEatIn";
            this.rdEatIn.Size = new System.Drawing.Size(53, 17);
            this.rdEatIn.TabIndex = 0;
            this.rdEatIn.Tag = "0";
            this.rdEatIn.Text = "Eat In";
            this.rdEatIn.UseVisualStyleBackColor = true;
            this.rdEatIn.CheckedChanged += new System.EventHandler(this.rdEatIn_CheckedChanged);
            // 
            // grOrderSummary
            // 
            this.grOrderSummary.Controls.Add(this.LbTotalPrice);
            this.grOrderSummary.Controls.Add(this.OTotalPrice);
            this.grOrderSummary.Controls.Add(this.OWhareToEat);
            this.grOrderSummary.Controls.Add(this.LbWhareToEat);
            this.grOrderSummary.Controls.Add(this.OCrustType);
            this.grOrderSummary.Controls.Add(this.LbCrustType);
            this.grOrderSummary.Controls.Add(this.OSize);
            this.grOrderSummary.Controls.Add(this.LbSize);
            this.grOrderSummary.Controls.Add(this.OToppings);
            this.grOrderSummary.Controls.Add(this.LbToppings);
            this.grOrderSummary.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.grOrderSummary.Location = new System.Drawing.Point(562, 103);
            this.grOrderSummary.Name = "grOrderSummary";
            this.grOrderSummary.Size = new System.Drawing.Size(226, 335);
            this.grOrderSummary.TabIndex = 4;
            this.grOrderSummary.TabStop = false;
            this.grOrderSummary.Text = "Order Summary";
            // 
            // OTotalPrice
            // 
            this.OTotalPrice.AutoSize = true;
            this.OTotalPrice.Font = new System.Drawing.Font("Ravie", 26.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.OTotalPrice.ForeColor = System.Drawing.Color.MediumSeaGreen;
            this.OTotalPrice.Location = new System.Drawing.Point(105, 256);
            this.OTotalPrice.Name = "OTotalPrice";
            this.OTotalPrice.Size = new System.Drawing.Size(74, 48);
            this.OTotalPrice.TabIndex = 9;
            this.OTotalPrice.Text = "$0";
            // 
            // LbTotalPrice
            // 
            this.LbTotalPrice.AutoSize = true;
            this.LbTotalPrice.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LbTotalPrice.Location = new System.Drawing.Point(33, 256);
            this.LbTotalPrice.Name = "LbTotalPrice";
            this.LbTotalPrice.Size = new System.Drawing.Size(73, 13);
            this.LbTotalPrice.TabIndex = 8;
            this.LbTotalPrice.Text = "TotalPrice: ";
            // 
            // OWhareToEat
            // 
            this.OWhareToEat.AutoSize = true;
            this.OWhareToEat.Location = new System.Drawing.Point(117, 219);
            this.OWhareToEat.Name = "OWhareToEat";
            this.OWhareToEat.Size = new System.Drawing.Size(10, 13);
            this.OWhareToEat.TabIndex = 7;
            this.OWhareToEat.Text = " ";
            // 
            // LbWhareToEat
            // 
            this.LbWhareToEat.AutoSize = true;
            this.LbWhareToEat.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LbWhareToEat.Location = new System.Drawing.Point(33, 199);
            this.LbWhareToEat.Name = "LbWhareToEat";
            this.LbWhareToEat.Size = new System.Drawing.Size(94, 13);
            this.LbWhareToEat.TabIndex = 6;
            this.LbWhareToEat.Text = "Where To Eat: ";
            // 
            // OCrustType
            // 
            this.OCrustType.AutoSize = true;
            this.OCrustType.Location = new System.Drawing.Point(110, 157);
            this.OCrustType.Name = "OCrustType";
            this.OCrustType.Size = new System.Drawing.Size(10, 13);
            this.OCrustType.TabIndex = 5;
            this.OCrustType.Text = " ";
            // 
            // LbCrustType
            // 
            this.LbCrustType.AutoSize = true;
            this.LbCrustType.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LbCrustType.Location = new System.Drawing.Point(27, 157);
            this.LbCrustType.Name = "LbCrustType";
            this.LbCrustType.Size = new System.Drawing.Size(76, 13);
            this.LbCrustType.TabIndex = 4;
            this.LbCrustType.Text = "Crust Type: ";
            // 
            // OSize
            // 
            this.OSize.AutoSize = true;
            this.OSize.Location = new System.Drawing.Point(75, 27);
            this.OSize.Name = "OSize";
            this.OSize.Size = new System.Drawing.Size(10, 13);
            this.OSize.TabIndex = 1;
            this.OSize.Text = " ";
            // 
            // LbSize
            // 
            this.LbSize.AutoSize = true;
            this.LbSize.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LbSize.Location = new System.Drawing.Point(30, 25);
            this.LbSize.Name = "LbSize";
            this.LbSize.Size = new System.Drawing.Size(39, 13);
            this.LbSize.TabIndex = 0;
            this.LbSize.Text = "Size: ";
            // 
            // OToppings
            // 
            this.OToppings.BackColor = System.Drawing.SystemColors.Menu;
            this.OToppings.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.OToppings.Location = new System.Drawing.Point(60, 75);
            this.OToppings.Multiline = true;
            this.OToppings.Name = "OToppings";
            this.OToppings.ReadOnly = true;
            this.OToppings.Size = new System.Drawing.Size(134, 58);
            this.OToppings.TabIndex = 3;
            this.OToppings.Text = " ";
            // 
            // LbToppings
            // 
            this.LbToppings.AutoSize = true;
            this.LbToppings.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LbToppings.Location = new System.Drawing.Point(27, 58);
            this.LbToppings.Name = "LbToppings";
            this.LbToppings.Size = new System.Drawing.Size(63, 13);
            this.LbToppings.TabIndex = 2;
            this.LbToppings.Text = "Toppings:";
            // 
            // btnOrderPizza
            // 
            this.btnOrderPizza.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.btnOrderPizza.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.btnOrderPizza.Location = new System.Drawing.Point(238, 372);
            this.btnOrderPizza.Name = "btnOrderPizza";
            this.btnOrderPizza.Size = new System.Drawing.Size(89, 31);
            this.btnOrderPizza.TabIndex = 5;
            this.btnOrderPizza.Text = "Order Pizza";
            this.btnOrderPizza.UseVisualStyleBackColor = false;
            this.btnOrderPizza.Click += new System.EventHandler(this.btnOrderPizza_Click);
            // 
            // btnRestForm
            // 
            this.btnRestForm.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.btnRestForm.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.btnRestForm.Location = new System.Drawing.Point(386, 372);
            this.btnRestForm.Name = "btnRestForm";
            this.btnRestForm.Size = new System.Drawing.Size(89, 31);
            this.btnRestForm.TabIndex = 6;
            this.btnRestForm.Text = "Reset Form";
            this.btnRestForm.UseVisualStyleBackColor = false;
            this.btnRestForm.Click += new System.EventHandler(this.btnRestForm_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.btnRestForm);
            this.Controls.Add(this.btnOrderPizza);
            this.Controls.Add(this.grOrderSummary);
            this.Controls.Add(this.grWhereToEat);
            this.Controls.Add(this.grToppings);
            this.Controls.Add(this.grCrustType);
            this.Controls.Add(this.grSize);
            this.Controls.Add(this.Title);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.Text = "Pizza Order";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.grCrustType.ResumeLayout(false);
            this.grCrustType.PerformLayout();
            this.grSize.ResumeLayout(false);
            this.grSize.PerformLayout();
            this.grToppings.ResumeLayout(false);
            this.grToppings.PerformLayout();
            this.grWhereToEat.ResumeLayout(false);
            this.grWhereToEat.PerformLayout();
            this.grOrderSummary.ResumeLayout(false);
            this.grOrderSummary.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label Title;
        private System.Windows.Forms.RadioButton rdThin;
        private System.Windows.Forms.RadioButton rdThink;
        private System.Windows.Forms.GroupBox grCrustType;
        private System.Windows.Forms.RadioButton rdSmall;
        private System.Windows.Forms.RadioButton rdMeduim;
        private System.Windows.Forms.RadioButton rdLarg;
        private System.Windows.Forms.GroupBox grSize;
        private System.Windows.Forms.GroupBox grToppings;
        private System.Windows.Forms.CheckBox chOlives;
        private System.Windows.Forms.CheckBox chGreenPeppers;
        private System.Windows.Forms.CheckBox chOnion;
        private System.Windows.Forms.CheckBox chMushrooms;
        private System.Windows.Forms.CheckBox chTomatoes;
        private System.Windows.Forms.CheckBox chExtraChees;
        private System.Windows.Forms.GroupBox grWhereToEat;
        private System.Windows.Forms.RadioButton rdTakeOut;
        private System.Windows.Forms.RadioButton rdEatIn;
        private System.Windows.Forms.GroupBox grOrderSummary;
        private System.Windows.Forms.Label LbToppings;
        private System.Windows.Forms.TextBox OToppings;
        private System.Windows.Forms.Label OWhareToEat;
        private System.Windows.Forms.Label LbWhareToEat;
        private System.Windows.Forms.Label OCrustType;
        private System.Windows.Forms.Label LbCrustType;
        private System.Windows.Forms.Label OSize;
        private System.Windows.Forms.Label LbSize;
        private System.Windows.Forms.Label OTotalPrice;
        private System.Windows.Forms.Label LbTotalPrice;
        private System.Windows.Forms.Button btnOrderPizza;
        private System.Windows.Forms.Button btnRestForm;
    }
}

