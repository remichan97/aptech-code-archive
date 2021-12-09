package CatManager;

import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class program {
	static ManagerCat catList = new ManagerCat();
	static ColourManager colourManager = new ColourManager();
	static CatDetail cat;

	public static void sortColour() {
		System.out.println("Sorted colour list:");
		Collections.sort(catList.getCatList(), new Comparator<CatDetail>(){
			@Override
			public int compare(CatDetail o1, CatDetail o2) {
				if (o1.getIndex() == o2.getIndex()) {
					return 1;
				}
				return -1;
			}
		});
		showCat();
	} 

	public static void searchCatByType(Scanner input) {
		System.out.println("Enter type to search:");
		String key = input.nextLine();
		catList.getCatList().forEach(a -> {
			if (a.getLoai().equalsIgnoreCase(key)) {
				a.hienthi();
			}
		});
	}

	public static void sortCatByColour() {
		Collections.sort(catList.getCatList(), new Comparator<CatDetail>(){

			@Override
			public int compare(CatDetail o1, CatDetail o2) {
				return o1.getMau().compareToIgnoreCase(o2.getMau());	
			}
			
		});
		showCat();
	}

	public static void showCat() {
		catList.getCatList().forEach(a -> a.hienthi());
	}

	public static void menu() {
		System.out.println("0. Add Colour");
		System.out.println("1. Add cats");
		System.out.println("2. Show all Cats");
		System.out.println("3. Sort by Colours");
		System.out.println("4. Search by Type");
		System.out.println("5. Sort Colour");
		System.out.println("6. Exit");
		System.out.println("Your choice:");
	}

	public static void main(String[] args) {

		Scanner input = new Scanner(System.in);
		int opt;
		do {
			menu();
			opt = Integer.parseInt(input.nextLine());
			switch (opt) {
				case 0:
					int n;
					System.out.println("How many colours would you like to add?");
					n = Integer.parseInt(input.nextLine());
					for (int i = 0; i < n; i++) {
						colourManager.addColour(input);
					}
					break;
				case 1:
					System.out.println("How many cats would you like to add? ");
					int a = Integer.parseInt(input.nextLine());
					for (int i = 0; i < a; i++) {
						cat = new CatDetail();
						cat.nhap(input);

						catList.getCatList().add(cat);
					}
					break;
				case 2:
					System.out.println("Available cats:");
					showCat();
					break;
				case 3:
					System.out.println("Sorted cat list by Colour:");
					sortCatByColour();
					break;
				case 4:
					searchCatByType(input);
					break;
				case 5:
					sortColour();
					break;
				case 6:
					System.exit(0);
					break;
				default:
					colourManager.listOfColour();
					break;
			}
		} while (opt != 6);
	}
}
