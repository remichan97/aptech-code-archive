import java.util.Scanner;

public class bai5 {
	public static void main(String[] args) {
		float a, b, c, n;
		Scanner input = new Scanner(System.in);
		System.out.println("Nhập điểm thi lần 1: ");
		a = input.nextFloat();
		System.out.println("Nhập điểm online: ");
		b = input.nextFloat();
		System.out.println("Nhập điểm thi cuối kỳ: ");
		c = input.nextFloat();
		n = (a * 0.25f) + (b * 0.25f) + (c * 0.5f);
		System.out.println("Điểm tổng kết: " + n);
		input.close();
	}
}
