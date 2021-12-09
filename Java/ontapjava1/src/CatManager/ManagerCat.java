package CatManager;

import java.util.ArrayList;

public class ManagerCat {
	ArrayList<CatDetail>catList;

	public ManagerCat() {
		catList = new ArrayList<>();
	}

	public ArrayList<CatDetail> getCatList() {
		return catList;
	}

	public void setCatList(ArrayList<CatDetail> catList) {
		this.catList = catList;
	}
}
