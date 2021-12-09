import java.util.Scanner;

public class bai7 {
	public static void main(String[] args) {
		double a, b, c, p, s;
		Scanner input = new Scanner(System.in);
		System.out.println("Nhập cạnh thứ nhất của tam giác: ");
		a = input.nextDouble();
		System.out.println("Nhập cạnh thứ hai của tam giác: ");
		b = input.nextDouble();
		System.out.println("Nhập cạnh thứ ba của tam giác: ");
		c = input.nextDouble();
		p = a + b + c;
		s = 0.25 * Math.sqrt((a + b + c) * (a + b - c) * (b + c - a) * (c + a - b));
		System.out.println("Chu vi tam giác: " + p);
		System.out.println("Diện tích tam giác: " + s);
		input.close();
	}
}
