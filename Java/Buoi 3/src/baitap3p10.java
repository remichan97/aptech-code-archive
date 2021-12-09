import java.util.Scanner;

public class baitap3p10 {
	public static void main(String[] args) {
		int n, dem = 0;
		Scanner input = new Scanner(System.in);
		System.out.println("Nhập môt số để kiểm tra: ");
		n = input.nextInt();
		if (n < 2) {
			System.out.println("Số vừa nhập không phải số nguyên tố");
		} else {
			for (int i = 2; i <= Math.sqrt(n); i++) {
				if (n % i == 0) {
					dem++;
				}
			}
			if (dem != 0) {
				System.out.println("Số vừa nhập không phải số nguyên tố");
			} else {
				System.out.println("Số vừa nhập là số nguyên tố");
			}
		}
		input.close();
	}
}
