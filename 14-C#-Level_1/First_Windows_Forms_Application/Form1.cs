using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace First_Windows_Forms_Application
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            textBox2.Text = textBox1.Text;
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            textBox2.Text = textBox1.Text;
        }

        private void Mouse_Enter(object sender, EventArgs e)
        {
            textBox2.Text = textBox1.Text;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            textBox1.Enabled = false;
        }


        private void button4_Click(object sender, EventArgs e)
        {
            textBox1.Enabled = true;
        }

        private void button6_Click(object sender, EventArgs e)
        {
            textBox2.Enabled = false;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            textBox2.Enabled = true;
        }

        private void button8_Click(object sender, EventArgs e)
        {
            textBox1.Show();
            textBox2.Show();
            button1.Show();
            button2.Show();
            button3.Show();
            button4.Show();
            button5.Show();
            button6.Show();
            button9.Show();
            button10.Show();
            button11.Show();
           // button12.Show();


        }

        private void button7_Click(object sender, EventArgs e)
        {
            textBox1.Hide();
            textBox2.Hide();
            button1.Hide();
            button2.Hide();
            button3.Hide();
            button4.Hide();
            button5.Hide();
            button6.Hide();

            button9.Hide();
            button10.Hide();
            button10.Hide();
            //button12.Hide();


        }

        private void button9_Click(object sender, EventArgs e)
        {
            textBox1.BackColor = Color.Red;
        }

        private void button10_Click(object sender, EventArgs e)
        {
            textBox1.BackColor = Color.White;
           // this.BackColor = Color.Red;
        }

        private void button11_Click(object sender, EventArgs e)
        {
            this.Text = "Yooo";
        }

        private void button12_Click(object sender, EventArgs e)
        {
            button1.Enabled = !button1.Enabled;
            button2.Enabled = !button2.Enabled;
            button3.Enabled = !button3.Enabled;
            button4.Enabled = !button4.Enabled;
            button5.Enabled = !button5.Enabled;
            button6.Enabled = !button6.Enabled;
            button9.Enabled = !button9.Enabled;
            button10.Enabled = !button10.Enabled;
            button11.Enabled = !button11.Enabled;

        }

        private void button13_Click(object sender, EventArgs e)
        {

        }

        private void btnclolse_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
