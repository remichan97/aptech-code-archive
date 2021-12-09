using System;
using cs = System.Console;
using System.Collections;

namespace Buoi11
{
	public class ThuVien
	{
		public string tenSach, maSach, tenSinhVien, maSV, tenSachMuon, sinhVienMuonSach;
		public int soLuong;

		ArrayList Sach;
		ArrayList sinhVien;

		ArrayList muonSach;
		public void nhapLieuSach()
		{
			cs.WriteLine("Nhập tên sách:");
			tenSach = cs.ReadLine();
			cs.WriteLine("Nhập số lượng:");
			soLuong = Convert.ToInt32(cs.ReadLine());
			cs.WriteLine("Nhập mã sách:");
			maSach = cs.ReadLine();
			Sach = new ArrayList() { tenSach, soLuong, maSach };
		}

		public void hienThiSach()
		{
			for (int i = 0; i < Sach.Count - 1; i++)
			{
				cs.WriteLine("Quyển sách thứ " + (i + 1));
				cs.WriteLine("Tên sách: " + tenSach);
				cs.WriteLine("Số lượng ấn bản: " + soLuong);
				cs.WriteLine("Mã sách: " + maSach);
			}
		}

		public void nhapLieuSinhVien()
		{
			cs.WriteLine("Nhập mã sinh viên:");
			maSV = cs.ReadLine();
			cs.WriteLine("Nhập họ tên sinh viên:");
			tenSinhVien = cs.ReadLine();
			sinhVien = new ArrayList() { maSV, tenSinhVien };
		}

		public void hienThiSinhVien()
		{
			for (int i = 0; i < sinhVien.Count - 1; i++)
			{
				cs.WriteLine("Mã sinh viên: " + maSV);
				cs.WriteLine("Tên sinh viên: " + tenSinhVien);
			}
		}

		public void choMuonSach()
		{
			cs.WriteLine("Nhập tên sách cần mượn:");
			tenSachMuon = cs.ReadLine();
			if (Sach.Contains(tenSachMuon))
			{
				do
				{
					cs.WriteLine("Nhập tên sinh viên cần mượn sách:");
					sinhVienMuonSach = cs.ReadLine();
				} while (!(sinhVien.Contains(sinhVienMuonSach)));
			}
			else
			{
				cs.WriteLine("Không tìm thấy sách đã nhập");
			}
		}

		public void danhSachMuonSach()
		{
			for (int i = 0; i < muonSach.Count - 1; i++)
			{
				cs.WriteLine("Tên sinh viên:" +sinhVienMuonSach);
				cs.WriteLine("Tên sách mượn:" +tenSachMuon);
			}
		}
	}
}