abstract class Animal1 {
	int id;
	String name;
	float age;

	abstract void move();
	
	void speak() {

	}
}

class Cat1 extends Animal1 {

	@Override
	void move() {
		System.out.println("Move");		
	}

}

public class bai12 {
	// Trừu tượng (Abstract): là kỹ thuật ẩn đi những hành vi (hành động) khó thể hiện, hoặc không thể hiện được, hoặc không cần thiết phải thể hiện, hoặc chưa cần quan tâm đến.
	// Sử dụng từ khóa abstract để không mô tả chi tiết cho hành vi, lúc này sẽ không còn {} mà sẽ kết thúc bằng ;
	// lưu ý: lớp có chứa phương thức trừu tượng cũng phải là lớp trừu tượng => Phải đặt từ khóa abstract trước lớp
	// Lớp thừa kế từ lớp trừu tượng phải thực hiện các hành vi trừu tượng
	public static void main(String[] args) {
		Cat1 cat1 = new Cat1();
		cat1.move();
	}
}
