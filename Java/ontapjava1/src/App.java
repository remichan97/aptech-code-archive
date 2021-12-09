import java.util.Scanner;

public class App {

    public static void menu() {
        System.out.println("1. Add a Room");
        System.out.println("2. Remove a Room");
        System.out.println("3. Add an Animal");
        System.out.println("4. Remove an Animal");
        System.out.println("5. Show all Animals");
        System.out.println("6. Exit");
        System.out.println("Your choice:");

    }
    public static void main(String[] args) throws Exception {
        int opt;
        Scanner input = new Scanner(System.in);
        Zoo zoo = new Zoo();

        do {
            menu();
            opt = Integer.parseInt(input.nextLine());
            switch (opt) {
                case 1:
                    Room room = new Room();
                    room.input(input);

                    zoo.getRoomList().add(room);
                    break;
            
                case 2:
                    System.out.println("Enter the Room No you wish to remove:");
                    int rm = Integer.parseInt(input.nextLine());

                    for (int i = 0; i < zoo.getRoomList().size(); i++) {
                        if (zoo.getRoomList().get(i).getRoomNo() == rm) {
                            zoo.getRoomList().remove(i);
                            break;
                        }
                    }
                    break;
                case 3:
                    zoo.addAnimal(input);
                    break;
                case 4:
                    zoo.removeAnimal(input);
                    break;
                case 5:
                    zoo.display();
                    break;
                case 6:
                    System.exit(0);
                    break;
            }
        } while (opt != 6);

    }
}
