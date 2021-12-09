public class bai4 {
	public static void main(String[] args) {
		// Hằng: để khai báo hằng trong java, ta dùng từ final
		final int n = 10; // n là hằng mang giá trị 10
		// phép toán 3 ngôi
		int age = 10;
		String s = (age >= 18) ? "Người lớn" : "Không phải người lớn";
		System.out.println(s);
		// if-else:
		float dtb = 8.7f;
		if (dtb >= 9) {
			System.out.println("Xuất sắc");
		} else if (dtb >= 8 && dtb < 9) {
			System.out.println("Giỏi");
		} else if (dtb >= 6.5 && dtb < 8) {
			System.out.println("Khá");
		} else if (dtb >= 5 && dtb < 6.5) {
			System.out.println("Trung bình");
		} else {
			System.out.println("Thi lại");
		}
	}
}
