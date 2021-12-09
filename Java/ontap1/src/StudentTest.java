import java.util.ArrayList;
import java.util.Scanner;

public class StudentTest {
	static Student std;

	public static void addStudent(ArrayList<Student> stdList, Scanner input) {
		std = new Student();
		std.inputInfo(input);
		stdList.add(std);
	}

	public static void showStudent(ArrayList<Student> stdList) {
		stdList.forEach((a) -> a.showInfo());
	}

	public static void highestAVG(ArrayList<Student> stdList) {
		ArrayList<Student> tmp = stdList;
		tmp.sort();

	}

	public static void menu() {
		System.out.println("1. Add new Students");
		System.out.println("2. Show all Students");
		System.out.println("3. Highest Average Student and Lowest Average Student");
		System.out.println("4. Find a Student");
		System.out.println("5. Sort Students alphabetically");
		System.out.println("6. Students eligible for Scholarship and sort from highest to lowest");
		System.out.println("7. Exit");
	}

	public static void main(String[] args) throws Exception {
		int opt;
		Scanner input = new Scanner(System.in);
		ArrayList<Student> stdList = new ArrayList<Student>();
		do {
			menu();
			System.out.println("Enter your choice:");
			opt = input.nextInt();
			switch (opt) {
				case 1:
					int n;
					System.out.println("Enter the number of Students you'd like to add:");
					n = input.nextInt();
					for (int i = 1; i <= n; i++) {
						input.nextLine();
						addStudent(stdList, input);
					}
					break;
				case 2:
					showStudent(stdList);
					break;
				case 3:
					highestAVG(stdList);
					break;
				case 7:
					System.exit(0);
					break;
			}
		} while (opt != 7);

	}
}
