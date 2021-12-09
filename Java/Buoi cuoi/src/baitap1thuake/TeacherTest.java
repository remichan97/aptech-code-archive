package baitap1thuake;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class TeacherTest {
	public static void menu() {
		System.out.println("Teacher Management");
		System.out.println("1. Add new Teacher(s)");
		System.out.println("1. Show all Teacher");
		System.out.println("1. Teaher with Highest Salary");
		System.out.println("4. Exit");
	}

	public static void main(String[] args) {
		int opt, n;
		ArrayList<Teacher> teacher = new ArrayList<>();
		Teacher tch;
		Scanner input = new Scanner(System.in);

		while (true) {
			do {
				System.out.print("Choose an option: ");
				opt = input.nextInt();
			} while (!(1 <= opt && opt <= 4));
			switch (opt) {
				case 1:
					System.out.println("How many teacher(s) would you like to add? ");
					n = input.nextInt();
					for (int i = 0; i < n; i++) {
						tch = new Teacher();
						tch.inputInfo(input);
						teacher.add(tch);
					}
					break;
				case 2:
					tch = new Teacher();
					tch.showInfo();
					break;
				case 3:
					Integer[] luong = new Integer[teacher.size()];
					tch = new Teacher();
					for (Teacher t : teacher) {
						for (int i = 0; i < luong.length; i++) {
							luong[i] = t.tinhLuong(teacher);
						}
					}
					Arrays.sort(luong);
					System.out.println(luong[luong.length - 1]);
					break;
				default:
					System.exit(1);
					break;
			}
		}
	}
}
