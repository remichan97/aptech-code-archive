import java.util.ArrayList;
import java.util.Scanner;

interface IStudent {
	void showStudent();
}

class Student implements IStudent {
	String fullname, DoB, Native, PhoneNo, Class;
	int id, mobile;

	@Override
	public void showStudent() {
		System.out.println("Student ID: " + id);
		System.out.println("Full name: " + fullname);
		System.out.println("Date of Birth: " + DoB);
		System.out.println("Native: " + Native);
		System.out.println("Class: " + Class);
		System.out.println("Phone number: " + PhoneNo);
		System.out.println("Mobile: " + mobile);
	}

}

public class baitapinterface5 {
	public static void menu() {
		System.out.println("Student management");
		System.out.println("1. Add new Student.");
		System.out.println("2. View all Student(s).");
		System.out.println("3. Search for Student(s).");
		System.out.println("4. Exit");
	}

	public static void insertStd(Scanner input, Student foo) {
		System.out.print("Enter Student full name: ");
		foo.fullname = input.nextLine();
		System.out.print("Enter Student date of birth: ");
		foo.DoB = input.nextLine();
		System.out.print("Enter Student Native: ");
		foo.Native = input.nextLine();
		System.out.print("Enter Student Class: ");
		foo.Class = input.nextLine();
		System.out.print("Enter Student Phone number: ");
		foo.PhoneNo = input.nextLine();
		System.out.print("Enter Student mobile number: ");
		foo.mobile = input.nextInt();
	}

	public static void main(String[] args) {
		int opt;
		Scanner input = new Scanner(System.in);
		ArrayList<Student> std = new ArrayList<>();
		String keyword;
		while (true) {
			do {
				menu();
				System.out.println("Choose an option: ");
				opt = input.nextInt();
			} while (!(1 <= opt && opt <= 4));
			switch (opt) {
				case 1:
					input.nextLine();
					Student foo = new Student();
					foo.id = std.size() + 1;
					insertStd(input, foo);
					std.add(foo);
					System.out.println("Successfully added Student with ID " + foo.id + " into the list.");
					break;
				case 2:
					std.forEach(a -> a.showStudent());
					break;
				case 3:
					input.nextLine();
					System.out.print("Enter a class you wish to search Student from: ");
					keyword = input.nextLine();
					for (Student student : std) {
						if (student.Class.contains(keyword)) {
							student.showStudent();
						}
					}
					break;
				default:
					System.exit(0);
					break;
			}
		}
	}
}
