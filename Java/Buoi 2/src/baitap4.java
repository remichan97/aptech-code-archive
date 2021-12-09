import java.io.IOException;

public class baitap4 {
	public static void main(String[] args) throws IOException  {
		char ch;
		System.out.println("Nhập một ký tự bất kỳ: ");
		ch = (char) System.in.read();
		if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') {
			switch (ch) {
			case 'a':
			case 'A':
			case 'e':
			case 'E':
			case 'i':
			case 'I':
			case 'o':
			case 'O':
			case 'u':
			case 'U':
				System.out.println("Ký tự nhập vào là nguyên âm");
				break;

			default:
				System.out.println("Ký tự nhập vào là phụ âm");
				break;
			}
		} else if (ch >= '0' && ch <= '9') {
			System.out.println("Ký tự nhập vào là ký số");
		} else {
			System.out.println("Ký tự nhập vào không có trong bảng tiếng Anh");
		}

	}
}
