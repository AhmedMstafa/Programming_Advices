using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Pizza_Project_Requirments
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private short OrginalPalance = 0;

        private short Toppings = 0;

        private string[] ToppigsList = { "", "", "", "", "","" };

        private void rdSizeSmall_CheckedChanged(object sender, EventArgs e)
        {
            OrginalPalance = Convert.ToInt16(rdSizeSmall.Tag);
            TotalPrice.Text = Convert.ToString(OrginalPalance + Toppings);
            OrderCheckSize.Text = "Small";
        }

        private void rdSizeMedium_CheckedChanged(object sender, EventArgs e)
        {
            OrginalPalance = Convert.ToInt16(rdSizeMedium.Tag);
            TotalPrice.Text = Convert.ToString(OrginalPalance + Toppings);
            OrderCheckSize.Text = "Medium";


        }

        private void rdSizeLarg_CheckedChanged(object sender, EventArgs e)
        {
            OrginalPalance = Convert.ToInt16(rdSizeLarg.Tag);
            TotalPrice.Text = Convert.ToString(OrginalPalance + Toppings);
            OrderCheckSize.Text = "Larg";

        }

        private void chToppingsExtraChees_CheckedChanged(object sender, EventArgs e)
        {
            if (chToppingsExtraChees.Checked)
            {
                ToppigsList[0] = "ExtraChees\n";
                Toppings += Convert.ToInt16(chToppingsExtraChees.Tag);
            }
            else
            {
                ToppigsList[0] = "";
                Toppings -= Convert.ToInt16(chToppingsExtraChees.Tag);
            }           
            TotalPrice.Text = Convert.ToString(OrginalPalance + Toppings);

            ToopingsCheck.Text = "";


            foreach (string Toppin in ToppigsList)
            {
                if (Toppin != "")
                {
                    ToopingsCheck.Text += Toppin;
                }
            }

        }

        private void chToppingsMushrooms_CheckedChanged(object sender, EventArgs e)
        {
            if (chToppingsMushrooms.Checked)
            {
                ToppigsList[1] = "Toppings Mushrooms\n";

                Toppings += Convert.ToInt16(chToppingsMushrooms.Tag);
            }
            else
            {
                ToppigsList[1] = "";

                Toppings -= Convert.ToInt16(chToppingsMushrooms.Tag);
            }

            TotalPrice.Text = Convert.ToString(OrginalPalance + Toppings);

            ToopingsCheck.Text = "";

            foreach (string Toppin in ToppigsList)
            {
                if (Toppin != "")
                {
                    ToopingsCheck.Text += Toppin;
                }
            }
        }

        private void chToppingsTomatoes_CheckedChanged(object sender, EventArgs e)
        {
            if (chToppingsTomatoes.Checked)
            {
                ToppigsList[2] = "Tomatoes\n";

                Toppings += Convert.ToInt16(chToppingsTomatoes.Tag);
            }
            else
            {
                ToppigsList[2] = "";

                Toppings -= Convert.ToInt16(chToppingsTomatoes.Tag);
            }
            TotalPrice.Text = Convert.ToString(OrginalPalance + Toppings);

            ToopingsCheck.Text = "";

            foreach (string Toppin in ToppigsList)
            {
                if (Toppin != "")
                {
                    ToopingsCheck.Text += Toppin;
                }
            }
        }

        private void chToppingsOnion_CheckedChanged(object sender, EventArgs e)
        {
            if (chToppingsOnion.Checked)
            {
                ToppigsList[3] = "Onion\n";

                Toppings += Convert.ToInt16(chToppingsOnion.Tag);
            }
            else
            {
                ToppigsList[3] = "";

                Toppings -= Convert.ToInt16(chToppingsOnion.Tag);
            }
            TotalPrice.Text = Convert.ToString(OrginalPalance + Toppings);

            ToopingsCheck.Text = "";

            foreach (string Toppin in ToppigsList)
            {
                if (Toppin != "")
                {
                    ToopingsCheck.Text += Toppin;
                }
            }
        }

        private void chToppingsOlives_CheckedChanged(object sender, EventArgs e)
        {
            if (chToppingsOlives.Checked)
            {
                ToppigsList[4] = "Olives\n";

                Toppings += Convert.ToInt16(chToppingsOlives.Tag);
            }
            else
            {
                ToppigsList[4] = "";

                Toppings -= Convert.ToInt16(chToppingsOlives.Tag);
            }
            TotalPrice.Text = Convert.ToString(OrginalPalance + Toppings);

            ToopingsCheck.Text = "";

            foreach (string Toppin in ToppigsList)
            {
                if (Toppin != "")
                {
                    ToopingsCheck.Text += Toppin;
                }
            }
        }

        private void chToppingsGreenPapers_CheckedChanged(object sender, EventArgs e)
        {
            if (chToppingsGreenPapers.Checked)
            {
                ToppigsList[5] = "Green Papers\n";

                Toppings += Convert.ToInt16(chToppingsGreenPapers.Tag);
            }
            else
            {
                ToppigsList[5] = "";

                Toppings -= Convert.ToInt16(chToppingsGreenPapers.Tag);
            }
            TotalPrice.Text = Convert.ToString(OrginalPalance + Toppings);

            ToopingsCheck.Text = "";


            foreach (string Toppin in ToppigsList)
            {
                if (Toppin != "")
                {
                    ToopingsCheck.Text += Toppin;
                }
            }
        }

        private void TotalPrice_Click(object sender, EventArgs e)
        {

        }

        private void rdCrustThin_CheckedChanged(object sender, EventArgs e)
        {
            CrustType.Text = "Thin"; 
        }

        private void rdCrustThink_CheckedChanged(object sender, EventArgs e)
        {
            CrustType.Text = "Think";
        }

        private void rdEatin_CheckedChanged(object sender, EventArgs e)
        {
            WhereToEatCheck.Text = "In";
        }

        private void rdTakeOut_CheckedChanged(object sender, EventArgs e)
        {
            WhereToEatCheck.Text = "Out";
        }

        private void btnResetFrom_Click(object sender, EventArgs e)
        {
            rdSizeSmall.Checked = false;
            rdSizeMedium.Checked = false;
            rdSizeLarg.Checked = false;

            chToppingsExtraChees.Checked = false;
            chToppingsGreenPapers.Checked = false;
            chToppingsMushrooms.Checked = false;
            chToppingsOlives.Checked = false;
            chToppingsOnion.Checked = false;
            chToppingsTomatoes.Checked = false;

            rdCrustThin.Checked = false;
            rdCrustThink.Checked = false;

            OrginalPalance = 0;
            TotalPrice.Text = "";
            Toppings = 0;
            ToopingsCheck.Text = "";
            CrustType.Text = "";
            WhereToEatCheck.Text = "";
            WhereToEatCheck.Text = "";

            grSizeBox.Enabled = true;
            grToppingsBox.Enabled = true;
            grCrustTypebox.Enabled = true;
            grWhereToEatBox.Enabled = true;
        }

        private void btnOrderPizza_Click(object sender, EventArgs e)
        {
            DialogResult = MessageBox.Show("Conferm Order", "Conferm", MessageBoxButtons.OKCancel, MessageBoxIcon.Question);

            if(DialogResult == DialogResult.OK)
            {
                grSizeBox.Enabled = false;
                grToppingsBox.Enabled = false;  
                grCrustTypebox.Enabled = false;
                grWhereToEatBox.Enabled = false;
            }
        }
    }
}
