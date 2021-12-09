using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Buoi6
{
	class KeThua
	{

	}

	public class HinhHoc {
		public double chieuDai, chieuRong;
		double pi = Math.PI;

		public void chuVi() {

		}

		public void dienTich() {

		}
	}

	public class hinhVuong : HinhHoc {
		public double chuVi(double chieuDai) {
			return chieuDai * 4;
		}

		public double dienTich(double chieuDai) {
			return Math.Pow(chieuDai, 4);
		}
	}

	public class hinhChuNhat : HinhHoc {
		public double chuVi(double chieuDai, double chieuRong) {
			return (chieuDai + chieuRong) * 2;
		}

		public double dienTich(double chieuDai, double chieuRong) {
			return chieuDai * chieuRong;
		}
	}

	public class tamGiac : HinhHoc {
		public double a,b,c;

		public double chuVi(double a, double b, double c) {
			return a + b + c;
		}

		public double dienTich(double a, double b, double c) {
			double p = chuVi(a,b,c) / 2;
			return Math.Sqrt(p*(p-a)*(p-b)*(p-c));
		}
	}
}
