#include <stdio.h>

void tinhTong(float a, float b)
{
	printf("\n%g+%g=%g", a, b, a + b);
}

void demo()
{
	printf("\nDay la ham Demo!");
	tinhTong(50, 60);
}
double tinhDelta(float a, float b, float c)
{
	double delta;
	delta = b * b - 4 * a * c;
	return delta;
}

int main()
{
	//Hàm (Function): Dễ dàng trong việc quản lý chương trình (code) bằng cách tách các chức năng (công việc) riêng biệt nhau ra.
	//Định nghĩa (tạo) hàm:
	/*kiểu_trả_về tên_hàm(các_tham_số_nhận_dữ_liệu) {
		code ở đây
		[return giá_trị;] (tùy, có thể có hoặc không)	
	}
	*/
	//kiểu_trả_về: Nếu là void thì không có lệnh return giá_trị;, khác void thì bắt buộc phải có câu lệnh return gía_trị;
	//tên_hàm: do ta tự đặt, thường là 1 động từ hoặc cụm động từ, ví dụ: nhapLieu, hienThi, tinhDelta,... Tên hàm thường đặt theo quy tắc lạc đà.
	//Các tham_số_nhận_dữ_liệu: có thể có hoặc không nhưng đây là nơi duy nhất tiếp nhận dữ liệu để xử lý.
	//return giá_trị: giá_trị phải tương ứng với kiểu_trả_về.
	//kiểu_trả_về: Trả giá_trị về nơi gọi hàm.
	//chú ý: không định nghĩa hàm trong hàm.
	//ví dụ:
	//Lơi gọi hàm (call function): Bản chất là yêu cầu thực hiện chức năng của nó.
	demo();
	double d = tinhDelta(1, 3, 2);
	printf("\nDelta= %g", d);
	return 0;
}