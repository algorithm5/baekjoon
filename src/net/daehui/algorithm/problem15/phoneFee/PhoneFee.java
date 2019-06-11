package net.daehui.algorithm.problem15.phoneFee;

import java.util.Scanner;

public class PhoneFee {
	private int N;	// 통화 목록 갯수 N
	private int[] callList;	// 통화 목록 
	private int feeY;	// 영식 요금제 사용 요금
	private int feeM;	// 민식 요금제 사용 요금

	public PhoneFee() {
		this.initialization();	// 초기화
	}
	
	public static void main(String[] args) {
		PhoneFee phoneFee = new PhoneFee();
		
		phoneFee.calFeeY();	// 영식 요금제 사용 요금 계산
		phoneFee.calFeeM();	// 민식 요금제 사용 요금 계산
		phoneFee.printFee();	// 더 싼 요금제 및 요금 출력
	}
	
	private void initialization() {	// 초기화 하는 함수
		Scanner scan = new Scanner(System.in);
		
		this.N = Integer.parseInt(scan.nextLine());	// 사용자로부터 N의 값 입력
		this.callList = new int[this.N];
		
		String[] input = scan.nextLine().split(" ");
		for(int i = 0; i < this.callList.length; i++) {
			this.callList[i] = Integer.parseInt(input[i]);	// 사용자로부터 통화 목록 입력
		}
		
		feeY = 0;
		feeM = 0;
		
		scan.close();
	}
	
	private void calFeeY() {	// 영식 요금제 사용 요금 계산하는 함수
		for(int i = 0; i < this.callList.length; i++) {
			if(this.callList[i] != 0) {
				this.feeY += (((this.callList[i] / 30) + 1) * 10);
			}
		}
	}
	
	private void calFeeM() {	// 민식 요금제 사용 요금 계산하는 함수
		for(int i = 0; i < this.callList.length; i++) {
			if(this.callList[i] != 0) {
				this.feeM += (((this.callList[i] / 60) + 1) * 15);
			}
		}
	}
	
	private void printFee() {	// 더 싼 요금제 및 요금 출력하는 함수
		if(this.feeY < this.feeM) {
			System.out.println("Y " + this.feeY);
		}
		else if(this.feeY > this.feeM) {
			System.out.println("M " + this.feeM);
		}
		else {
			System.out.println("Y M " + this.feeY);
		}
	}
}
