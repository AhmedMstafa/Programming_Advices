using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Pizza_Project
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        float PSize()
        {
            if(rdSmall.Checked)
                return Convert.ToSingle(rdSmall.Tag);

            if(rdMeduim.Checked)
                return Convert.ToSingle(rdMeduim.Tag);

            if(rdLarg.Checked)
                return Convert.ToSingle(rdLarg.Tag);

            return 0;
        }

        float PToppings()
        {
            float Toppings = 0;

            if(chExtraChees.Checked)
                Toppings += Convert.ToSingle(chExtraChees.Tag);

            if (chMushrooms.Checked)
                Toppings += Convert.ToSingle(chMushrooms.Tag);

            if (chTomatoes.Checked)
                Toppings += Convert.ToSingle(chTomatoes.Tag);

            if (chOnion.Checked)
                Toppings += Convert.ToSingle(chOnion.Tag);

            if(chOlives.Checked)
                Toppings += Convert.ToSingle(chOlives.Tag);

            if (chGreenPeppers.Checked)
                Toppings += Convert.ToSingle(chGreenPeppers.Tag);

            return Toppings ;
        }
        float PCrustType()
        {
            if(rdThin.Checked)
                return Convert.ToSingle(rdThin.Tag);   

            if(rdThink.Checked)
                return Convert.ToSingle(rdThink.Tag);

            return 0;
        }

        float PWhereToEat()
        {
            if(rdEatIn.Checked)
                return Convert.ToSingle(rdEatIn.Tag);

            if(rdTakeOut.Checked)
                return Convert.ToSingle(rdTakeOut.Tag);

            return 0;
        }

        float CalcTotalPrice()
        {
            return PSize() + PToppings() + PCrustType() + PWhereToEat();
        }

        void UpdateTotalPrice()
        {
            OTotalPrice.Text = $"${CalcTotalPrice()}";
        }

        void UpdateSize()
        {
            UpdateTotalPrice();

            if (rdSmall.Checked)
            {
                OSize.Text = rdSmall.Text;
                return;
            }

            if(rdMeduim.Checked)
            {
                OSize.Text = rdMeduim.Text;
                return;
            }

            if(rdLarg.Checked)
            {
                OSize.Text =rdLarg.Text;
                return;
            }

            
        }

        void UpdateToppings()
        {
            UpdateTotalPrice();

            string Toppings = "";

            if(chExtraChees.Checked)
                Toppings =  "Extra Chees";

            if (chMushrooms.Checked)
                Toppings +=  ", Onion" ;

            if (chTomatoes.Checked)
                Toppings += ", Tomatoes";

            if (chOnion.Checked)
                Toppings += ", Onion";

            if (chOlives.Checked)
                Toppings += ", Olives";

            if (chGreenPeppers.Checked)
                Toppings += ", Green Peppers";

            if(Toppings.StartsWith(","))
                Toppings = Toppings.Substring(1,Toppings.Length-1).Trim();

            if (Toppings == "")
                Toppings = "No Toppings";

            OToppings.Text = Toppings;
        }

        void UpdateCrustType()
        {
            UpdateTotalPrice();

            if (rdThin.Checked)
            {
                OCrustType.Text = rdThin.Text;
                return;
            }

            if(rdThink.Checked)
            {
                OCrustType.Text = rdThink.Text;
                return;
            }
        }

        void UpdateWhereToEate()
        {
            UpdateTotalPrice();

            if (rdEatIn.Checked)
            {
                OWhareToEat.Text = rdEatIn.Text;
                return;
            }

            if(rdTakeOut.Checked)
            {
                OWhareToEat.Text = rdTakeOut.Text;
                return;
            }
        }

        void DisableAllControls()
        {
            grSize.Enabled = false;

            grCrustType.Enabled = false;

            grToppings.Enabled = false;

            grWhereToEat.Enabled = false;

            btnOrderPizza.Enabled = false;
        }

        void Reset()
        {
            //Reset Groups
            grSize.Enabled = true;
            grCrustType.Enabled = true;
            grToppings.Enabled = true;
            grWhereToEat.Enabled = true;
            btnOrderPizza.Enabled = true;

            //Reset Size
            rdMeduim.Checked = true;

            //Reset Toppings
            chExtraChees.Checked = false;
            chTomatoes.Checked = false;
            chMushrooms.Checked = false;
            chGreenPeppers.Checked = false;
            chOlives.Checked = false;
            chOnion.Checked = false;

            //Reset CrustType
            rdThin.Checked = true;

            //Reset Where to Eat
            rdEatIn.Checked = true;

            //Reset Order Button
            btnOrderPizza.Enabled = true;
        }

        void UpdateOrderSummary()
        {
            UpdateSize();
            UpdateToppings();
            UpdateCrustType();
            UpdateWhereToEate();
            UpdateTotalPrice();
        }
        private void rdSmall_CheckedChanged(object sender, EventArgs e)
        {
            UpdateSize();
        }

        private void rdMeduim_CheckedChanged(object sender, EventArgs e)
        {
            UpdateSize();
        }

        private void rdLarg_CheckedChanged(object sender, EventArgs e)
        {
            UpdateSize();

        }

        private void rdThin_CheckedChanged(object sender, EventArgs e)
        {
            UpdateCrustType();

        }

        private void rdThink_CheckedChanged(object sender, EventArgs e)
        {
            UpdateCrustType();

        }

        private void chExtraChees_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();

        }

        private void chMushrooms_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();

        }

        private void chTomatoes_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();

        }

        private void chOnion_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();

        }

        private void chOlives_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();

        }

        private void chGreenPeppers_CheckedChanged(object sender, EventArgs e)
        {
            UpdateToppings();

        }

        private void rdEatIn_CheckedChanged(object sender, EventArgs e)
        {
            UpdateWhereToEate();

        }

        private void grWhereToEat_Enter(object sender, EventArgs e)
        {
            UpdateWhereToEate();

        }

        private void btnOrderPizza_Click(object sender, EventArgs e)
        {
            if(MessageBox.Show("Conferm Order","Conferm",MessageBoxButtons.OKCancel,MessageBoxIcon.Question,MessageBoxDefaultButton.Button1) == DialogResult.OK)
            {
                MessageBox.Show("Order Placed Successfully", "Success", MessageBoxButtons.OK, MessageBoxIcon.Information);
                DisableAllControls();
            }
        }

        private void btnRestForm_Click(object sender, EventArgs e)
        {
            Reset();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            UpdateOrderSummary();
        }
    }
}
