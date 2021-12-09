import java.util.Scanner;

public class baitap7 {
	public static void main(String[] args) {
		float a, b, c;
		Scanner input = new Scanner(System.in);
		System.out.println("Nhập a: ");
		a = input.nextFloat();
		System.out.println("Nhập b: ");
		b = input.nextFloat();
		System.out.println("Nhập c: ");
		c = input.nextFloat();
		if ((a + b) > c && (a + c) > b && (b + c) > a) {
			System.out.println("Ba số đã cho thỏa mãn 3 cạnh của một tam giác");
			if (a == b || b == c || c == a) {
				System.out.println("Ba số đã cho tạo thành một tam giác cân");
			} else {
				System.out.println("Ba số đã cho không tạo thành một tam giác cân");
			}
			if (a == b && b == c && c == a) {
				System.out.println("Ba số đã cho tạo thành một tam giác đều");
			} else {
				System.out.println("Ba số đã cho không tạo thành một tam giác đều");
			}
			if (2 * Math.pow(a, 2) == Math.pow(c, 2)) {
				System.out.println("Ba số đã cho tạo thành một tam giác vuông cân");
			} else {
				System.out.println("Ba số đã cho tạo thành một tam giác vuông cân");
			}
			if ((Math.pow(a, 2) + Math.pow(b, 2) == Math.pow(c, 2))
					|| (Math.pow(b, 2) + Math.pow(c, 2) == Math.pow(a, 2))
					|| (Math.pow(c, 2) + Math.pow(a, 2) == Math.pow(b, 2))) {
				System.out.println("Ba số đã cho tạo thành một tam giác vuông");
			} else {
				System.out.println("Ba số đã cho không tạo thành một tam giác vuông");
			}
		} else {
			System.out.println("Ba số đã cho không thỏa mãn 3 cạnh của một tam giác");
		}
		input.close();
	}
}
