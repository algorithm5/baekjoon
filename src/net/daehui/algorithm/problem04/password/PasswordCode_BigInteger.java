package net.daehui.algorithm.problem04.password;

import java.math.BigInteger;
import java.util.Scanner;

public class PasswordCode_BigInteger {
	BigInteger password;	// 암호
	BigInteger wordNum;	// 나올 수 있는 해석의 가짓수
	
	@SuppressWarnings("resource")
	public PasswordCode_BigInteger() {
		try {
			String input = new Scanner(System.in).nextLine();	// 사용자로부터 암호 입력
			
			if(input.substring(0, 1).equals("0")) {	// 암호는 '0'으로 시작 불가
				System.out.println("0");
				System.exit(0);
			}
			
			password = new BigInteger(input);
			
			wordNum = BigInteger.ZERO;
		} catch(Exception error) {	// 암호를 해석할 수 없는 경우
			System.out.println("0");
			System.exit(0);
		}
	}
	
	public static void main(String[] args) {
		PasswordCode_BigInteger pwCode = new PasswordCode_BigInteger();
		
		pwCode.calWordNum();	// 나올 수 있는 해석의 가짓수 계산
		pwCode.printWordNum();	// 나올 수 있는 해석의 가짓수 출력
	}
	
	private void calWordNum() {	// 나올 수 있는 해석의 가짓수 계산하기 위한 함수
		int passwordNum = 0;
		
		for(BigInteger i = this.password;
				i.mod(BigInteger.TEN).compareTo(BigInteger.ZERO) > 0;
				i = i.divide(BigInteger.TEN)) {
			passwordNum++;
			
			if(passwordNum == 1) {
				this.wordNum = this.wordNum.add(BigInteger.ONE);
			}
			if(i.compareTo(BigInteger.TEN) == 1
					&& i.mod(BigInteger.valueOf(100)).compareTo(BigInteger.valueOf(26)) < 1) {
				this.wordNum = this.wordNum.add(BigInteger.ONE);
			}
		}
		
		int[][] base = new int[((passwordNum - 1) * (passwordNum - 2) / 2)
		                       - (passwordNum - 2)][2];
		
		if(passwordNum > 3) {
			for(BigInteger i = BigInteger.ZERO, j = this.password,
					k = j.divide(BigInteger.valueOf(100)),
					front = BigInteger.valueOf(passwordNum - 1),
					back = front.subtract(BigInteger.valueOf(2));
					i.compareTo(BigInteger.valueOf(base.length)) < 0; ) {
				if(k.mod(BigInteger.valueOf(100)).compareTo(BigInteger.valueOf(26)) < 1
						&& j.mod(BigInteger.valueOf(100)).compareTo(BigInteger.valueOf(26)) < 1) {
					base[i.intValue()][1] = back.intValue();
					base[i.intValue()][0] = front.intValue();
					this.wordNum = this.wordNum.add(BigInteger.ONE);
				}
				
				if(k.compareTo(BigInteger.valueOf(100)) > 0) {
					k = k.divide(BigInteger.TEN);
					back = back.subtract(BigInteger.ONE);
				}
				else {
					j = j.divide(BigInteger.TEN);
					k = j.divide(BigInteger.valueOf(100));
					front = front.subtract(BigInteger.ONE);
					back = front.subtract(BigInteger.valueOf(2));
				}
				
				i = i.add(BigInteger.ONE);
			}
		}
		
		if(passwordNum > 5) {
			for(int i = 0, j = i, k = j + 1; i < base.length - 1; ) {
				if(base[j][1] == base[k][0]) {
					this.wordNum = this.wordNum.add(BigInteger.ONE);
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
		System.out.println(this.wordNum.mod(BigInteger.valueOf(1000000)));
	}
}
