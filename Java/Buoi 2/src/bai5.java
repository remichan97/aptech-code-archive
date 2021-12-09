public class bai5 {
	public static void main(String[] args) {
		int month = 7;
		int year = 2020;
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
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
				System.out.println("Tháng 2 có 29 ngày");
			} else {
				System.out.println("Tháng 2 có 28 ngày");
			}
			break;
		}
	}
}
