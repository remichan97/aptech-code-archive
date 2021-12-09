package baitap1thuake;

import java.util.ArrayList;
import java.util.Scanner;

public class StudentTest {
	public static void menu() {
		System.out.println("Student Management");
		System.out.println("1. Add new Students");
		System.out.println("2. Show all Students");
		System.out.println("3. Students with highest and lowest average score");
		System.out.println("4. Search for a Student");
		System.out.println("5. Show all Student in Alphabet order");
		System.out.println("6. All students eligible for scholarship. Sort in ascending order");
		System.out.println("7. Exit");
	}

	public static void main(String[] args) {
		int opt, n;
		Scanner input = new Scanner(System.in);
		ArrayList<Student> std = new ArrayList<>();
		Student foo;

		while (true) {
			do {
				menu();
				System.out.print("Choose an option: ");
				opt = input.nextInt();
			} while (!(1 <= opt && opt <= 7));
			switch (opt) {
				case 1:
					System.out.print("How many students would you like to add? ");
					n = input.nextInt();
					input.nextLine();
					for (int i = 0; i < n; i++) {
						foo = new Student();
						foo.inputInfo(input);
						std.add(foo);
					}
					break;
				case 2:
					for (Student student : std) {
						student.showInfo();
					}
					break;
				case 3:
					foo = new Student();
					foo.caoThap(std);
					break;
				case 4:
					foo = new Student();
					foo.search(input, std);
					break;
				case 5:
					foo = new Student();
					foo.sapXep(std);
					break;
				case 6:
					foo = new Student();
					foo.hocBongTangDan(std);
					break;
				default:
					System.exit(1);
					break;
			}
		}
	}
}
