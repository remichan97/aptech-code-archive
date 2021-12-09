import java.util.Scanner;

public class Student extends Person {
	String masv, email;
	float avg;
	@Override
	public void inputInfo(Scanner input) {
		super.inputInfo(input);
		System.out.println("Enter Student ID:");
		masv = input.nextLine();
		System.out.println("Enter Student Email:");
		email = input.nextLine();
		System.out.println("Enter Student Average marks:");
		avg = input.nextFloat();
	}
	@Override
	public void showInfo() {
		super.showInfo();
		System.out.println("Student ID: " +masv);
		System.out.println("Student Email: " +email);
		System.out.println("Student Average Marks: " +avg);
	}
	
	public boolean checkScholarship() {
		if (avg > 8.0) {
			return true;
		} else {
			return false;
		}
	}
}
