package net.daehui.algorithm.problem2.gcd;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int tcNum = Integer.parseInt(new Scanner(System.in).nextLine());
		
		if(tcNum < 1) {
			System.out.println("t is too small");
		}
		else if(tcNum > 100) {
			System.out.println("t is too big");
		}
		
		for(int i = 0; i < tcNum; i++) {
			GCD_Manager gcdManager = new GCD_Manager();
			
			String[] cmd = new Scanner(System.in).nextLine().split(" ");
			
			if(cmd.length < 1) {
				System.out.println("No command");
				i--;
				continue;
			}
			
			for(int j = 0; j < Integer.parseInt(cmd[0]); j++) {
				for(int k = j + 1; k < cmd.length - 1; k++) {
					gcdManager.doFunction(Integer.parseInt(cmd[j + 1]), Integer.parseInt(cmd[k + 1]));
				}
			}
			
			System.out.println(gcdManager.doFunction());
		}
	}
}
