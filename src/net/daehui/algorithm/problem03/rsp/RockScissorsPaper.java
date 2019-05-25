package net.daehui.algorithm.problem03.rsp;

import java.util.Scanner;

public class RockScissorsPaper {
	private int N;
	private int K;
	private int[][] rspTable;	// 상성 표
	private int[][] jiwoo;	// 지우의 가능한 손동작
	private String[] kyonghui;	// 경희의 손동작
	private String[] minho;	// 민호의 손동작
	
	@SuppressWarnings("resource")
	public RockScissorsPaper() {
		String[] init = new Scanner(System.in).nextLine().split(" ");	// 사용자로부터 N과 K 값 입력
		N = Integer.parseInt(init[0]);	// init으로부터 N 값 도출
		K = Integer.parseInt(init[1]);	// init으로부터 K 값 도출
		rspTable = new int[N][N];	// N 값에 따른 상성 표 rspTable 크기 선언

		makeRSP_Table();	// 상성 표 rspTable 생성
		printRSP_Table();	// 상성 표 rspTable 출력
		
		kyonghui = new Scanner(System.in).nextLine().split(" ");	// 사용자로부터 경희의 손동작 20개 입력
		minho = new Scanner(System.in).nextLine().split(" ");	// 사용자로부터 민호의 손동작 20개 입력
		makeJiwoo();	// 지우의 가능한 손동작 리스트 생성
	}
	
	public static void main(String[] args) {
		RockScissorsPaper rsp = new RockScissorsPaper();
		
		if(rsp.isWin()) {	// 지우가 모두 다른 손동작으로 이길 수 있는 경우 '1' 출력
			System.out.println(1);
		}
		else {	// 지우가 모두 다른 손동작으로 이길 수 없는 경우 '0' 출력
			System.out.println(0);
		}
	}
	
	private void makeRSP_Table() {	// 상성 표 rspTable 생성하기 위한 함수
		for(int i = 0, j = 0; i < this.N; ) {
			if(i == j) {	// 비기는 경우
				this.rspTable[i++][j] = 1;
				j = 0;
				continue;
			}
			
			if((int)(Math.random() * 2 + 1) == 1) {	// 이기는 경우와 지는 경우
				this.rspTable[i][j] = 2;
				this.rspTable[j][i] = 0;
			}
			else {
				this.rspTable[i][j] = 0;
				this.rspTable[j][i] = 2;
			}
			j++;
		}
	}
	
	private void printRSP_Table() {	// 상성 표 rspTable 출력하기 위한 함수
		for(int i = 0, j = 0; i < this.N; ) {
			System.out.print(this.rspTable[i][j++]);
			
			if(j == this.N) {
				System.out.println();
				i++;
				j = 0;
			}
			else {
				System.out.print(" ");
			}
		}
	}
	
	private void makeJiwoo() {	// 지우의 가능한 손동작 리스트 생성하기 위한 함수
		int caseNum = 1;	// (가능한 손동작 경우의 수 값) = N!
		int stack = 0;
		
		for(int i = 1; i <= this.N; i++) {
			caseNum *= i;
			stack = (i * (int)Math.pow(10, (i - 1))) + stack;
		}
		
		this.jiwoo = new int[caseNum][this.N];
		
		for(int i = 1, j = 0, k = caseNum, l = this.N, count = 0; ; ) {
			if(j == this.N) {
				if(i == caseNum) {
					break;
				}
				
				if(i % k != 0) {
					k /= l--;
				}
				else {
					if(count == 0) {
						stack = 0;
					}
					
					if(count != l + 1) {
						stack = (this.jiwoo[i - 1][this.N - count - 1]
								* (int)Math.pow(10, count)) + stack;
						this.jiwoo[i][count] = this.jiwoo[i - 1][count];
						
						count++;
					}
					else {
						j = this.N - count;
						k = caseNum;
						l = this.N;
						count = 0;
						i++;
					}
				}
			}
			else {
				this.jiwoo[i - 1][j++] = stack % 10;
				stack /= 10;
			}
		}
	}
	
	private boolean isWin() {	// 지우가 모두 다른 손동작으로 이길 수 있는 경우를 판별하기 위한 함수
		int flag = 1;
		int jiwooCaseNum = 0;
		int jiwooTop = 0;
		int kyonghuiTop = 0;
		int minhoTop = 0;
		int jiwooWin = 0;
		int kyonghuiWin = 0;
		int minhoWin = 0;
		
		while(true) {
			if(flag == 1) {	// 지우와 경희가 가위바위보를 하는 경우
				if(rspTable[this.jiwoo[jiwooCaseNum][jiwooTop] - 1]
						[Integer.parseInt(this.kyonghui[kyonghuiTop]) - 1] == 2) {
					jiwooWin++;
					flag = 3;
				}
				else {
					kyonghuiWin++;
					flag = 2;
				}
				
				jiwooTop++;
				kyonghuiTop++;
			}
			else if(flag == 2) {	// 경희와 민호가 가위바위보를 하는 경우
				if(rspTable[Integer.parseInt(this.kyonghui[kyonghuiTop]) - 1]
						[Integer.parseInt(this.minho[minhoTop]) - 1] == 2) {
					kyonghuiWin++;
					flag = 1;
				}
				else {
					minhoWin++;
					flag = 3;
				}
				
				kyonghuiTop++;
				minhoTop++;
			}
			else {	// 지우와 민호가 가위바위보를 하는 경우
				if(rspTable[this.jiwoo[jiwooCaseNum][jiwooTop] - 1]
						[Integer.parseInt(this.minho[minhoTop]) - 1] == 2) {
					jiwooWin++;
					flag = 1;
				}
				else {
					minhoWin++;
					flag = 2;
				}
				
				jiwooTop++;
				minhoTop++;
			}
			
			if(jiwooWin == this.K) {
				return true;
			}
			if(jiwooCaseNum == this.jiwoo.length - 1) {
				return false;
			}
			if(kyonghuiWin == this.K || minhoWin == this.K || jiwooTop == this.N) {
				flag = 1;
				jiwooCaseNum++;
				jiwooTop = 0;
				kyonghuiTop = 0;
				minhoTop = 0;
				jiwooWin = 0;
				kyonghuiWin = 0;
				minhoWin = 0;
			}
		}
	}
}
