import java.util.Scanner;

public class baitap3p9 {
	public static void main(String[] args) {
		int n, giaithua = 1;
		Scanner input = new Scanner(System.in);
		System.out.println("Nhập một số để tính giai thừa: ");
		n = input.nextInt();
		for (int i = 1; i <= n; i++) {
			giaithua = giaithua * i;
		}
		System.out.println("Giai thừa = " + giaithua);
		input.close();
	}
}
