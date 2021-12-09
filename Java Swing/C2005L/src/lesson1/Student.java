/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lesson1;

/**
 *
 * @author Mirai
 */
public class Student {
    int id;
	String fullname, gender, email, phone;
	int age;

	public Student() {
	}

	public Student(int id, String fullname, String gender, String email, String phone, int age) {
		this.id = id;
		this.fullname = fullname;
		this.gender = gender;
		this.email = email;
		this.phone = phone;
		this.age = age;
	}

	public Student(String fullname, String gender, String email, String phone, int age) {
		this.fullname = fullname;
		this.gender = gender;
		this.email = email;
		this.phone = phone;
		this.age = age;
	}

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getFullname() {
		return fullname;
	}

	public void setFullname(String fullname) {
		this.fullname = fullname;
	}

	public String getGender() {
		return gender;
	}

	public void setGender(String gender) {
		this.gender = gender;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public String getPhone() {
		return phone;
	}

	public void setPhone(String phone) {
		this.phone = phone;
	}

	public int getAge() {
		return age;
	}

	public void setAge(int age) {
		this.age = age;
	}

	
	
}
