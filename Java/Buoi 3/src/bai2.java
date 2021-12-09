import java.util.Scanner;

public class bai2 {
	public static void main(String[] args) {
		// mảng một chiều: là tập hợp các phần tử cùng tên, cùng kiểu dữ liệu nhưng khác
		// nhau chỉ số (index)
		// khai báo:
		// cách 1:
		int[] arr1 = new int[5]; // tạo một mảng tên arr1, kiểu int và có 10 phần tử.
		// arr1[0] => phần tử thứ nhất
		// arr1[1] => phần tử thứ hai
		// tương tự với các phần tử còn lại
		// cách 2:
		float[] arr2;
		int size = 20;
		arr2 = new float[size];
		// nhập liệu cho mảng:
		Scanner input = new Scanner(System.in);
		System.out.println("Mời nhập liệu cho mảng:");
		for (int i = 0; i < arr1.length; i++) {
			System.out.format("Phần tử thứ %d: ", i + 1);
			arr1[i] = input.nextInt();
		}
		// hiển thị dữ liệu mảng:
		System.out.println("Dữ liệu mảng là:");
		for (int i : arr1) {
			System.out.println(i);
		}
		// ví dụ: tìm max:
		int max;
		max = arr1[0];
		for (int k : arr1) {
			if (max < k) {
				max = k;
			}
		}
		System.out.println("max = " + max);
		// tìm số chính phương:
		boolean timthay = false;
		System.out.println("Các số chính phương của mảng:");
		for (int l : arr1) {
			if (l > 0 && Math.sqrt(l) % 1 == 0) {
				System.out.println(l);
				timthay = true;
			}
		}
		if (!timthay) {
			System.out.println("Mảng không có số chính phương");
		}
	}
}
