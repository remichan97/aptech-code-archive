using System;
using System.Collections;
using System.Collections.Generic;

namespace Buoi7
{
	public interface IBook
	{
		void nhapLieu();
		void thongTin();
		void muonSach();
	}

	public class Book
	{
		public string name, author, publisher, category, borrow, borrowerName;
		public int year, quantity;
	}

	public class BookList : Book, IBook
	{
		Book book;
		List<Book> sach = new List<Book>();
		public void muonSach()
		{
			Console.WriteLine("Nhập tên sách muốn mượn:");
			borrow = Console.ReadLine();
			Console.WriteLine("Nhập tên người mượn:");
			borrowerName = Console.ReadLine();
			foreach (Book item in sach)
			{
				if (sach.Equals(borrow))
				{
					Console.WriteLine("Đã ghi nhận thành công");
					Console.WriteLine("Quyển sách {0} đã được mượn bởi {1}" ,borrow, borrowerName);
					quantity = quantity - 1;
					Console.WriteLine("Số bản in còn lại của ấn phẩm: " +quantity);
				}
				else
				{
					Console.WriteLine("Không có sách nào có tên đã nhập!");
				}
			}
		}

		public void nhapLieu()
		{
			book = new Book();
			Console.WriteLine("Nhập tên sách:");
			book.name = Console.ReadLine();
			Console.WriteLine("Nhập tên tác giả:");
			book.author = Console.ReadLine();
			Console.WriteLine("Nhập tên nhà xuất bản:");
			book.publisher = Console.ReadLine();
			Console.WriteLine("Nhập năm xuất bản sách:");
			book.year = Convert.ToInt32(Console.ReadLine());
			Console.WriteLine("Nhập danh mục sách:");
			book.category = Console.ReadLine();
			book.quantity = 100;
			sach.Add(book);
			thongTin();
		}

		public void thongTin()
		{
			Console.WriteLine("Tên tác phẩm: " +name);
			Console.WriteLine("Tên tác giả: " +author);
			Console.WriteLine("Nhà xuất bản: " +publisher);
			Console.WriteLine("Năm xuất bản: " +year);
			Console.WriteLine("Thuộc danh mục: " +category);
		}

	}
}
