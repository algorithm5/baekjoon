package net.daehui.algorithm.problem8.startlink;

import java.util.Scanner;

public class Starlink_The_Other {
	int[] floor;	// F, S, G, U, D
	int cntMin;	// 눌러야 하는 버튼 수의 최솟값
	
	@SuppressWarnings("resource")
	public Starlink_The_Other() {
		String[] inputN = new Scanner(System.in).nextLine().split(" ");	// 사용자로부터 F, S, G, U, D 값 입력
		
		this.floor = new int[5];
		for(int i = 0; i < inputN.length; i++) {
			this.floor[i] = Integer.parseInt(inputN[i]);
		}
	}
	
	public static void main(String[] args) {
		Starlink_The_Other startlink = new Starlink_The_Other();
		
		if(startlink.calMin()) {
			System.out.println(startlink.cntMin);
		}
		else {
			System.out.println("use the stairs");
		}
	}
	
	private boolean calMin() {	// 눌러야 하는 버튼 수의 최솟값을 구하기 위한 함수
		int maxStairs = this.floor[0];
		int start = this.floor[1];
		int end = this.floor[2];
		int up = this.floor[3];
		int down = this.floor[4];
		int start_end = end - start;
		
		if((start_end > 0 && up == 0) || (start_end < 0 && down == 0)) {
			return false;
		}
		
		for(int i = 0, j = 0; ; ) {
			int x = i * up;
			int y = j * down + start_end;
			
			if(x == y) {
				this.cntMin = i + j;
				return true;
			}

			if(y > maxStairs) {
				i++;
				j = 0;
			}
			else if(x > maxStairs) {
				break;
			}
			else {
				j++;
			}
		}
		
		return false;
	}
}
