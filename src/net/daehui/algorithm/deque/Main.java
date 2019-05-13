package net.daehui.algorithm.deque;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int cmdNum = Integer.parseInt(new Scanner(System.in).nextLine());
		DequeManager dequeManager = new DequeManager(cmdNum);
		
		if(cmdNum < 1) {
			System.out.println("N is too small");
		}
		else if(cmdNum > 100000) {
			System.out.println("N is too big");
		}
		
		for(int i = 0; i < cmdNum; i++) {
			String[] cmd = new Scanner(System.in).nextLine().split(" ");
			
			if(cmd.length == 2) {
				dequeManager.doFunction(cmd[0], Integer.parseInt(cmd[1]));
			}
			else if(cmd.length == 1) {
				dequeManager.doFunction(cmd[0]);
			}
			else {
				System.out.println("No command");
			}
		}
	}
}
