package CatManager;

import java.util.Scanner;

public class CatDetail implements ICat{
	String loai;
	String mau;
	String noisong;
	int index;

	public CatDetail() {
	}

	public CatDetail(String loai, String mau, String noisong) {
		this.loai = loai;
		this.mau = mau;
		this.noisong = noisong;
	}

	public String getLoai() {
		return loai;
	}

	public void setLoai(String loai) {
		this.loai = loai;
	}

	public String getMau() {
		return mau;
	}

	public void setMau(String mau) {
		this.mau = mau;
	}

	public String getNoisong() {
		return noisong;
	}

	public void setNoisong(String noisong) {
		this.noisong = noisong;
	}

	public int getIndex() {
		return index;
	}

	public void setIndex(int index) {
		this.index = index;
	}

	@Override
	public void nhap(Scanner input) {
		System.out.println("Enter cat type: ");
		loai = input.nextLine();
		System.out.println("Available colour:");
		program.colourManager.listOfColour();
		System.out.println("Enter cat colour:");
		mau = input.nextLine();
		while (program.colourManager.colourID(mau) < 0) {
			System.out.println("Invalid colour! Please enter another colour:");
			mau = input.nextLine();
		}
		System.out.println("Enter cat noisong:");
		noisong = input.nextLine();
	}

	@Override
	public void hienthi() {
		System.out.println(this);
	}

	@Override
	public String toString() {
		return "CatDetail [loai=" + loai + ", mau=" + mau + ", noisong=" + noisong + "]";
	}
	
}
