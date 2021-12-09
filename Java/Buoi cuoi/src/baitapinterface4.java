import java.util.ArrayList;
import java.util.Scanner;

interface IStudentMark {
	void showMarks();
}

class StudentMark implements IStudentMark {
	int id, semester;
	String fullname, lopHoc;
	int[] subjectMarks = new int[5];

	@Override
	public void showMarks() {
		System.out.println("Student ID: " + id);
		System.out.println("Student Fullname: " + fullname);
		System.out.println("Student Class: " + lopHoc);
		System.out.println("Current semester: " + semester);
	}

	public float avgMark() {
		int sum = 0;
		for (int i = 0; i < subjectMarks.length; i++) {
			sum += subjectMarks[i];
		}
		return (float) (sum / subjectMarks.length);
	}
}

public class baitapinterface4 {
	public static void menu() {
		System.out.println("Marks management system");
		System.out.println("1. Add new Student");
		System.out.println("2. View list of Student");
		System.out.println("3. View list of Student and their average marks");
		System.out.println("4. Exit");
	}

	public static void insert(Scanner input, StudentMark std) {
		input.nextLine();
		System.out.println("Enter Student name:");
		std.fullname = input.nextLine();
		System.out.println("Enter Class name:");
		std.lopHoc = input.nextLine();
		System.out.println("Enter current semester:");
		std.semester = input.nextInt();
		System.out.println("Enter Student marks below:");
		for (int i = 0; i < std.subjectMarks.length; i++) {
			System.out.printf("Enter marks of subject #%d: ", i + 1);
			std.subjectMarks[i] = input.nextInt();
		}
	}

	public static void main(String[] args) {
		int opt;
		ArrayList<StudentMark> stdMark = new ArrayList<>();
		Scanner input = new Scanner(System.in);
		while (true) {
			do {
				menu();
				System.out.print("Choose an option: ");
				opt = input.nextInt();
			} while (!(1 <= opt && opt <= 4));
			switch (opt) {
				case 1:
					StudentMark std = new StudentMark();
					std.id = stdMark.size() + 1;
					insert(input, std);
					stdMark.add(std);
					System.out.println("Successfully added Student with ID " + std.id + " into the list.");
					break;
				case 2:
					stdMark.forEach(a -> a.showMarks());
					break;
				case 3:
					stdMark.forEach(b -> {
						b.showMarks();
						System.out.println("Average marks: " + b.avgMark());
					});
					break;
				default:
					System.exit(0);
					break;
			}
		}
	}
}
