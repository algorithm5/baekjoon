package net.daehui.algorithm.problem14.treeInvestment;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class TreeInvestment {
	private int N;	// N X N 크기의 땅
	private int M;	// M개의 나무
	private int K;	// K년
	private int[][] nourishmentInit;	// S2D2가 추가하는 양분의 양
	private Tree[][] treeState;	// 현재 나무 재태크의 상태
	private int treeNum;	// 나무 갯수
	
	public TreeInvestment() {
		this.initialization();	// 초기화
	}
	
	public static void main(String[] args) {
		TreeInvestment treeInvestment = new TreeInvestment();
		
		treeInvestment.calCurrent();	// 나무 갯수 계산
		treeInvestment.printCurrent();	// 나무 갯수 출력
	}
	
	private void initialization() {	// 초기화 하는 함수
		Scanner scan = new Scanner(System.in);
		String[] input = scan.nextLine().split(" ");
		
		this.N = Integer.parseInt(input[0]);	// 사용자로부터 N의 값 입력
		this.M = Integer.parseInt(input[1]);	// 사용자로부터 M의 값 입력
		this.K = Integer.parseInt(input[2]);	// 사용자로부터 K의 값 입력
		
		this.nourishmentInit = new int[this.N][this.N];
		this.treeState = new Tree[this.N][this.N];
		
		for(int i = 0, j = 0; i < this.treeState.length; ) {
			if(j == 0) {
				input = scan.nextLine().split(" ");
				this.nourishmentInit[i][j] = Integer.parseInt(input[j]);	// 사용자로부터 S2D2가 추가하는 양분의 양 입력
				this.treeState[i][j] = new Tree();
				this.treeState[i][j].setNourishment(5);	// 초기 양분의 양 입력
				j++;
			}
			else if(j == this.treeState.length) {
				i++;
				j = 0;
			}
			else {
				this.nourishmentInit[i][j] = Integer.parseInt(input[j]);	// 사용자로부터 S2D2가 추가하는 양분의 양 입력
				this.treeState[i][j] = new Tree();
				this.treeState[i][j].setNourishment(5);	// 초기 양분의 양 입력
				j++;
			}
		}
		
		for(int i = 0; i < this.M; i++) {
			input = scan.nextLine().split(" ");
			this.treeState[Integer.parseInt(input[0]) - 1]
					[Integer.parseInt(input[1]) - 1].setTree(Integer.parseInt(input[2]));	// 사용자로부터 초기 나무 재태크 상태 입력
		}
		
		this.treeNum = 0;
		
		scan.close();
	}
	
	private void calCurrent() {	// 나무 갯수를 계산하는 함수
		for(int i = 0; i < this.K; i++) {
			this.springSummer();	// 나무들이 양분을 먹는 봄과 죽은 나무들이 양분이 되는 여름
			this.fall();	// 나무들이 번식하는 가을
			this.winter();	// S2D2가 양분을 보충하는 겨울
		}
	}
	
	private void printCurrent() {	// 나무 갯수를 출력하는 함수
		for(int i = 0, j = 0; i < this.treeState.length; ) {
			this.treeNum += this.treeState[i][j].getTree().size();
			
			if(j == this.treeState[i].length - 1) {
				i++;
				j = 0;
			}
			else {
				j++;
			}
		}
		
		System.out.println(this.treeNum);
	}
	
	private void springSummer() {	// 나무들이 양분을 먹는 봄과 죽은 나무들이 양분이 되는 여름을 수행하는 함수 
		for(int i = 0, j = 0; i < this.treeState.length; ) {
			this.treeState[i][j].feeding();
			
			if(j == this.treeState[i].length - 1) {
				i++;
				j = 0;
			}
			else {
				j++;
			}
		}
	}
	
	private void fall() {	// 나무들이 번식하는 가을을 수행하는 함수
		for(int i = 0, j = 0; i < this.treeState.length; ) {
			int breedingNum = this.treeState[i][j].canBreeding();
			
			if(i > 0 && j > 0) {
				this.treeState[i - 1][j - 1].breeding(breedingNum);
			}
			if(i > 0) {
				this.treeState[i - 1][j].breeding(breedingNum);
			}
			if(i > 0 && j < this.treeState[i].length - 1) {
				this.treeState[i - 1][j + 1].breeding(breedingNum);
			}
			if(j > 0) {
				this.treeState[i][j - 1].breeding(breedingNum);
			}
			if(j < this.treeState[i].length - 1) {
				this.treeState[i][j + 1].breeding(breedingNum);
			}
			if(i < this.treeState.length - 1 && j > 0) {
				this.treeState[i + 1][j - 1].breeding(breedingNum);
			}
			if(i < this.treeState.length - 1) {
				this.treeState[i + 1][j].breeding(breedingNum);
			}
			if(i < this.treeState.length - 1 && j < this.treeState[i].length - 1) {
				this.treeState[i + 1][j + 1].breeding(breedingNum);
			}
			
			if(j == this.treeState[i].length - 1) {
				i++;
				j = 0;
			}
			else {
				j++;
			}
		}
	}
	
	private void winter() {	// S2D2가 양분을 보충하는 겨울을 수행하는 함수
		for(int i = 0, j = 0; i < this.treeState.length; ) {
			if(j == this.treeState[i].length) {
				i++;
				j = 0;
			}
			else {
				this.treeState[i][j].setNourishment(this.nourishmentInit[i][j]);
				j++;
			}
		}
	}
}

class Tree {
	private int nourishment;
	private ArrayList<Integer> tree;
	
	public Tree() {
		this.nourishment = 0;
		this.tree = new ArrayList<Integer>();
	}
	
	public void setNourishment(int nourishment) {
		this.nourishment += nourishment;
	}
	
	public void setTree(int age) {
		this.tree.add(age);
	}
	
	public void feeding() {	// 나무들에게 양분을 주고, 죽은 나무는 양분으로 만드는 함수
		int newNourishment = 0;
		
		Collections.sort(this.tree);
		for(int i = 0; i < this.tree.size(); i++) {
			if(this.tree.get(i) <= this.nourishment) {
				this.setNourishment(-(this.tree.get(i)));
				this.tree.set(i, (this.tree.get(i) + 1));
			}
			else {
				newNourishment += (this.tree.remove(i) / 2);
				i--;
			}
		}
		
		this.setNourishment(newNourishment);
	}
	
	public int canBreeding() {	// 번식할 개체 수를 확인하는 함수
		int breedingNum = 0; 
		
		for(int i = 0; i < this.tree.size(); i++) {
			if(this.tree.get(i) % 5 == 0) {
				breedingNum++;
			}
		}
		
		return breedingNum;
	}
	
	public void breeding(int breedingNum) {	// 나무들이 번식하는 함수
		for(int i = 0; i < breedingNum; i++) {
			setTree(1);
		}
	}
	
	public ArrayList<Integer> getTree() {
		return this.tree;
	}
}
