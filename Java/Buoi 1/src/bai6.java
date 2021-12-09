import java.util.Scanner;

public class bai6 {
	public static void main(String[] args) {
		double a,b,c,p,s;
		Scanner input = new Scanner(System.in);
		System.out.println("Nhập cạnh thứ nhất của tam giác vuông: ");
		a = input.nextDouble();
		System.out.println("Nhập cạnh thứ hai của tam giác vuông: ");
		b = input.nextDouble();
		c = Math.sqrt(Math.pow(a, 2) + Math.pow(b, 2));
		s = (a*b)/2;
		p = a+b+c;
		System.out.println("Chu vi =  "+p);
		System.out.println("Diện tích =  "+s);
		input.close();
	}
}
