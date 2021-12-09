/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lesson1;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Mirai
 */
public class StudentModify {
	static final String user = "root";
	static final String pw = "";
	static final String host = "jdbc:mysql://localhost:3306/c2005l";

	public static List<Student> getStudentList(String s) {
		List<Student> dataList = new ArrayList<>();

		Connection con = null;
		try {
			// Lay thong tin du lieu tu database
			// B1. Ket noi toi data
			con = DriverManager.getConnection(host, user, pw);

			// B2. Thuc hien lay du lieu
			String sql = "select * from students";
			if (s != null && !s.isEmpty()) {
				sql += " where fullname like '" + s + "'";
			}
			PreparedStatement statement = con.prepareStatement(sql);

			ResultSet resultSet = statement.executeQuery();

			// Fetch data
			while (resultSet.next()) {
				Student std = new Student(resultSet.getInt("id"), resultSet.getString("fullname"),
						resultSet.getString("gender"), resultSet.getString("email"), resultSet.getString("phone"),
						resultSet.getInt("age"));
				dataList.add(std);
			}
		} catch (SQLException ex) {
			Logger.getLogger(StudentModify.class.getName()).log(Level.SEVERE, null, ex);
		} finally {
			// B3. Dong ket noi toi database
			if (con != null) {
				try {
					con.close();
				} catch (SQLException ex) {
					Logger.getLogger(StudentModify.class.getName()).log(Level.SEVERE, null, ex);
				}
			}
		}

		return dataList;
	}

	public static void update(Student std) {
		Connection con = null;
		try {
			// Lay thong tin du lieu tu database
			// B1. Ket noi toi data
			con = DriverManager.getConnection(host, user, pw);

			// B2. Thuc hien lay du lieu
			String sql = "update students set fullname = ?, email = ?, gender = ?, age = ?, phone = ? where id = ?";
			PreparedStatement statement = con.prepareStatement(sql);

			statement.setString(1, std.getFullname());
			statement.setString(2, std.getEmail());
			statement.setString(3, std.getGender());
			statement.setInt(4, std.getAge());
			statement.setString(5, std.getPhone());
			statement.setInt(6, std.getId());

			statement.execute();
		} catch (SQLException ex) {
			Logger.getLogger(StudentModify.class.getName()).log(Level.SEVERE, null, ex);
		} finally {
			// B3. Dong ket noi toi database
			if (con != null) {
				try {
					con.close();
				} catch (SQLException ex) {
					Logger.getLogger(StudentModify.class.getName()).log(Level.SEVERE, null, ex);
				}
			}
		}
	}

	public static void delete(int id) {
		Connection con = null;
		try {
			// Lay thong tin du lieu tu database
			// B1. Ket noi toi data
			con = DriverManager.getConnection(host, user, pw);

			// B2. Thuc hien lay du lieu
			String sql = "delete from students where id = ?";
			PreparedStatement statement = con.prepareStatement(sql);

			statement.setInt(1, id);

			statement.execute();
		} catch (SQLException ex) {
			Logger.getLogger(StudentModify.class.getName()).log(Level.SEVERE, null, ex);
		} finally {
			// B3. Dong ket noi toi database
			if (con != null) {
				try {
					con.close();
				} catch (SQLException ex) {
					Logger.getLogger(StudentModify.class.getName()).log(Level.SEVERE, null, ex);
				}
			}
		}
	}

	public static void insert(Student std) {
		Connection con = null;
		try {
			// Lay thong tin du lieu tu database
			// B1. Ket noi toi data
			con = DriverManager.getConnection(host, user, pw);

			// B2. Thuc hien lay du lieu
			String sql = "insert into students (fullname, email, gender, age, phone) values (?, ?, ?, ?, ?)";
			PreparedStatement statement = con.prepareStatement(sql);

			statement.setString(1, std.getFullname());
			statement.setString(2, std.getEmail());
			statement.setString(3, std.getGender());
			statement.setInt(4, std.getAge());
			statement.setString(5, std.getPhone());

			statement.execute();
		} catch (SQLException ex) {
			Logger.getLogger(StudentModify.class.getName()).log(Level.SEVERE, null, ex);
		} finally {
			// B3. Dong ket noi toi database
			if (con != null) {
				try {
					con.close();
				} catch (SQLException ex) {
					Logger.getLogger(StudentModify.class.getName()).log(Level.SEVERE, null, ex);
				}
			}
		}
	}
}
