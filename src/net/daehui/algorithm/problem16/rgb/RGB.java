package net.daehui.algorithm.problem16.rgb;

import java.util.Scanner;

public class RGB {
	private int N;	// 집의 수 N
	private int[][] cost;	// 집을 칠하는 비용
	private int minCost;	// 최소 비용
	
	public RGB() {
		this.initialization();	// 초기화
	}
	
	public static void main(String[] args) {
		RGB rgb = new RGB();
		
		rgb.calMinCost();	// 최소 비용 계산
		rgb.printMinCost();	// 최소 비용 출력
	}
	
	private void initialization() {	// 초기화 하는 함수
		Scanner scan = new Scanner(System.in);
		
		this.N = Integer.parseInt(scan.nextLine());	// 사용자로부터 N의 값 입력
		this.cost = new int[this.N][3];
		
		String[] input = null;
		for(int i = 0; i < this.cost.length; i++) {	// 사용자로부터 집을 칠하는 비용값 입력
			input = scan.nextLine().split(" ");
			this.cost[i][0] = Integer.parseInt(input[0]);
			this.cost[i][1] = Integer.parseInt(input[1]);
			this.cost[i][2] = Integer.parseInt(input[2]);
		}
		
		this.minCost = 0;
		
		scan.close();
	}
	
	private void calMinCost() {	// 최소 비용 계산 하는 함수
		for(int i = 0; i < this.cost.length; i++) {
			if(i == 0) {
				int j = compareMin(this.cost[i]);	// 최솟값 비교
				this.minCost += this.cost[i][j];
				this.cost[i][j] = -1;
			}
			else {
				int j = compareMin(this.cost[i], this.cost[i - 1]);	// 최솟값 비교
				this.minCost += this.cost[i][j];
				this.cost[i][j] = -1;
			}
		}
	}
	
	private void printMinCost() {	// 최소 비용 출력하는 함수
		System.out.println(this.minCost);
	}
	
	private int compareMin(int[] house) {	// 최솟값 비교하는 함수
		int seq = 0;
		int compare = house[seq];
		
		for(int i = 1; i < house.length; i++) {
			if(compare > house[i]) {
				compare = house[i];
				seq = i;
			}
		}
		
		return seq;
	}
	
	private int compareMin(int[] house, int[] neighbor) {	// 최솟값 비교하는 함수
		int seq = 0;
		int compare;
		
		for(int i = 0; i < house.length; i++) {
			if(neighbor[i] != -1) {
				seq = i;
				break;
			}
		}
		
		compare = house[seq];
		for(int i = 0; i < house.length; i++) {
			if(neighbor[i] == -1) {
				continue;
			}
			
			if(compare > house[i]) {
				compare = house[i];
				seq = i;
			}
		}
		
		return seq;
	}
}
