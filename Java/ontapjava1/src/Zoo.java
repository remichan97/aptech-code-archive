import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Zoo {
	List<Room> roomList;

	public Zoo() {
		roomList = new ArrayList<>();
	}
	
	public List<Room> getRoomList() {
		return roomList;
	}

	public void setRoomList(List<Room> roomList) {
		this.roomList = roomList;
	}

	public void addAnimal(Scanner input) {
		int a;
		System.out.println("Enter room no you wanted to add animal:");
		a = Integer.parseInt(input.nextLine());

		for (Room room : roomList) {
			if (room.getRoomNo() == a) {
				room.addAnimal(input);
			}
		}
	}

	public void removeAnimal(Scanner input) {
		int b;
		System.out.println("Enter Room No you wish to remove animal from:");
		b = Integer.parseInt(input.nextLine());

		for (Room room : roomList) {
			if (room.getRoomNo() == b) {
				System.out.println("Enter animal name you wanted to remove:");
				String rm = input.nextLine();
				room.removeAnimal(rm);
				break;
			}
		}
	}

	public void display() {
		System.out.println("Zoo Information:");

		for (Room room : roomList) {
			room.display();
		}
	}
}
