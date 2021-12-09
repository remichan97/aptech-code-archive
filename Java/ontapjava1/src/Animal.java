import java.util.Scanner;

public abstract class Animal {
	String name;
	int age;
	String description;

	public Animal() {
	}

	public Animal(String name, int age, String description) {
		this.name = name;
		this.age = age;
		this.description = description;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getAge() {
		return age;
	}

	public void setAge(int age) {
		this.age = age;
	}

	public String getDescription() {
		return description;
	}

	public void setDescription(String description) {
		this.description = description;
	}

	public void display() {
		System.out.println(this);
	}

	@Override
	public String toString() {
		return "Animal [age=" + age + ", description=" + description + ", name=" + name + "]";
	}

	public void input(Scanner input) {
		System.out.println("Enter name:");
		name = input.nextLine();
		System.out.println("Enter age:");
		age = Integer.parseInt(input.nextLine());
		System.out.println("Enter description:");
		description = input.nextLine();
	}

	abstract void showSound();
}
