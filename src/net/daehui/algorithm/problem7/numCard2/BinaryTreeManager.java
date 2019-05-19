package net.daehui.algorithm.problem7.numCard2;

public class BinaryTreeManager {
private BinaryTreeModel root;
	
	public BinaryTreeManager() {
		this.root = new BinaryTreeModel();
	}
	
	public BinaryTreeModel insertKey(BinaryTreeModel root, int num) {
		BinaryTreeModel base = root;
		BinaryTreeModel insert = new BinaryTreeModel(num);
		
		if(base == null) {
			return insert;
		}
		else if(base.getNum() > insert.getNum()) {
			base.setLeft(insertKey(base.getLeft(), num));
			return base;
		}
		else if(base.getNum() < insert.getNum()) {
			base.setRight(insertKey(base.getRight(), num));
			return base;
		}
		else {
			return base;
		}
	}
	
	public void insertBST(int num) {
		this.root = insertKey(this.root, num);
	}
	
	public BinaryTreeModel searchBST(int num) {
		BinaryTreeModel base = this.root;
		
		while(base != null) {
			if(num < base.getNum()) {
				base = base.getLeft();
			}
			else if(num > base.getNum()) {
				base = base.getRight();
			}
			else {
				return base;
			}
		}
		
		return base;
	}
}
