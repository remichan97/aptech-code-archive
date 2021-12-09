import java.util.Scanner;

class Animal {
	int id;
	String name;
	float age;
	
	void move() {
		System.out.println("Swim, Run, Fly,...");
	}
	
	void speak() {
		System.out.println("Gogo, Meowmeow,...");
	}
	
	void inputInfo(Scanner input) {
		System.out.println("Mới nhập id: ");
		id = input.nextInt();
		input.nextLine();
		System.out.println("Mời nhập name: ");
		name = input.nextLine();
		System.out.println("Mời nhập tuổi: ");
		age = input.nextFloat();
	}

	

	public Animal() {
	}

	public Animal(int id, String name, float age) {
		this.id = id;
		this.name = name;
		this.age = age;
	}

	void showInfo() {
		System.out.println("ID: "+id);
		System.out.println("name: "+name);
		System.out.println("age: "+age);
	}
}

class Cat extends Animal {
	String colour;
	// ghi đè (override): lớp con được quyền định nghĩa hành vi (phương thức) giống hệt với hành vi tương ứng của lớp cha.
	// khi đó đối tượng của lớp con sẽ đùng phương thức tương ứng được tạo ở lớp con
	@Override
	void move() {
		System.out.println("Run");
	}
	
	@Override
	void inputInfo(Scanner input) {
		super.inputInfo(input);
		System.out.println("Mời nhập màu: ");
		colour = input.nextLine();
	}

	public Cat() {

	}

	public Cat(int id, String name, float age, String colour) {
		super(id,name,age);
		this.colour = colour;
	}

	@Override
	void showInfo() {
		super.showInfo();
		System.out.println("Colour: " + colour);
	}
}

public class bai1 {

	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(System.in);
		// Thừa kế (Inherit): là một trong nhữn kỹ thuật quan trọng nhất của lập trình
		// hướng đối tượng
		// Thừa kế giúp dev giảm thời gian và công sức trong quá trình lập trình và phát
		// triển ứng dụng
		// đồng thời tăng hiệu năng ứng dụng
		// Cách thức thừa kế: dùng từ khóa extends để thực hiện thừa kế. Theo đó thì lớp
		// con khi thừa kế lớp cha
		// sẽ được sử dụng nhứng thành phần (member) của lớp cha mà không cần định nghĩa
		// lại
		Cat cat1 = new Cat(5678, "Bengal", 3, "Black");
		cat1.move();
		cat1.inputInfo(input);
		cat1.showInfo();
	}
}
