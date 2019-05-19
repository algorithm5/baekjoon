package net.daehui.algorithm.problem6.good;

public class BinaryTreeModel {
	private BinaryTreeModel left;
	private BinaryTreeModel right;
	private int num;
	
	public BinaryTreeModel() {
		this.left = null;
		this.right = null;
	}
	
	public BinaryTreeModel(int num) {
		this.left = null;
		this.right = null;
		this.num = num;
	}
	
	public void setLeft(BinaryTreeModel left) {
		this.left = left;
	}
	
	public BinaryTreeModel getLeft() {
		return this.left;
	}
	
	public void setRight(BinaryTreeModel right) {
		this.right = right;
	}
	
	public BinaryTreeModel getRight() {
		return this.right;
	}
	
	public int getNum() {
		return this.num;
	}
}
