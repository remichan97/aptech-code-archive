import java.util.Scanner;

public class baitap6p3 {
	public static void main(String[] args) {
		double a, b, c, delta, t1, t2, x1, x2, x3, x4;
		Scanner input = new Scanner(System.in);
		do {
			System.out.println("Nhập a: ");
			a = input.nextDouble();
		} while (a == 0);
		System.out.println("Nhập b: ");
		b = input.nextDouble();
		System.out.println("Nhập c: ");
		c = input.nextDouble();
		delta = Math.pow(b, 2) - 4 * a * c;
		if (delta < 0) {
			System.out.println("Phương trình vô nghiệm");
		} else if (delta == 0) {
			t1 = -b / (2 * a);
			t2 = -b / (2 * a);
			x1 = Math.sqrt(t1);
			x2 = -Math.sqrt(t1);
			x3 = Math.sqrt(t2);
			x4 = -Math.sqrt(t2);
			System.out.println("Phương trình có nghiệm:");
			System.out.println("x1 = " + x1);
			System.out.println("x2 = " + x2);
			System.out.println("x3 = " + x3);
			System.out.println("x4 = " + x4);
		} else {
			t1 = (-b + Math.sqrt(delta)) / (2 * a);
			t2 = (-b - Math.sqrt(delta)) / (2 * a);
			x1 = Math.sqrt(t1);
			x2 = -Math.sqrt(t1);
			x3 = Math.sqrt(t2);
			x4 = -Math.sqrt(t2);
			System.out.println("Phương trình có nghiệm:");
			System.out.println("x1 = " + x1);
			System.out.println("x2 = " + x2);
			System.out.println("x3 = " + x3);
			System.out.println("x4 = " + x4);
		}
		input.close();
	}
}
