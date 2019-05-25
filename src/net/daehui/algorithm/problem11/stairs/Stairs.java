package net.daehui.algorithm.problem11.stairs;

import java.util.Scanner;

public class Stairs {
	private int stairsNum;	// 계단의 갯수
	private int[] stairPoints;	// 계단 별 점수
	private int maxPoints;	// 총 점수의 최댓값
	
	public Stairs() {
		Scanner scan = new Scanner(System.in);
		
		this.stairsNum = Integer.parseInt(scan.nextLine());	// 사용자로부터 계단의 갯수 입력
		this.stairPoints = new int[this.stairsNum];
		
		for(int i = 0; i < this.stairPoints.length; i++) {
			this.stairPoints[i] = Integer.parseInt(scan.nextLine());	// 사용자로부터 계단 별 점수 값 입력
		}
		
		this.maxPoints = this.stairPoints[this.stairPoints.length - 1];
		
		scan.close();
	}
	
	public static void main(String[] args) {
		Stairs stairs = new Stairs();
		
		stairs.calMaxPoints();	// 총 점수의 최댓값 계산
		stairs.printMaxPoints();	// 총 점수의 최댓값 출력
	}
	
	private void calMaxPoints() {	// 총 점수의 최댓값 계산하는 함수
		for(int i = this.stairsNum - 1, flag = 0; ; ) {
			if(i == 1 && flag == 0) {
				this.maxPoints += this.stairPoints[i - 1];
				break;
			}
			if(i == 1 && flag == 1) {
				break;
			}
			
			if(flag == 1) {
				this.maxPoints += this.stairPoints[i - 2];
				i -= 2;
				flag = 0;
			}
			
			if(this.stairPoints[i - 1] > this.stairPoints[i - 2]) {
				this.maxPoints += this.stairPoints[i - 1];
				i -= 1;
				flag += 1;
			}
			else {
				this.maxPoints += this.stairPoints[i - 2];
				i -= 2;
			}
		}
	}
	
	private void printMaxPoints() {	// 총 점수의 최댓값 출력하는 함수
		System.out.println(this.maxPoints);
	}
}
