import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ProductModifier {
	static final String url = "jdbc:mysql://localhost:3306/products";
	static final String user = "root";
	static final String password = "";
	static Connection con = null;

	public static void deleteProduct(int id) {
		try {
			con = DriverManager.getConnection(url, user, password);

			String sql = "delete from productname where id = ?";

			PreparedStatement preparedStatement = con.prepareStatement(sql);
			
			preparedStatement.setInt(1, id);

			preparedStatement.executeUpdate();
		} catch (Exception e) {
			Logger.getLogger(ProductModifier.class.getName()).log(Level.SEVERE, null, e);
		} finally {
			try {
				if (con != null) {
					con.close();
				}				
			} catch (Exception e) {
				Logger.getLogger(ProductModifier.class.getName()).log(Level.SEVERE, null, e);
			}
		}
	}

	public static void editProduct(Product prd) {
		try {
			con = DriverManager.getConnection(url, user, password);

			String sql = "update productname set name = ? catID = ? price = ? description = ? where id = ?";

			PreparedStatement preparedStatement = con.prepareStatement(sql);
			preparedStatement.setString(1, prd.getProductName());
		} catch (Exception e) {
			Logger.getLogger(ProductModifier.class.getName()).log(Level.SEVERE, null, e);
		} finally {
			try {
				if (con != null) {
					con.close();
				}				
			} catch (Exception e) {
				Logger.getLogger(ProductModifier.class.getName()).log(Level.SEVERE, null, e);
			}
		}
	}

	public static void addProduct(Product prd) {
		try {
			con = DriverManager.getConnection(url, user, password);

			String sql = "insert into productname (name, catID, price, description) values (?, ?, ?, ?)";

			PreparedStatement preparedStatement = con.prepareStatement(sql);
			preparedStatement.setString(1, prd.getProductName());
			preparedStatement.setInt(2, prd.getId());
			preparedStatement.setInt(3, prd.getPrice());
			preparedStatement.setString(1, prd.getDescription());
			
			preparedStatement.executeUpdate();
		} catch (Exception e) {
			Logger.getLogger(ProductModifier.class.getName()).log(Level.SEVERE, null, e);
		} finally {
			try {
				if (con != null) {
					con.close();
				}				
			} catch (Exception e) {
				Logger.getLogger(ProductModifier.class.getName()).log(Level.SEVERE, null, e);
			}
		}
	}

	public static List<Product> getProductList(String searchTerm) {
		List<Product> prdList = new ArrayList<>();

		try {
			con = DriverManager.getConnection(url, user, password);
			String sql = "select*from productname";

			if (searchTerm != null && !searchTerm.isEmpty()) {
				sql += " where name like '" + searchTerm + "'";
			}

			PreparedStatement preparedStatement = con.prepareStatement(sql);

			ResultSet resultSet = preparedStatement.executeQuery();

			while (resultSet.next()) {
				Product prd = new Product(resultSet.getInt("id"), resultSet.getString("name"), resultSet.getInt("catID"), resultSet.getInt("price"), resultSet.getString("description"));
				prdList.add(prd);
			}
		} catch (Exception e) {
			Logger.getLogger(ProductModifier.class.getName()).log(Level.SEVERE, null, e);
		} finally {
			try {
				if (con != null) {
					con.close();
				}				
			} catch (Exception e) {
				Logger.getLogger(ProductModifier.class.getName()).log(Level.SEVERE, null, e);
			}
		}

		return prdList;
	}
}
