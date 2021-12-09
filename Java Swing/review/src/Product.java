public class Product {
	int id;
	String productName;
	int catID;
	int price;
	String description;

	public Product(int id, String productName, int catID, int price, String description) {
		this.id = id;
		this.productName = productName;
		this.catID = catID;
		this.price = price;
		this.description = description;
	}

	public Product(String productName, int catID, int price, String description) {
		this.productName = productName;
		this.catID = catID;
		this.price = price;
		this.description = description;
	}



	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getProductName() {
		return productName;
	}

	public void setProductName(String productName) {
		this.productName = productName;
	}

	public int getCatID() {
		return catID;
	}

	public void setCatID(int catID) {
		this.catID = catID;
	}

	public int getPrice() {
		return price;
	}

	public void setPrice(int price) {
		this.price = price;
	}

	public String getDescription() {
		return description;
	}

	public void setDescription(String description) {
		this.description = description;
	}
}
