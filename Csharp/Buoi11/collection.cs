using System;
using cs = System.Console;
using System.Collections.Generic;
using System.Collections.ObjectModel;

namespace Buoi11
{
	public class DanhSach<T> {
		T[] values;
		int index = 0;

		public DanhSach(int a) {
			values = new T[a];
		}

		public void Nhap(T tl) {
			values[index] = tl;
			index++;
		}

		public void In() {
			for (int i = 0; i <= index; i++)
			{
				cs.WriteLine(values[i]);
			}
		}
	}

	public class collection {
		public List<string> DanhSach {get;set;}
		public void nhapLieu() {
			DanhSach = new List<string>();
			DanhSach.Add("Nguyen Van A");
			DanhSach.Add("Nguyen Van B");
			DanhSach.Add("Nguyen Van C");
		}

		public void inDanhSach() {
			for (int i = 0; i < DanhSach.Count; i++)
			{
				cs.WriteLine(DanhSach[i]);
			}
		}
	}
}