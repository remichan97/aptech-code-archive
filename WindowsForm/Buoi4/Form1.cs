using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Buoi4
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		private void btnTinhNghiem_Click(object sender, EventArgs e)
		{
			if (String.IsNullOrEmpty(txtHeSo1.Text) || String.IsNullOrEmpty(txtHeSo2.Text) || String.IsNullOrEmpty(txtHeSo3.Text))
			{
				MessageBox.Show("Chưa nhập đủ dữ liệu", "Thiếu dữ liệu", MessageBoxButtons.OK, MessageBoxIcon.Warning);

			}
			else
			{
				double a = Double.Parse(txtHeSo1.Text);
				double b = Double.Parse(txtHeSo2.Text);
				double c = Double.Parse(txtHeSo3.Text);

				double delta = Math.Pow(b, 2) - 4 * a * c;

				if (delta < 0)
				{
					MessageBox.Show("Phương trình vô nghiệm!", "Vô nghiệm", MessageBoxButtons.OK, MessageBoxIcon.Information);
				}
				else if (delta == 0)
				{
					txtNghiemKep.Text = (-b / 2 * a).ToString();
				}
				else
				{
					txtNghiem1.Text = ((-b + Math.Sqrt(delta)) / 2 * a).ToString();
					txtNghiem2.Text = ((-b - Math.Sqrt(delta)) / 2 * a).ToString();
				}
			}
		}

        private void button1_Click(object sender, EventArgs e)
        {
			txtHeSo1.Text = "";
			txtHeSo2.Text = "";
			txtHeSo3.Text = "";
        }
    }
}
