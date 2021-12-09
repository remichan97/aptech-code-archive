package baitap1thuake;

import java.util.ArrayList;
import java.util.Scanner;

public class Teacher extends Person {
	String lop;
	int luong;
	int hour;

	@Override
	void inputInfo(Scanner input) {
		input.nextLine();
		super.inputInfo(input);
		System.out.println("Enter teaching class: ");
		lop = input.nextLine();
		System.out.println("Enter Salary: ");
		luong = input.nextInt();
		System.out.println("Enter teaching hour: ");
		hour = input.nextInt();
	}

	@Override
	void showInfo() {
		super.showInfo();
		System.out.println("Teaching class: " + lop);
		System.out.println("Salary: " + luong);
		System.out.println("Teaching hours: " + hour);
	}

	int tinhLuong(ArrayList<Teacher> teacher) {
		if (lop.startsWith("L") || lop.startsWith("M")) {
			return luong * hour;
		} else {
			return luong * hour + 200000;
		}
	}
}
