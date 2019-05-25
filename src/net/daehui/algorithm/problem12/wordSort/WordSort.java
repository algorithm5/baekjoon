package net.daehui.algorithm.problem12.wordSort;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class WordSort {
	private int N;	// 단어의 갯수
	private ArrayList<String>[] word;	// 입력된 N개의 단어
	
	@SuppressWarnings("unchecked")
	public WordSort() {
		Scanner scan = new Scanner(System.in);
		
		this.N = Integer.parseInt(scan.nextLine());	// 사용자로부터 단어의 갯수 입력
		this.word = new ArrayList[50];
		
		for(int i = 0; i < this.word.length; i++) {
			this.word[i] = new ArrayList<String>();
		}
		
		for(int i = 0; i < this.N; i++) {
			String temp = scan.nextLine();
			
			if(!this.word[temp.length() - 1].contains(temp)) {
				this.word[temp.length() - 1].add(temp);	// 사용자로부터 N개의 단어 입력
			}
		}
		
		scan.close();	
	}
	
	public static void main(String[] args) {
		WordSort wordSort = new WordSort();
		
		for(int i = 0; i < wordSort.word.length; i++) {
			Collections.sort(wordSort.word[i]);
			wordSort.printWord(wordSort.word[i]);	// 길이가 n인 단어를 출력 
		}
	}
	
	private void printWord(ArrayList<String> word) {	// 길이가 n인 단어를 출력하는 함수
		for(int i = 0; i < word.size(); i++) {
			System.out.println(word.get(i));
		}
	}
}
