using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Buoi2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void txtNum0_Click(object sender, EventArgs e)
        {
            txtCalc.Text += "0";
        }

        private void txtNum1_Click(object sender, EventArgs e)
        {
            txtCalc.Text += "1";
        }

        private void txtNum2_Click(object sender, EventArgs e)
        {
            txtCalc.Text += "2";
        }

        private void txtNum3_Click(object sender, EventArgs e)
        {
            txtCalc.Text += "3";
        }

        private void txtNum4_Click(object sender, EventArgs e)
        {
            txtCalc.Text += "4";
        }

        private void txtNum5_Click(object sender, EventArgs e)
        {
            txtCalc.Text += "5";
        }

        private void txtNum6_Click(object sender, EventArgs e)
        {
            txtCalc.Text += "6";
        }

        private void txtNum7_Click(object sender, EventArgs e)
        {
            txtCalc.Text += "7";

        }

        private void txtNum8_Click(object sender, EventArgs e)
        {
            txtCalc.Text += "8";
        }

        private void txtNum9_Click(object sender, EventArgs e)
        {
            txtCalc.Text += "9";
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            txtCalc.Text = String.Empty;
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            txtCalc.Text += "+";
        }

        private void btnSubstract_Click(object sender, EventArgs e)
        {
            txtCalc.Text += "-";
        }

        private void btnMultiple_Click(object sender, EventArgs e)
        {
            txtCalc.Text += "*";
        }

        private void btnDivide_Click(object sender, EventArgs e)
        {
            txtCalc.Text += "/";
        }

        private void btnEqual_Click(object sender, EventArgs e)
        {
            double result = Convert.ToDouble(new DataTable().Compute(txtCalc.Text, null));
            if (Double.IsInfinity(result))
            {
                txtCalc.Text = "Không thể chia cho 0";
            } else
            {
                txtCalc.Text = result.ToString();
            }
        }
    }
}
