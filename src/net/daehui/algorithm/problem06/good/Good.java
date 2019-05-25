package net.daehui.algorithm.problem06.good;

import java.util.Scanner;

public class Good {
	int[] N;	// N개의 정수
	int goodCount;	// 좋은 수의 갯수
	
	@SuppressWarnings("resource")
	public Good() {
		this.N = new int[Integer.parseInt(new Scanner(System.in).nextLine())];	// 사용자로부터 N의 개수 입력
		
		String[] inputN = new Scanner(System.in).nextLine().split(" ");	// 사용자로부터 N의 값 입력
		for(int i = 0; i < inputN.length; i++) {
			this.N[i] = Integer.parseInt(inputN[i]);
		}
	}
	
	public static void main(String[] args) {
		Good good = new Good();
		BinaryTreeManager tree_of_N = new BinaryTreeManager();	// 이진 트리 생성
		
		for(int i = 0, j = i + 1; i < good.N.length - 1; ) {	// N개의 정수 중 두 수의 합을 트리에 삽입
			tree_of_N.insertBST(good.N[i] + good.N[j]);
			
			if(j == good.N.length - 1) {
				i++;
				j = i + 1;
			}
			else {
				j++;
			}
		}
		for(int i = 0; i < good.N.length; i++) {	// N개의 정수 중 좋은 수가 있는지 확인
			BinaryTreeModel temp = tree_of_N.searchBST(good.N[i]);
			
			if(temp != null) {
				good.goodCount++;
			}
		}
		
		System.out.println(good.goodCount);
	}
}
