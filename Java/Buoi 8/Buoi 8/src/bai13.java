import java.util.ArrayList;

class Animal2 {
	int id;
	String name;
	float age;

}

public class bai13 {
	// ArrayList: là kỹ thuật lưu trữ giống như lưu trữ mảng thông thường, nhưng có
	// những điểm mạnh và linh hoạt. Cụ thể là :
	// ArrayList cho phép thay đổi (thêm, bớt) số lượng phần tử ngay trong quá trình
	// thực thi chương trình. Kích thước của ArrayList sẽ tự động
	// thay đổi theo số lượng phần tử mà nó đang chứa.
	// Ngoài ra, ArrayList có nhiều phương thức hỗ trợ trong quá trình thao tác với
	// nó.
	// điểm đặc biệt là ArrayList có thể chứa bất kỳ loại dữ liệu nào.
	// cách khai báo:
	public static void main(String[] args) {
		ArrayList al = new ArrayList<>();
		// thêm phần tử:
		al.add(1);
		al.add(1.5f);
		al.add(20.345);
		al.add("ABCD");
		al.add(true);
		al.forEach((a) -> System.out.println(a));
		// Xóa phần tử:
		al.remove(1);
		System.out.println(al.size());
		// Generic: Kỹ thuật cho phép quản lý dữ liệu mà ArrayList chứa:
		ArrayList<String> al2 = new ArrayList<>();
		Animal2 animal2 = new Animal2();
		animal2.id = 1234;
		animal2.name = "Moon";
		animal2.age = 2;

		ArrayList<Animal2> al3 = new ArrayList<>();
		al3.add(animal2);
		for (Animal2 animal22 : al3) {
			System.out.println(animal22.id);
		}
	}
}
