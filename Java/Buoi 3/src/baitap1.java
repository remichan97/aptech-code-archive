import java.util.Scanner;

public class baitap1 {
	public static void main(String[] args) {
		int n;
		Scanner input = new Scanner(System.in);
		do {
			System.out.println("Nhập một số trong khoảng từ 0 đến 100");
			n = input.nextInt();
		} while (n <= 0 || n >= 100);
		input.close();
	}
}
