import java.util.Scanner;

class NhanVien {
	private String ten;
	private int tuoi;
	private String diaChi;
	private double luong;
	private int gioLam;

	public NhanVien() {
	}

	public NhanVien(String ten, int tuoi, String diaChi, double luong, int gioLam) {
		this.ten = ten;
		this.tuoi = tuoi;
		this.diaChi = diaChi;
		this.luong = luong;
		this.gioLam = gioLam;
	}

	public String getTen() {
		return ten;
	}

	public void setTen(String ten) {
		this.ten = ten;
	}

	public int getTuoi() {
		return tuoi;
	}

	public void setTuoi(int tuoi) {
		this.tuoi = tuoi;
	}

	public String getDiaChi() {
		return diaChi;
	}

	public void setDiaChi(String diaChi) {
		this.diaChi = diaChi;
	}

	public double getLuong() {
		return luong;
	}

	public void setLuong(double luong) {
		this.luong = luong;
	}

	public int getGioLam() {
		return gioLam;
	}

	public void setGioLam(int gioLam) {
		this.gioLam = gioLam;
	}

	void inputInfo(Scanner input) {
		System.out.println("Nhập tên nhân viên: ");
		ten = input.nextLine();
		System.out.println("Nhập tuổi nhân viên: ");
		tuoi = input.nextInt();
		input.nextLine();
		System.out.println("Nhập địa chỉ của nhân viên: ");
		diaChi = input.nextLine();
		System.out.println("Nhập tiền lương nhân viên: ");
		luong = input.nextDouble();
		System.out.println("Nhập số giờ làm của nhân viên: ");
		gioLam = input.nextInt();
	}

	void printInfo() {
		System.out.println("Tên nhân viên: " + ten);
		System.out.println("Tuổi nhân viên: " + tuoi);
		System.out.println("Địa chỉ nhân viên: " + diaChi);
		System.out.println("Tiền lương nhân viên: " + luong);
		System.out.println("Tổng số giờ làm của nhân viên: " + gioLam);
	}

	double tinhThuong() {
		if (gioLam >= 200) {
			return luong * 0.2;
		} else if (gioLam >= 100 && gioLam < 200) {
			return luong * 0.1;
		} else {
			return 0;
		}
	}
}

public class baitap2 {
	public static void main(String[] args) {
		NhanVien nv = new NhanVien();
		String encoding = "UTF-8";
		Scanner input = new Scanner(System.in, encoding);
		nv.inputInfo(input);
		nv.printInfo();
		System.out.println("Thưởng của nhân viên là: " + nv.tinhThuong());
	}
}
