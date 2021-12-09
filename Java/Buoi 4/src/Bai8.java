public class Bai8 {
	public static void main(String[] args) {
		// Hàm (Function): Dùng để thực thi một công việc nhất định.
		// Trong Java, hàm phải được tạo (định nghĩa) ở trong lớp.
		// Tạo hàm (định nghĩa hàm):
		// kiểu_trả_về tên_hàm([danh_sách_tham_số]){
		// thân_hàm
		// [return giá_trị;]
		// }
		// Trong đó:
		// kiểu_trả_về: là kiểu bất kỳ theo mong muốn của người lập trình. Nếu
		// kiểu_trả_về là void
		// thì không có lệnh return giá_trị; hoặc return; ; nếu kiểu_trả_về khác void
		// thì bắt buộc
		// phải có lệnh return giá_trị;
		// tên_hàm: do lập trình viên tự đặt, thường đặt tên theo dạng lạc đà, ví dụ:
		// nhapLieu,
		// tinhTong, tinhBietThucDelta, ...
		// danh_sách_tham_số: có thể có hoặc không có, nếu cần nhận dữ liệu để xử lý thì
		// cần
		// phải có danh_sách_tham_số, ngược lại thì không cần.
		// return giá_trị; : chỉ trả về được một giá trị cụ thể, trong đó giá_trị phải
		// có kiểu
		// tương ứng với kiểu_trả_về. giá_trị sẽ được trả về nơi hàm được gọi.
		// Lưu ý: Trong Java ta không được phép tạo hàm trong hàm khác.
		// Gọi hàm trong Java: Có thể gọi hàm trực tiếp từ hàm main nếu hàm đó được tạo
		// với từ
		// khóa static. Về cơ bản, ta cần tạo 1 đối tượng của lớp chứa hàm được tạo, sau
		// đó gọi
		// hàm thông qua đối tượng đó.
		// Tên_Lớp tên_đối_tượng = new Tên_Lớp();
		// tên_đối_tượng.tên_hàm([danh_sách_đối_số]);
		// Trong đó: danh_sách_đối_số phải có số lượng đối số bằng với số lượng tham số
		// trong
		// danh_sách_tham_số. Nếu không có danh_sách_tham_số thì cũng không có
		// danh_sách_đối_số.
		// Lưu ý: Hàm sẽ không thể tự thực thi sau khi được tạo => Cần gọi hàm.
		// Hàm có thể được gọi ở nhiều nơi trong chương trình: gọi trực tiếp bằng lệnh
		// gọi hàm,
		// hoặc gọi từ trong hàm println(), hoặc gọi ở bên trong phần đối số của hàm
		// khác, ...
		Bai8 bai8 = new Bai8();
		bai8.demo();
		bai8.tinhTong(10, 20);
		System.out.println(bai8.tinhBietThucDelta(1, 3, 2));
		bai8.tinhTong(100, (float) bai8.tinhBietThucDelta(10, 30, 20));
	}

	void demo() {
		System.out.println("Hello demo()!");
	}

	void tinhTong(float a, float b) {
		System.out.println(a + " + " + b + " = " + (a + b));
	}

	double tinhBietThucDelta(float a, float b, float c) {
		return b * b - 4 * a * c;
	}
}