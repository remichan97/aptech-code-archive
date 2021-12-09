package src.pack1;

import java.util.Scanner;

public class TestMySQLTransaction {
	public static void main(String[] args) {
		//xem dữ liệu
		Scanner input = new Scanner(System.in);
		new MySQLTransaction().showData();
		// thêm dữ liệu
		System.out.println("Mời nhập tên danh mục muốn thêm: ");
		new MySQLTransaction().addData(input.nextLine());
		// Sửa dữ liệu
		System.out.println("Mời nhập tên danh mục muốn sửa: ");
		String name = input.nextLine();
		System.out.println("Mời nhập mã danh mục muốn sửa: ");
		new MySQLTransaction().updateData(name, input.nextInt());
		new MySQLTransaction().showData();
		// Xóa dữ liệu:
		System.out.println("Mời bạn nhập mã danh mục muốn xóa");
		new MySQLTransaction().deleteData(input.nextInt());
		new MySQLTransaction().showData();
	}
}
