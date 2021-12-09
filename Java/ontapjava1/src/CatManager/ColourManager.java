package CatManager;

import java.util.ArrayList;
import java.util.Scanner;

public class ColourManager {
	ArrayList<String> colourList = new ArrayList<>();

	public ArrayList<String> getColourList() {
		return colourList;
	}

	public void setColourList(ArrayList<String> colourList) {
		this.colourList = colourList;
	}

	public void addColour(Scanner input) {
		System.out.println("Enter Colour you wished to add:");
		String colour = input.nextLine();

		while (colourList.contains(colour)) {
			System.out.println("The Colour is already on the list! Please enter a new colour:");
			colour = input.nextLine();
		}

		colourList.add(colour);
	}

	public void listOfColour() {
		for (int i = 0; i < colourList.size(); i++) {
			System.out.println(colourList.get(i));
		}
	}

	public int colourID(String colour) {
		for (int i = 0; i < colourList.size(); i++) {
			if (colourList.get(i).equalsIgnoreCase(colour)) {
				return i;
			}
		}
		return -1;
	}
}
