import java.util.Scanner;

public class baitap6p4 {
	public static void main(String[] args) {
		float a1, b1, c1, a2, b2, c2, d, d1, d2, x, y;
		Scanner input = new Scanner(System.in);
		System.out.println("Nhập a1: ");
		a1 = input.nextFloat();
		System.out.println("Nhập b1: ");
		b1 = input.nextFloat();
		System.out.println("Nhập c1: ");
		c1 = input.nextFloat();
		System.out.println("Nhập a2: ");
		a2 = input.nextFloat();
		System.out.println("Nhập b2: ");
		b2 = input.nextFloat();
		System.out.println("Nhập c2: ");
		c2 = input.nextFloat();
		d = (a1 * b2) - (a2 * b1);
		d1 = (c1 * b2) - (c2 * b1);
		d2 = (a1 * c2) - (a2 * c1);
		if (d == 0) {
			if (d1 == d2) {
				System.out.println("Phương trình vô số nghiệm");
			} else {
				System.out.println("Phương trình vô nghiệm");
			}
		} else {
			x = d1 / d;
			y = d2 / d;
			System.out.println("Phương trình có nghiệm");
			System.out.println("x = " + x);
			System.out.println("y = " + y);

		}
		input.close();
	}
}
