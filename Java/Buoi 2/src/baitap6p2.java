import java.util.Scanner;

public class baitap6p2 {
	public static void main(String[] args) {
		double a, b, c, delta, x1, x2;
		Scanner input = new Scanner(System.in);
		do {
			System.out.println("Nhập hệ số a: ");
			a = input.nextDouble();
		} while (a == 0);
		System.out.println("Nhập hệ số b: ");
		b = input.nextDouble();
		System.out.println("Nhập hệ số c: ");
		c = input.nextDouble();
		delta = Math.pow(b, 2) - 4 * a * c;
		if (delta < 0) {
			System.out.println("Phương trình vô nghiệm");
		} else if (delta == 0) {
			x1 = -(b / (a * 2));
			System.out.println("Phương trình có nghiệm kép x1 = x2 = " + x1);
		} else {
			x1 = ((-b + Math.sqrt(delta)) / (2 * a));
			x2 = ((-b - Math.sqrt(delta)) / (2 * a));
			System.out.println("Phương trình có 2 nghiệm phân biệt:");
			System.out.println("x1 = " + x1);
			System.out.println("x2 = " + x2);
		}
		input.close();
	}
}
