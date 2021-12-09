import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class bai2 {
	public static Float[] inputArr(int n, Scanner input) {
		Float arr[] = new Float[n];
		for (int i = 0; i < arr.length; i++) {
			System.out.format("Nhập phần tử thứ %d: ", i + 1);
			arr[i] = input.nextFloat();
		}
		return arr;
	}

	public static int inputN(Scanner input) {
		int n;
		do {
			System.out.println("Nhập n trong khoảng 0<n<50:");
			n = input.nextInt();
		} while (0 <= n && n >= 50);
		return n;
	}

	public static float max(Float arr[]) {
		float max;
		Float[] asc = new Float[arr.length];
		asc = asc(arr, arr.length);
		max = asc[asc.length - 1];
		return max;
	}

	public static float min(Float arr[]) {
		float min;
		Float[] desc = new Float[arr.length];
		desc = desc(arr, arr.length);
		min = desc[0];
		return min;
	}

	public static void duongChan(Float arr[]) {
		float duongChan;
		duongChan = arr[0];
		for (int i = 0; i < arr.length; i++) {
			if (arr[i] % 2 == 0 && arr[i] > 0 && duongChan < arr[i]) {
				duongChan = arr[i];
			} else {
				System.out.println("Không có số nào thỏa mãn");
				break;
			}
		}
		System.out.println("Số dương chẵn lớn nhất trong mảng là:" + duongChan);
	}

	public static void leAm(Float arr[]) {
		float leAm;
		leAm = arr[0];
		for (int i = 0; i < arr.length; i++) {
			if (arr[i] % 2 != 0 && arr[i] < 0 && leAm > arr[i]) {
				leAm = arr[i];
			} else {
				System.out.println("Không có số nào thỏa mãn");
				break;
			}
		}
		System.out.println("Số lẻ âm nhỏ nhất trong mảng là: " + leAm);
	}

	public static void chinhPhuong(Float arr[]) {
		boolean found = false;
		System.out.println("Các số chính phương trong mảng là:");
		for (int i = 0; i < arr.length; i++) {
			if (arr[i] > 0 && (Math.sqrt(arr[i]) == (int) Math.sqrt(arr[i]))) {
				System.out.println("\n " + arr[i]);
				found = true;
			}
		}
		if (!found) {
			System.out.println("Không có số chính phương trong mảng");
		}
	}

	public static float sum(Float arr[]) {
		float tong = 0;
		for (int i = 0; i < arr.length; i++) {
			tong += arr[i];
		}
		return tong;
	}

	public static float avg(Float arr[], float tong) {
		float avg;
		avg = (tong / arr.length);
		return avg;
	}

	public static void lonHonAvg(Float arr[], float avg) {
		System.out.println("Các số lớn hơn trung bình cộng là:");
		for (int i = 0; i < arr.length; i++) {
			if (avg < arr[i]) {
				System.out.println("\n" + arr[i]);
			}
		}

	}

	public static Float[] asc(Float arr[], int n) {
		Float[] asc = new Float[n];
		Arrays.sort(arr);
		asc = arr;
		return asc;
	}

	public static Float[] desc(Float arr[], int n) {
		Float[] desc = new Float[n];
		Arrays.sort(arr, Collections.reverseOrder());
		desc = arr;
		return desc;
	}

	public static void menu() {
		System.out.println("Mời bạn chọn các lựa chọn sau đây:");
		System.out.println("1. Nhập giới hạn mảng trong khoảng 0<n<50");
		System.out.println("2. Nhập mảng gồm n số thực");
		System.out.println("3. Tìm số lớn nhất");
		System.out.println("4. Tìm số nhỏ nhất");
		System.out.println("5. Tìm số dương chẵn lớn nhất");
		System.out.println("6. Tìm số âm lẻ nhỏ nhất");
		System.out.println("7. Tìm các số chính phương trong mảng");
		System.out.println("8. Tính tổng mảng");
		System.out.println("9. Tính trung bình cộng mảng");
		System.out.println("10. Các phần tử lớn hơn trung bình cộng");
		System.out.println("11. Sắp xếp mảng tăng dần");
		System.out.println("12. Sắp xếp mảng giảm dần");
		System.out.println("13. Thoát chương trình");

	}

	public static void main(String[] args) {
		int opt, n = 0;
		Float[] arr;
		arr = new Float[n];
		Float[] asc;
		asc = new Float[n];
		Float[] desc;
		desc = new Float[n];
		float max, min, sum = 0, avg = 0;
		Scanner input = new Scanner(System.in);
		while (true) {
			do {
				menu();
				System.out.println("Nhập lựa chọn của bạn: ");
				opt = input.nextInt();
			} while (opt < 1 || opt > 13);
			switch (opt) {
			case 1:
				n = inputN(input);
				break;
			case 2:
				arr = inputArr(n, input);
				System.out.println("Mảng đã nhập: " + Arrays.toString(arr));
				break;
			case 3:
				max = max(arr);
				System.out.println("Số lớn nhất trong mảng là: " + max);
				break;
			case 4:
				min = min(arr);
				System.out.println("Số nhỏ nhất trong mảng là: " + min);
				break;
			case 5:
				duongChan(arr);
				break;
			case 6:
				leAm(arr);
				break;
			case 7:
				chinhPhuong(arr);
				break;
			case 8:
				sum = sum(arr);
				System.out.println("Tổng các sô trong mảng: " + sum);
				break;
			case 9:
				avg = avg(arr, sum);
				System.out.println("Tổng các sô trong mảng: " + avg);
				break;
			case 10:
				lonHonAvg(arr, avg);
				break;
			case 11:
				asc = asc(arr, n);
				System.out.println("Mảng đã sắp xếp tăng dần: " + Arrays.toString(asc));
				break;
			case 12:
				desc = desc(arr, n);
				System.out.println("Mảng đã sắp xếp tăng dần: " + Arrays.toString(desc));
				break;
			default:
				System.exit(0);
				break;
			}
		}
	}
}