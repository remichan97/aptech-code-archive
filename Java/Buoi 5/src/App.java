class Animal {
    private int id; //private chỉ được truy cập trực tiếp trong lớp chứa nó
    String name;
    float age;

    // hàm tạo không tham số
    Animal() {
        id = 1234;
        name = "Moon";
        age=1.5f;
    }

    // hàm tạo đầy đủ tham số
    Animal(int id, String name, float age) {
        this.id = id;
        this.name = name;
        this.age = age;
        // this đại diện cho đối tượng hiện thời, là đối tượng gọi đến hàm (phương thức) chứa this.
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public float getAge() {
        return age;
    }

    public void setAge(float age) {
        this.age = age;
    }

    void speak() {
        System.out.println("Gogo,meomeo,growl,..");
    }
    void move() {
        System.out.println("Fly,Swim,Walk..");
    }
}

public class App {
    public static void main(String[] args) throws Exception {
        Animal cat = new Animal();
        // cat.id = 1234;
        cat.setId(3579);
        System.out.println("ID = "+cat.getId());
        System.out.println(cat.name);
        System.out.println(cat.age);
        Animal dog = new Animal(5678,"Bull",2);
        // cat.move();
        // Hàm tạo (Constructor): khởi tạo giá trị ban đầu cho những đối tượng vừa được tạo ra
        // hàm tạo không có tham số.
        // hàm tạo đầy đủ tham số: số lượng và kiểu tham số tương ứng với số lượng và kiểu của thuộc tính
        // hàm tạo có tên trùng với tên lớp
        // getter-setter: dùng để truy cập gián tiếp vào thuộc tính có mức truy cập thấp
        // getter: truy cập thuộc tính để lấy thông tin (cụ thể là xem giá trị thuộc tính)
        // setter: truy cập thuộc tinhs để thay đổi/thiết lập giá trị thuộc tính.
    }    
}
