package baitap1thuake;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class Student extends Person {
	String sID;
	double avg;
	String email;

	@Override
	void inputInfo(Scanner input) {
		super.inputInfo(input);
		System.out.print("Enter Student ID: ");
		sID = input.nextLine();
		System.out.print("Enter average grade: ");
		avg = input.nextDouble();
		input.nextLine();
		System.out.print("Enter email address: ");
		email = input.nextLine();
	}

	@Override
	void showInfo() {
		super.showInfo();
		System.out.println("Student ID: "+sID);
		System.out.println("Average Grade: "+avg);
		System.out.println("Email address: "+email);
	}

	void hocBong() {
		if (avg >= 8) {
			System.out.println("Student is eligible for scholarship");
		} else {
			System.out.println("Student is not eligible for scholarship");
		}
	}

	void caoThap(ArrayList<Student> std) {
		Collections.sort(std, new Comparator<Student>(){
			@Override
			public int compare(Student o1, Student o2) {
				if (o1.avg > o2.avg) {
					return 1;
				} else if (o1.avg < o2.avg) {
					return 0;
				}
				return -1;
			}
		});
		for (Student student : std) {
			student.showInfo();
		}
	}

	void search(Scanner input, ArrayList<Student> std) {
		input.nextLine();
		String keyword;
		System.out.println("Enter Student ID: ");
		keyword = input.nextLine();
		for (Student student : std) {
			if (student.sID.contains(keyword)) {
				student.showInfo();
				break;
			}
		}
	}

	void sapXep(ArrayList<Student> std) {
		Collections.sort(std, (d1,d2) ->d1.getName().compareTo(d2.getName()));
	}

	void hocBongTangDan(ArrayList<Student> std) {
		for (Student student : std) {
			if (student.avg > 8) {
				student.showInfo();
			}
		}
	}
}
