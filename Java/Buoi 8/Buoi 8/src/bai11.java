class Calculation {
	double tinhTong(float a, float b) {
		return a + b;
	}

	double tinhTong(float a, float b, float c) {
		return a + b + c;
	}
}

class Animal {
	int id;
	String name;
	float age;

}

class Cat extends Animal {

}

class Dog extends Animal {

}

public class bai11 {
	public static void main(String[] args) throws Exception {
		// Đa hình:
		Animal animal = new Animal();
		//...
		animal = new Cat();
		//...
		animal = new Dog();
		///////////////////////////
		double d = 10;
		float f = 10.5f;
		int i = 20;
		// i = d;
		d = i;
		// f = d;
		d = f;
	}
}
