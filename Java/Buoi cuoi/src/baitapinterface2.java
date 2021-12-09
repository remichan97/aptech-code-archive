import java.util.ArrayList;
import java.util.Scanner;

interface INews {
	void Display();
}

class News implements INews {
	int id;
	String Title, PublishDate, Author, Content;
	float avgRate;
	int[] rateList = new int[3];

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

	public String getTitle() {
		return Title;
	}

	public void setTitle(String title) {
		Title = title;
	}

	public String getPublishDate() {
		return PublishDate;
	}

	public void setPublishDate(String publishDate) {
		PublishDate = publishDate;
	}

	public String getAuthor() {
		return Author;
	}

	public void setAuthor(String author) {
		Author = author;
	}

	public String getContent() {
		return Content;
	}

	public void setContent(String content) {
		Content = content;
	}

	public float getAvgRate() {
		return avgRate;
	}

	@Override
	public void Display() {
		System.out.println("Tille: " + Title);
		System.out.println("Publish date: " + PublishDate);
		System.out.println("Author: " + Author);
		System.out.println("Content: " + Content);
		System.out.println("Average Rate: " + avgRate);
	}

	public float calculate() {
		return avgRate = (rateList[0] + rateList[1] + rateList[2]) / rateList.length;
	}
}

public class baitapinterface2 {
	public static void menu() {
		System.out.println("News Management");
		System.out.println("1. Insert news");
		System.out.println("2. View all news");
		System.out.println("3. Average rating");
		System.out.println("4. Exit");
	}

	public static void inputNews(Scanner input, News article) {
		News foo = new News();
		input.nextLine();
		System.out.println("Enter title: ");
		foo.Title = input.nextLine();
		System.out.println("Enter author: ");
		foo.Author = input.nextLine();
		System.out.println("Enter Publish date: ");
		foo.PublishDate = input.nextLine();
		System.out.println("Enter Content: ");
		foo.Content = input.nextLine();
		for (int i = 0; i < foo.rateList.length; i++) {
			System.out.printf("Enter rating #%d: ", i + 1);
			foo.rateList[i] = input.nextInt();
		}
	}

	public static void showInfo() {

	}

	public static void main(String[] args) throws Exception {
		int opt;
		Scanner input = new Scanner(System.in);
		ArrayList<News> news = new ArrayList<>();

		while (true) {
			do {
				menu();
				System.out.print("Choose an action: ");
				opt = input.nextInt();
			} while (!(1 <= opt && opt <= 4));
			switch (opt) {
				case 1:
					News article = new News();
					inputNews(input, article);
					article.id = news.size() + 1;
					news.add(article);
					System.out.println("Added news with ID " + article.id + " into the list");
					break;
				case 2:
					System.out.println("Current listing: ");
					news.forEach(a -> a.Display());
					break;
				case 3:
					System.out.println("Current listing with average rate: ");
					news.forEach(a -> {
						a.Display();
						System.out.println("Average rating: " + a.calculate());
					});
					break;
				default:
					System.exit(0);
					break;
			}
		}
	}
}
