package net.daehui.algorithm.problem10.PPAP;

import java.util.Scanner;

public class PPAP {
	private String PPAP_String;	// PPAP 문자열
	
	public PPAP() {
		Scanner scan = new Scanner(System.in);
		
		this.PPAP_String = scan.nextLine();	// 사용자로부터 PPAP 문자열 입력
		
		scan.close();
	}
	
	public static void main(String[] args) {
		PPAP ppap = new PPAP();
		
		if(ppap.PPAP_String.length() <= 4) {
			if(ppap.PPAP_String.equals("P") || ppap.PPAP_String.equals("PPAP")) {
				System.out.println("PPAP");
				System.exit(0);
			}
			else {
				System.out.println("NP");
				System.exit(0);
			}
		}
		
		String base = ppap.PPAP_String.substring(2, ppap.PPAP_String.length() -2);
		
		if(base.length() % 3 != 0) {
			System.out.println("NP");
			System.exit(0);
		}
		
		for(int i = 0; ; ) {
			String temp = base.substring(i * 3, (i + 1) * 3);
			
			if(!temp.equals("APP") && !temp.equals("PAP") && !temp.equals("PPA")) {
				System.out.println("NP");
				System.exit(0);
			}
			
			if(i + 1 == base.length() / 3) {
				break;
			}
			else {
				i++;
			}
		}
		
		System.out.println("PPAP");
	}
}
