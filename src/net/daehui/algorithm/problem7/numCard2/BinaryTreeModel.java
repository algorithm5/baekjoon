package net.daehui.algorithm.problem7.numCard2;

public class BinaryTreeModel {
	private BinaryTreeModel left;
	private BinaryTreeModel right;
	private int num;
	private int count;
	
	public BinaryTreeModel() {
		this.left = null;
		this.right = null;
	}
	
	public BinaryTreeModel(int num) {
		this.left = null;
		this.right = null;
		this.num = num;
		this.count = 0;
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
	
	public void setCount() {
		this.count++;
	}
	
	public int getCount() {
		return this.count;
	}
}
