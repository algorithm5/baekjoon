package net.daehui.algorithm.problem04.password;

import java.util.Scanner;

public class PasswordCode_Integer {
	int password;	// 암호
	int wordNum;	// 나올 수 있는 해석의 가짓수
	
	@SuppressWarnings("resource")
	public PasswordCode_Integer() {
		try {
			String input = new Scanner(System.in).nextLine();	// 사용자로부터 암호 입력
			
			if(input.substring(0, 1).equals("0")) {	// 암호는 '0'으로 시작 불가
				System.out.println("0");
				System.exit(0);
			}
			
			password = Integer.parseInt(input);
			
			wordNum = 0;
		} catch(Exception error) {	// 암호를 해석할 수 없는 경우
			System.out.println("0");
			System.exit(0);
		}
	}
	
	public static void main(String[] args) {
		PasswordCode_Integer pwCode = new PasswordCode_Integer();
		
		pwCode.calWordNum();	// 나올 수 있는 해석의 가짓수 계산
		pwCode.printWordNum();	// 나올 수 있는 해석의 가짓수 출력
	}
	
	private void calWordNum() {	// 나올 수 있는 해석의 가짓수 계산하기 위한 함수
		int passwordNum = 0;
		
		for(int i = this.password; i % 10 != 0; i /= 10) {
			passwordNum++;
			
			if(passwordNum == 1) {
				this.wordNum++;
			}
			if(i > 10 && i % 100 <= 26) {
				this.wordNum++;
			}
		}
		
		int[][] base = new int[((passwordNum - 1) * (passwordNum - 2) / 2)
		                       - (passwordNum - 2)][2];
		
		if(passwordNum > 3) {
			for(int i = 0, j = this.password, k = j / 100,
					front = passwordNum - 1, back = front - 2; i < base.length; ) {
				if(k % 100 <= 26 && j % 100 <= 26) {
					base[i][1] = back;
					base[i][0] = front;
					this.wordNum++;
				}
				
				if(k > 100) {
					k /= 10;
					back--;
				}
				else {
					j /= 10;
					k = j / 100;
					front--;
					back = front - 2;
				}
				
				i++;
			}
		}
		
		if(passwordNum > 5) {
			for(int i = 0, j = i, k = j + 1; i < base.length - 1; ) {
				if(base[j][1] == base[k][0]) {
					this.wordNum++;
					j = k;
					k = j + 1;
				}
				else {
					k++;
				}
				
				if(j == base.length || k == base.length) {
					i++;
					j = i;
					k = j + 1;
				}
			}
		}
	}
	
	private void printWordNum() {	// 나올 수 있는 해석의 가짓수 출력하기 위한 함수
		System.out.println((this.wordNum % 1000000));
	}
}