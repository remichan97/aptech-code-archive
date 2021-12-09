import java.util.Scanner;

public class Person {
	String ten, gioiTinh, ngaySinh, diaChi;

	public Person(String ten, String gioiTinh, String ngaySinh, String diaChi) {
		this.ten = ten;
		this.gioiTinh = gioiTinh;
		this.ngaySinh = ngaySinh;
		this.diaChi = diaChi;
	}

	public Person() {
		
	}

	public void inputInfo(Scanner input) {
		System.out.println("Enter name:");
		ten = input.nextLine();
		System.out.println("Enter gender:");
		gioiTinh = input.nextLine();
		System.out.println("Enter date of birth:");
		ngaySinh = input.nextLine();
		System.out.println("Enter address:");
		diaChi = input.nextLine();
	}

	public void showInfo() {
		System.out.println("Name: " +ten);
		System.out.println("Gender: " +gioiTinh);
		System.out.println("Date of birth: " +ngaySinh);
		System.out.println("Address: " +diaChi);
	}
}
