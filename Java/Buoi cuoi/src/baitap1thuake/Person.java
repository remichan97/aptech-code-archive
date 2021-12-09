package baitap1thuake;

import java.util.Scanner;

public class Person {
	private String name;
	private String gender;
	private String dob;
	private String address;

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getGender() {
		return gender;
	}

	public void setGender(String gender) {
		this.gender = gender;
	}

	public String getDob() {
		return dob;
	}

	public void setDob(String dob) {
		this.dob = dob;
	}

	public String getAddress() {
		return address;
	}

	public void setAddress(String address) {
		this.address = address;
	}

	void inputInfo(Scanner input) {
		System.out.print("Enter name: ");
		name = input.nextLine();
		System.out.print("Enter gender: ");
		gender = input.nextLine();
		System.out.print("Enter date of birth: ");
		dob = input.nextLine();
		System.out.print("Enter address: ");
		address = input.nextLine();
	}

	void showInfo() {
		System.out.println("Name: " + name);
		System.out.println("Gender: " + gender);
		System.out.println("Date of Birth: " + dob);
		System.out.println("Address: " + address);
	}
}
