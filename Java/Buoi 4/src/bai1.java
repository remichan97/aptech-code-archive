import java.util.Arrays;
import java.util.Scanner;

public class bai1 {

	public static float[] input(Scanner input, float[] num) {
		System.out.println("Nhập số thứ nhất:");
		num[0] = input.nextFloat();
		System.out.println("Nhập số thứ hai:");
		num[1] = input.nextFloat();
		return num;
	}

	public static float sum(float[] num) {
		return num[0] + num[1];
	}

	public static float sub(float[] num) {
		return num[0] - num[1];
	}

	public static float multiple(float[] num) {
		return num[0] * num[1];
	}

	public static float divide(float[] num) {
		return num[0] / num[1];
	}

	public static boolean checkInteger(float[] num) {
		if ((num[0] == (int) num[0]) && (num[1] == (int) num[1])) {
			return true;
		} else {
			return false;
		}
	}

	public static int timUCLN(float a, float b) {
		if (b == 0) {
			return (int) a;
		}
		return timUCLN(b, a % b);
	}

	public static int timBCNN(float a, float b) {
		return (int) ((a * b) / timUCLN(a, b));
	}

	public static void menu() {
		System.out.println("Mời bạn chọn một trong các chức năng sau:");
		System.out.println("1. Nhập dữ liệu");
		System.out.println("2. Tính tổng");
		System.out.println("3. Tính hiệu");
		System.out.println("4. Tính tích");
		System.out.println("5. Tính thương");
		System.out.println("6. Tìm ước số chung lớn nhất");
		System.out.println("7. Tìm bội số chung nhỏ nhất");
		System.out.println("8. Kết thúc chương trình");
	}

	public static void main(String[] args) {
		float a = 0, b = 0, sum, sub, multiple, divide;
		float[] num = { a, b };
		int opt = 0, ucln, bcnn;
		Scanner input = new Scanner(System.in);
		while (true) {
			do {
				menu();
				System.out.println("Mời nhập lựa chọn của bạn");
				opt = input.nextInt();
			} while (opt < 1 || opt > 8);
			switch (opt) {
			case 1:
				num = input(input, num);
				System.out.println("Hai số vừa nhập là: " + Arrays.toString(num));
				break;
			case 2:
				sum = sum(num);
				System.out.println("Tổng hai số là: " + sum);
				break;
			case 3:
				sub = sub(num);
				System.out.println("Tổng hai số là: " + sub);
				break;
			case 4:
				multiple = multiple(num);
				System.out.println("Tổng hai số là: " + multiple);
				break;
			case 5:
				divide = divide(num);
				System.out.println("Tổng hai số là: " + divide);
				break;
			case 6:
				if (checkInteger(num) && num[0] > 0 && num[1] > 0) {
					ucln = timUCLN(num[0], num[1]);
					System.out.println("Ước số chung của " + num[0] + " và " + num[1] + " là: " + ucln);
				} else {
					System.out.println("Không thể thực hiện với dữ liệu hiện tại");
				}
				break;
			case 7:
				if (checkInteger(num) && num[0] > 0 && num[1] > 0) {
					bcnn = timBCNN(num[0], num[1]);
					System.out.println("Bội số chung nhỏ nhất của " + num[0] + " và " + num[1] + " là: " + bcnn);
				} else {
					System.out.println("Không thể thực hiện với dữ liệu hiện tại");
				}
				break;
			default:
				System.exit(0);
				break;
			}
		}
	}
}