import java.util.Arrays;
import java.util.Collections;

public class baitap3 {
	public static void asc(Integer [] num) {
		Arrays.sort(num);
		System.out.println("Số nhỏ nhất: " + num[0]);
		System.out.println("Số lớn nhất: " + num[num.length - 1]);
		System.out.println("Dãy số tăng dần: " + Arrays.toString(num));
	}

	public static void desc(Integer [] num) {
		Arrays.sort(num, Collections.reverseOrder());
		System.out.println("Dãy số giảm dần: " + Arrays.toString(num));
	}

	public static void main(String[] args) {
		Integer [] num = { 3, 5, 2, 4 };
		asc(num);
		desc(num);
	}
}
