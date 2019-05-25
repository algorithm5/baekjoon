package net.daehui.algorithm.problem09.theaterSeat;

import java.util.Scanner;

public class TheaterSeat {
	private int N;	// 좌석의 갯수 N
	private int M;	// VIP 좌석의 갯수 M
	private int[] VIP;	// VIP 좌석의 번호
	private int count;	// 가능한 배치도의 가짓수
	
	public TheaterSeat() {
		Scanner input = new Scanner(System.in);
		
		this.N = Integer.parseInt(input.nextLine());	// 사용자로부터 N의 값 입력
		this.M = Integer.parseInt(input.nextLine());	// 사용자로부터 M의 값 입력
		this.VIP = new int[M];
		
		for(int i = 0; i < this.VIP.length; i++) {
			this.VIP[i] = Integer.parseInt(input.nextLine());	// 사용자로부터 VIP 좌석의 번호 값 입력
		}
		
		count = 1;
		input.close();
	}
	
	public static void main(String[] args) {
		TheaterSeat theaterSeat = new TheaterSeat();
		
		theaterSeat.calCount();	// 가능한 배치도의 가짓수 계산
		theaterSeat.printCount();	// 가능한 배치도의 가짓수 출력
	}
	
	private void calCount() {	// 가능한 배치도의 가짓수 계산하는 함수
		for(int base = 1, index = 0; ; index++) {
			if(index == this.VIP.length) {
				this.count *= this.fibonacciFunc(this.N - this.VIP[index - 1]);
				break;
			}
			else {
				this.count *= this.fibonacciFunc(this.VIP[index] - base);
				base = this.VIP[index] + 1;
			}
		}
	}
	
	private int fibonacciFunc(int num) {
		int baseOne = 1;
		int baseTwo = 2;
		int current = 0;
		
		for(int i = 0; i < num; i++) {
			if(i == 0) {
				current = baseOne;
			}
			else if(i == 1) {
				current = baseTwo;
			}
			else {
				current = baseOne + baseTwo;
				baseOne = baseTwo;
				baseTwo = current;
			}
		}
		
		if(num == 0) {
			return 1;
		}
		else {
			return current;
		}
	}
	
	private void printCount() {	//	가능한 배치도의 가짓수 출력하는 함수
		System.out.println(this.count);
	}
}
