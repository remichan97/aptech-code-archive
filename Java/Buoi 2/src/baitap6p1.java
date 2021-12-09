import java.util.Scanner;

public class baitap6p1 {
	public static void main(String[] args) {
		float a, b, c;
		Scanner input = new Scanner(System.in);
		System.out.println("Phương trình bật nhất có dạng ax+b=0");
		System.out.println("Nhập số a: ");
		a = input.nextFloat();
		System.out.println("Nhập số b: ");
		b = input.nextFloat();
		if (a == 0 && b == 0) {
			System.out.println("Phương trình vô số nghiệm");
		} else if (a == 0 && b != 0) {
			System.out.println("Phương trình vô nghiệm");
		} else {
			c = -b / a;
			System.out.println("Phương trình có nghiệm x = " + c);
		}
		input.close();
	}
}
