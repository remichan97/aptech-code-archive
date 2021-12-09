import java.util.Scanner;

public class baitap1 {
	public static boolean checkInterger(float n) {
		if (n == (int) n) {
			return true;
		} else {
			return false;
		}
	}

	public static void main(String[] args) {
		float n;
		int a,b,c;
		boolean i;
		Scanner input = new Scanner(System.in);
		System.out.println("Nhập một số bất kỳ: ");
		n = input.nextFloat();
		i = checkInterger(n);
		if (i == true) {
			System.out.println("Số vừa nhập là số nguyên");
		} else {
			System.out.println("Số vừa nhập là số thực");
		}
		if (n % 2 == 0) {
			System.out.println("Số vừa nhập là số chẵn");
		} else {
			System.out.println("Số vừa nhập là số lẻ");
		}
		if (n % 2 == 0 && n > 0) {
			System.out.println("Số vừa nhập là số chẵn dương");
		} else {
			System.out.println("Số vừa nhập không phải số chẵn dương");
		}
		if (n % 2 != 0 && n < 0) {
			System.out.println("Số vừa nhập là số lẻ âm");
		} else {
			System.out.println("Số vừa nhập không phải số lẻ âm");
		}
		if (n > 0 && (Math.sqrt(n) == (int) Math.sqrt(n))) {
			System.out.println("Số vừa nhập là số chính phương");
		} else {
			System.out.println("Số vừa nhập không phải là số chính phương");
		}
		if (i == true && n > 0 && n < 1000) {
			a = (int) n % 10;
			b = (int) n /10 % 10;
			c = (int) n /100 % 10;
			if (n == (Math.pow(a, 3) + Math.pow(b, 3) + Math.pow(c, 3))) {
				System.out.println("Số vừa nhập là số đặc biệt");				
			} else {
				System.out.println("Số vừa nhập không phải số đặc biệt");
			}
		} else {
			System.out.println("Số vừa nhập không phải số đặc biệt");
		}
		input.close();
	}
}
