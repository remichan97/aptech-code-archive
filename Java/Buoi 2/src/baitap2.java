public class baitap2 {
	public static void main(String[] args) {
		int a = 5, b = 10;
		int temp;
		temp = a;
		a = b;
		b = temp;
		System.out.println("Sau khi hoán vị, a = " + a);
		System.out.println("Sau khi hoán vị, b = " + b);
	}
}
