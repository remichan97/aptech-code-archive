import java.util.Scanner;

public class baitap5 {
	public static void main(String[] args) {
		int month, year;
		Scanner input = new Scanner(System.in);
		System.out.println("Nhập một tháng bất kỳ: ");
		month = input.nextInt();
		switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			System.out.println("31 ngày");
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			System.out.println("30 ngày");
			break;
		default:
			System.out.println("Bạn đã nhập tháng 2, mời bạn nhập một năm bất kỳ: ");
			year = input.nextInt();
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
				System.out.println("Tháng 2 năm đó có 29 ngày");
			} else {
				System.out.println("Tháng 2 năm đó có 28 ngày");
			}
			break;
		}
		input.close();
	}
}
