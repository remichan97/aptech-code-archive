import java.io.IOException;
import java.util.Scanner;

public class bai2 {
	public static void main(String[] args) throws IOException {
		// cách nhập liệu: dùng đối tượng Scanner để nhập liệu:
		Scanner input = new Scanner(System.in); // tạo một đối tượng có tên là input của lớp Scanner
		int n;
		System.out.println("Mời nhập n: ");
		n = input.nextInt();
		System.out.println("Sau khi nhập, n= " + n);
		char ch;
		System.out.println("Mời nhập một ký tự: ");
		ch = (char) System.in.read();
		System.out.println("Sau khi nhập, ký tự là: " + ch);
		String s;
		System.out.println("Mời nhập một chuỗi: ");
		input.nextLine();
		input.nextLine();
		s = input.nextLine();
		System.out.println("Sau khi nhập, s= " + s);
		input.close();
	}
}
