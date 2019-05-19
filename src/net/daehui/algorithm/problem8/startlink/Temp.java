package net.daehui.algorithm.problem8.startlink;

import java.util.ArrayList;
import java.util.Scanner;

public class Temp {
	int[] floor;
	int count;
	
	@SuppressWarnings("resource")
	public Temp() {
		String[] inputN = new Scanner(System.in).nextLine().split(" ");
		
		this.floor = new int[5];
		for(int i = 0; i < inputN.length; i++) {
			this.floor[i] = Integer.parseInt(inputN[i]);
		}
		
		count = 0;
	}
	
	public static void main(String[] args) {
		Temp startlink = new Temp();
		boolean[] visit = new boolean[startlink.floor[0]];
		ArrayList<Integer> queue = new ArrayList<>();
		
		queue.add(startlink.floor[1]);
		visit[startlink.floor[1] - 1] = true;
		
		while(startlink.countDone(visit) != startlink.floor[0]) {
			int pre = queue.remove(0);
			int upPost;
			int downPost;
			
			if(pre - startlink.floor[4] < 1) {
				upPost = pre + startlink.floor[3];
				downPost = pre;
			}
			else if(pre + startlink.floor[3] > startlink.floor[0]) {
				upPost = pre;
				downPost = pre - startlink.floor[4];
			}
			else {
				upPost = pre + startlink.floor[3];
				downPost = pre - startlink.floor[4];
			}
			
			if(upPost == startlink.floor[2] || downPost == startlink.floor[2]) {
				startlink.printCount(startlink.count);
				System.exit(0);;
			}
			
			queue.add(upPost);
			queue.add(downPost);
			visit[upPost - 1] = true;
			visit[downPost - 1] = true;
			startlink.count++;
		}
		
		System.out.println("use the stairs");
	}
	
	private int countDone(boolean[] base) {
		int count = 0;
		
		for(int i = 0; i < base.length; i++) {
			if(base[i]) {
				count++;
			}
		}
		
		return count;
	}
	
	private void printCount(int num) {
		System.out.println((int)((Math.log(num) / Math.log(2)) + 1));
	}
}
