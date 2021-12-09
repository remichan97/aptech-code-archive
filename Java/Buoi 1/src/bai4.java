import java.util.Scanner;

public class bai4 {
	public static void main(String[] args) {
		int a,b,c,n;
		Scanner input = new Scanner(System.in);
		System.out.println("Nhập một số nguyên: ");
		while (true) {
			n = input.nextInt();
			if (n > 0 && n < 1000) {
				break;
			}
			System.out.println("Nhập một số nguyên: ");
		}
		a = n % 10;
		b = n / 10 % 10;
		c = n / 100 % 10;
		System.out.println("Ký số thứ nhất là: " + a);
		System.out.println("Ký số thứ hai là: " + b);
		System.out.println("Ký số thứ ba là: " + c);
		input.close();
	}
}
