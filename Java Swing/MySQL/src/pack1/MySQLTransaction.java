package src.pack1;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.logging.Level;
import java.util.logging.Logger;

public class MySQLTransaction {
	public void showData() {
		try {
			Connection con = (new MySQLConnection()).getConnection();
			Statement stm = con.createStatement();
			ResultSet rs = stm.executeQuery("select*from category");
			while (rs.next()) {
				System.out.println(rs.getInt(1) + " " + rs.getString(2) + " " + rs.getByte(3));
			}
		} catch (ClassNotFoundException | SQLException ex) {
			Logger.getLogger(MySQLTransaction.class.getName()).log(Level.SEVERE, null, ex);
		}
	}

	public void addData(String name) {
		try {
			Connection con = (new MySQLConnection()).getConnection();
			Statement stm = con.createStatement();
			stm.executeUpdate("insert category (categoryName) values ('" + name + "')");

		} catch (ClassNotFoundException | SQLException ex) {
			Logger.getLogger(MySQLTransaction.class.getName()).log(Level.SEVERE, null, ex);
		}
	}

	public void updateData(String name, int id) {
		try {
			Connection con = (new MySQLConnection()).getConnection();
			Statement stm = con.createStatement();
			stm.executeUpdate("insert category set categoryName='" + name + "' where id=" + id);
		} catch (ClassNotFoundException | SQLException ex) {
			Logger.getLogger(MySQLTransaction.class.getName()).log(Level.SEVERE, null, ex);
		}
	}

	public void deleteData(int id) {
		try {
			Connection con = (new MySQLConnection()).getConnection();
			Statement stm = con.createStatement();
			stm.executeUpdate("delete from category where id="+id);
		} catch (ClassNotFoundException | SQLException ex) {
			Logger.getLogger(MySQLTransaction.class.getName()).log(Level.SEVERE, null, ex);
		}
	}
}
