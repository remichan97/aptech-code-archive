import java.util.ArrayList;
import java.util.Scanner;

class Product {
	String name;
	String desc;
	double price;

	int[] rate;

	void viewinfo() {
		System.out.println("Product name: " + name);
		System.out.println("Description: " + desc);
		System.out.println("Product Price: " + price);
		for (int i = 0; i < rate.length; i++) {
			System.out.println("Rating#" + (i + 1) + ": " + rate[i]);
		}
	}
}

class Shop {
	ArrayList<Product> ProductList = new ArrayList<>();
	Product temp = new Product();

	void addProduct(Scanner input) {
		input.nextLine();
		System.out.println("Nhập tên sản phẩm: ");
		temp.name = input.nextLine();
		System.out.println("Nhập mô tả sản phẩm: ");
		temp.desc = input.nextLine();
		do {
			System.out.println("Nhập giá thành sản phẩm: ");
			temp.price = input.nextDouble();
		} while (temp.price < 0 || temp.price >= 100);
		System.out.println("Nhập số lượng đánh giá:");
		int num = input.nextInt();
		temp.rate = new int[num];
		for (int i = 0; i < temp.rate.length; i++) {
			do {
				System.out.format("Mời bạn nhập đánh giá thứ %d: ", i + 1);
				temp.rate[i] = input.nextInt();
			} while (temp.rate[i] < 1 || temp.rate[i] > 5);
		}
		ProductList.add(temp);
		temp.viewinfo();
	}

	void removeProduct(Scanner input) {
		String name;
		input.nextLine();
		System.out.println("Nhập tên sản phẩm muốn xóa: ");
		name = input.nextLine();
		for (Product product : ProductList) {
			if (product.name.equals(name)) {
				ProductList.remove(product);
				break;
			}
		}
	}

	void itelateProduct() {
		double avg;
		int tong = 0;
		temp.viewinfo();
		for (int i = 0; i <= ProductList.size(); i++) {
			tong += temp.rate[i];
		}
		avg = tong / ProductList.size();
		System.out.println("Average rating: " + avg);
	}

	void searchProduct(Scanner input) {
		int min, max;
		System.out.println("Type in the minimum price: ");
		min = input.nextInt();
		System.out.println("Type in the maximum price: ");
		max = input.nextInt();
		for (int i = min; i <= max; i++) {
			temp.viewinfo();
		}
	}
}

public class baitap18 {
	public static void menu() {
		System.out.println("PRODUCT MANAGEMENT SYSTEM");
		System.out.println("1. Add new Product");
		System.out.println("2. Remove Product");
		System.out.println("3. Itelate Product list");
		System.out.println("4. Search for a Product");
		System.out.println("5. Exit");
	}

	public static void main(String[] args) {
		int opt;
		Scanner input = new Scanner(System.in);
		Shop shop = new Shop();
		while (true) {
			do {
				menu();
				System.out.println("Choose an option:");
				opt = input.nextInt();
			} while (opt < 1 || opt > 5);
			switch (opt) {
			case 1:
				shop.addProduct(input);
				break;
			case 2:
				shop.removeProduct(input);
				break;
			case 3:
				shop.itelateProduct();
				break;
			case 4:
				shop.searchProduct(input);
				break;
			default:
				System.exit(1);
				break;
			}
		}
	}
}
