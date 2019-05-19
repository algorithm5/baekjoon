package net.daehui.algorithm.problem5.makeOne;

import java.util.Scanner;

public class MakeOne {
	int number;	// 정수 N
	int cntMin;	// 연산 횟수의 최솟값
	
	@SuppressWarnings("resource")
	public MakeOne() {
		this.number = Integer.parseInt(new Scanner(System.in).nextLine());	// 사용자로부터 정수 N 입력
		
		if(this.number < 1 || this.number > 1000000) {	// 정수 N은 10^0 초과 10^6 미만
			System.out.println("N is too small or big");
			System.exit(0);
		}
		
		cntMin = 0;
	}
	
	public static void main(String[] args) {
		MakeOne makeOne = new MakeOne();
		
		makeOne.calMinCount();	// 연산 횟수의 최솟값 계산
		makeOne.printCount();	// 연산 횟수의 최솟값 출력
	}
	
	private void calMinCount() {	// 연산 횟수의 최솟값 계산하기 위한 함수
		int[] base = new int[this.number];
		
		for(int i = 0; i < base.length; i++) {
			if(i < 3) {
				base[i] = 1;
				continue;
			}
			
			int min = 0;
			
			if((i + 1) % 3 == 0) {
				min = this.isMin(min, base[2] + base[((i + 1) / 3) - 1]);
			}
			if((i + 1) % 2 == 0) {
				min = this.isMin(min, base[1] + base[((i + 1) / 2) - 1]); 
			}
			min = this.isMin(min, base[0] + base[i - 1]);
			base[i] = min;
		}
		
		this.cntMin = base[base.length - 1];
	}
	
	private int isMin(int base, int num) {	// 최솟값 비교
		if(base == 0) {
			return num;
		}
		
		if(base > num) {
			return num;
		}
		
		return base;
	}
	
	private void printCount() {	// 연산 횟수의 최솟값 출력하기 위한 함수
		System.out.println(this.cntMin);
	}
}
