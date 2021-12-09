public class bai1 {
	public static void main(String[] args) {
		// Vòng lặp while: còn gọi là vòng lặp không xác định, vì thường thì sẽ không biết trước số lần lặp
		// Cú pháp:
		// while (condition) {
			// lệnh
		// }
		int i =1;
		while (i <= 10) {
			System.out.println(i);
			i++;
		}
		// vòng lặp đo-while
		// do {
			// lệnh
		// } while (condition);
		i = 10;
		do {
			System.out.println(i);
			i--;
		} while (i >= 1);
		System.out.println("\n");
		// vòng lặp for: còng lặp xác định vì ta biết trước đc số lần lặp là bao nhiêu.
		// cú pháp:
		// for (khởi_tạo_biến_đếm; điều_kiện; thay_đổi_biến_đếm) {
			// lệnh	
		// }
		// ví dụ với biến đếm tăng dần:
		for (int j = 1; j <= 10; j++) {
			System.out.println(j);
		}
		// ví dụ với biến đếm giảm dần:
		for (int k = 10; k >= 1; k--) {
			System.out.println(k);
		}
	}
}
