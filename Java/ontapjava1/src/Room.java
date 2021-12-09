import java.util.List;
import java.util.Scanner;

public class Room {
	int roomNo;
	List<Animal> animalList;

	public Room() {
	}

	public Room(int roomNo, List<Animal> animalList) {
		this.roomNo = roomNo;
		this.animalList = animalList;
	}

	public int getRoomNo() {
		return roomNo;
	}

	public void setRoomNo(int roomNo) {
		this.roomNo = roomNo;
	}

	public List<Animal> getAnimalList() {
		return animalList;
	}

	public void setAnimalList(List<Animal> animalList) {
		this.animalList = animalList;
	}

	public Animal createAnimal(Scanner input) {
		Animal animal = null;
		int opt;

		do {
			System.out.println("1. Add a new Tiger");
			System.out.println("2. Add a new Dog");
			System.out.println("3. Add a new Cat");
			System.out.println("Your choice:");
			opt = Integer.parseInt(input.nextLine());
		} while (opt != 3);

		switch (opt) {
			case 1:
				animal = new Tiger();
				break;
			case 2:
				animal = new Dog();
				break;
			case 3:
				animal = new Cat();
				break;
		}
		animal.input(input);
		return animal;
	}

	public void addAnimal(Scanner input) {
		Animal animal = createAnimal(input);
		animalList.add(animal);
	}

	public void removeAnimal(String rm) {
		for (int i = 0; i < animalList.size(); i++) {
			if (animalList.get(i).getName().equalsIgnoreCase(rm)) {
				animalList.remove(i);
				break;
			}
		}
	}

	public void display() {
		System.out.println("Room No:" +roomNo);
		animalList.forEach(a -> {
			a.display();
			a.showSound();
		});
	}

	public void input(Scanner input) {
		System.out.println("Input Room No of room needed to add animal:");
		roomNo = Integer.parseInt(input.nextLine());
		System.out.println("How many animals you wanted to add:");
		int n = Integer.parseInt(input.nextLine());

		for (int i = 0; i < n; i++) {
			Animal animal = createAnimal(input);
			animalList.add(animal);
		}
	}
}
