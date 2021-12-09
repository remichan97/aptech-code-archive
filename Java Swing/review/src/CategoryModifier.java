import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

public class CategoryModifier {
	static final String url = "jdbc:mysql://localhost:3306/products";
	static final String user = "root";
	static final String password = "";
	static Connection con = null;

	public static void deleteCategory(int id) {
		try {
			con = DriverManager.getConnection(url, user, password);

			String sql = "delete from category where id = ?";
			PreparedStatement preparedStatement = con.prepareStatement(sql);
			preparedStatement.setInt(1, id);
			preparedStatement.executeUpdate();
		} catch (Exception e) {
			Logger.getLogger(CategoryModifier.class.getName()).log(Level.SEVERE, null, e);
		} finally {
			try {
				if (con != null) {
					con.close();
				}
			} catch (Exception e) {
				Logger.getLogger(CategoryModifier.class.getName()).log(Level.SEVERE, null, e);
			}
		}
	}

	public static void editCategory(Category cat) {
		try {
			con = DriverManager.getConnection(url, user, password);

			String sql = "update category set catName = ? where catID = ?";
			PreparedStatement preparedStatement = con.prepareStatement(sql);
			preparedStatement.setString(1, cat.getCatName());
			preparedStatement.setInt(2, cat.getId());
			preparedStatement.executeUpdate();
		} catch (Exception e) {
			Logger.getLogger(CategoryModifier.class.getName()).log(Level.SEVERE, null, e);
		} finally {
			try {
				if (con != null) {
					con.close();
				}
			} catch (Exception e) {
				Logger.getLogger(CategoryModifier.class.getName()).log(Level.SEVERE, null, e);
			}
		}
	}

	public static void addCategory(Category cat) {
		try {
			con = DriverManager.getConnection(url, user, password);

			String sql = "insert into category (catName) values (?)";
			PreparedStatement preparedStatement = con.prepareStatement(sql);
			preparedStatement.setString(1, cat.getCatName());
			preparedStatement.executeUpdate();
		} catch (Exception e) {
			Logger.getLogger(CategoryModifier.class.getName()).log(Level.SEVERE, null, e);
		} finally {
			try {
				if (con != null) {
					con.close();
				}
			} catch (Exception e) {
				Logger.getLogger(CategoryModifier.class.getName()).log(Level.SEVERE, null, e);
			}
		}
	}

	public static List<Category> getCategory() {
		List<Category> catList = new ArrayList<>();

		try {
			con = DriverManager.getConnection(url, user, password);

			String sql = "select*from category";

			PreparedStatement preparedStatement = con.prepareStatement(sql);

			ResultSet resultSet = preparedStatement.executeQuery();

			while (resultSet.next()) {
				Category cat = new Category(resultSet.getInt("catID"), resultSet.getString("catName"));
				catList.add(cat);
			}
		} catch (Exception e) {
			Logger.getLogger(CategoryModifier.class.getName()).log(Level.SEVERE, null, e);
		} finally {
			try {
				if (con != null) {
					con.close();
				}
			} catch (Exception e) {
				Logger.getLogger(CategoryModifier.class.getName()).log(Level.SEVERE, null, e);
			}
		}

		return catList;
	}
}
