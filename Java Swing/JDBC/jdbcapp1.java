import java.sql.Statement;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;

public class jdbcapp1 {
	public static void main(String[] args) {
		try {
			Class.forName("com.mysql.jdbc.Driver");
			Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/db_demo", "root", "");
			Statement stmt = con.createStatement();
			ResultSet rs = stmt.executeQuery("select*from category");
			while (rs.next()) {
				System.out.println(rs.getInt("id") + " " + rs.getString("id") + " " + rs.getByte("id"));	
			}
			con.close();
		} catch (Exception e) {
			System.out.println(e);
		}
	}
}
