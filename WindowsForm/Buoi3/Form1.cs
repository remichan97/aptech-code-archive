using System.Collections;
using System.IO;
using System.Globalization;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Buoi3
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		private ToolTip toolTip1;
		private void btnSave_Click(object sender, EventArgs e)
		{
			if (String.IsNullOrEmpty(txtHoTen.Text))
			{
				toolTip1 = new ToolTip();
				txtHoTen.Focus();
				toolTip1.IsBalloon = true;
				toolTip1.Show(String.Empty, txtHoTen);
				toolTip1.Show("Thông tin bắt buộc", txtHoTen);
			}
			else if (String.IsNullOrEmpty(txtDiaChi.Text))
			{
				txtDiaChi.Focus();
				toolTip1.IsBalloon = true;
				toolTip1.Show(String.Empty, txtDiaChi);
				toolTip1.Show("Thông tin bắt buộc", txtDiaChi);
			}
			else
			{
				toolTip1.RemoveAll();
				SaveFileDialog saveFileDialog1 = new SaveFileDialog();

				saveFileDialog1.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
				saveFileDialog1.FilterIndex = 2;
				saveFileDialog1.RestoreDirectory = true;

				if (saveFileDialog1.ShowDialog() == DialogResult.OK)
				{
					string path = saveFileDialog1.FileName;
					string[] data = {"Họ tên: " +txtHoTen.Text, "Địa chỉ: " +txtDiaChi.Text, "Điện thoại: " +txtSoDienThoai.Text, "Giới tính: " +cmbGioiTinh.Text};
					File.WriteAllLines(path, data);
				}
			}
		}

		private void btnOpen_Click(object sender, EventArgs e)
		{
			OpenFileDialog openFileDialog1 = new OpenFileDialog();
			openFileDialog1.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
			if (openFileDialog1.ShowDialog() == DialogResult.OK)
			{
				ArrayList display = new ArrayList();
				string[] src = File.ReadAllLines(openFileDialog1.FileName);
				foreach (string item in src)
				{
					display.Add(item.Split(new [] {"Họ tên:", "Địa chỉ:", "Điện thoại:", "Giới tính:"}, StringSplitOptions.RemoveEmptyEntries));
				}
				txtHoTen.Text = display[0].ToString();
				txtDiaChi.Text = display[1].ToString();
				txtSoDienThoai.Text = display[2].ToString();
				cmbGioiTinh.Text = display[3].ToString();
			}

		}

		private void txtHoTen_Leave(object sender, EventArgs e)
		{
			toolTip1.Hide(txtHoTen);
		}
	}
}
