package net.daehui.algorithm.problem07.numCard2;

import java.util.Scanner;

public class NumberCard {
	int[] cardN;	// N개의 카드
	int[] cardM;	// M개의 카드
	
	@SuppressWarnings("resource")
	public NumberCard() {
		cardN = new int[Integer.parseInt(new Scanner(System.in).nextLine())];	// 사용자로부터 N의 개수 입력
		
		String[] inputN = new Scanner(System.in).nextLine().split(" ");	// 사용자로부터 N의 값 입력
		for(int i = 0; i < inputN.length; i++) {
			cardN[i] = Integer.parseInt(inputN[i]);
		}
		
		cardM = new int[Integer.parseInt(new Scanner(System.in).nextLine())];	// 사용자로부터 M의 개수 입력
		
		String[] inputM = new Scanner(System.in).nextLine().split(" ");	// 사용자로부터 M의 값 입력
		for(int i = 0; i < inputM.length; i++) {
			cardM[i] = Integer.parseInt(inputM[i]);
		}
	}
	
	public static void main(String[] args) {
		NumberCard numberCard = new NumberCard();
		BinaryTreeManager tree_of_M = new BinaryTreeManager();	// 이진 트리 생성
		
		for(int i = 0; i < numberCard.cardM.length; i++) {
			tree_of_M.insertBST(numberCard.cardM[i]);	// M개의 카드를 이진 트리에 삽입
		}
		for(int i = 0; i < numberCard.cardN.length; i++) {
			BinaryTreeModel temp = tree_of_M.searchBST(numberCard.cardN[i]);
			
			if(temp != null) {
				temp.setCount();
			}
		}
		for(int i = 0; i < numberCard.cardM.length; i++) {
			System.out.print(tree_of_M.searchBST(numberCard.cardM[i]).getCount() + " ");
		}
	}
}
