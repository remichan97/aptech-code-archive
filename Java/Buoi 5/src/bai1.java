import java.util.Scanner;

class SoHoc {
	private int number1;
	private int number2;

	void inputInfo() {
		final Scanner input = new Scanner(System.in);
		System.out.println("Nhập number1");
		number1 = input.nextInt();
		System.out.println("Nhập number2");
		number2 = input.nextInt();
		input.close();
	}

	void printInfo() {
		System.out.println("number1 = " + number1);
		System.out.println("number2 = " + number2);
	}

	public int getNumber1() {
		return number1;
	}

	public void setNumber1(final int number1) {
		this.number1 = number1;
	}

	public int getNumber2() {
		return number2;
	}

	public void setNumber2(final int number2) {
		this.number2 = number2;
	}

	int addition() {
		return number1 + number2;
	}

	int subtraction() {
		return number1 - number2;
	}

	int multi() {
		return number1 * number2;
	}

	void divide() {
		if ((float)number1/number2 == Float.POSITIVE_INFINITY || (float)number1/number2 == Float.NEGATIVE_INFINITY) {
			System.out.println("Không thể chia cho 0");
		} else {
			System.out.println(+number1 + " / " + number2 + " = " + (float) number1 / number2);
		}
	}
}

public class bai1 {
	public static void main(final String[] args) {
		final SoHoc num = new SoHoc();
		num.inputInfo();
		num.printInfo();
		System.out.println(+num.getNumber1() + " + " + num.getNumber2() + " = " + num.addition());
		System.out.println(+num.getNumber1() + " - " + num.getNumber2() + " = " + num.subtraction());
		System.out.println(+num.getNumber1() + " * " + num.getNumber2() + " = " + num.multi());
		num.divide();
	}
}
