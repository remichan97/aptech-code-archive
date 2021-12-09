import java.util.ArrayList;
import java.util.Scanner;

interface IBook {
	void showInfo();
}

class Book implements IBook {
	int id;
	String name, PublishDate, Author, Language;
	int[] PriceList = new int[5];

	@Override
	public void showInfo() {
		System.out.println("Book name: " + name);
		System.out.println("Publish Date: " + PublishDate);
		System.out.println("Author: " + Author);
		System.out.println("Language: " + Language);
	}

	public float AveragePrice() {
		return (float) ((PriceList[0] + PriceList[1] + PriceList[2] + PriceList[3] + PriceList[4]) / PriceList.length);
	}
}

public class baitapinterface3 {
	public static void menu() {
		System.out.println("Book management");
		System.out.println("1. Add new Book");
		System.out.println("2. View all Books");
		System.out.println("3. Display all Books plus it's average price");
		System.out.println("4. Exit");
	}

	public static void inputInfo(Scanner input, Book foo) {
		input.nextLine();
		System.out.println("Enter book name: ");
		foo.name = input.nextLine();
		System.out.println("Enter book author: ");
		foo.Author = input.nextLine();
		System.out.println("Enter book publish date: ");
		foo.PublishDate = input.nextLine();
		System.out.println("Enter book language: ");
		foo.Language = input.nextLine();
		System.out.println("Enter price:");
		for (int i = 0; i < foo.PriceList.length; i++) {
			System.out.printf("Price #%d: ", i + 1);
			foo.PriceList[i] = input.nextInt();
		}
	}

	public static void main(String[] args) {
		int opt;
		ArrayList<Book> book = new ArrayList<>();
		Scanner input = new Scanner(System.in);
		while (true) {
			do {
				menu();
				System.out.println("Choose an option: ");
				opt = input.nextInt();
			} while (!(1 <= opt && opt <= 4));
			switch (opt) {
				case 1:
					Book foo = new Book();
					foo.id = book.size() + 1;
					inputInfo(input, foo);
					book.add(foo);
					System.out.println("Successfully added book ID " + foo.id + " into the list.");
					break;
				case 2:
					book.forEach(a -> a.showInfo());
					break;
				case 3:
					book.forEach(b -> {
						b.showInfo();
						System.out.println("Average price: " + b.AveragePrice());
					});
					break;
				default:
					System.exit(0);
					break;
			}
		}
	}
}
