package net.daehui.algorithm.problem8.startlink;

import java.util.ArrayList;
import java.util.Scanner;

public class Startlink_with_BFS {
	int[] floor;	// F, S, G, U, D
	int cntMin;	// 눌러야 하는 버튼 수의 최솟값
	
	@SuppressWarnings("resource")
	public Startlink_with_BFS() {
		String[] inputN = new Scanner(System.in).nextLine().split(" ");	// 사용자로부터 F, S, G, U, D 값 입력 
		
		this.floor = new int[5];
		for(int i = 0; i < inputN.length; i++) {
			this.floor[i] = Integer.parseInt(inputN[i]);
		}
		
		cntMin = 0;
	}
	
	public static void main(String[] args) {
		Startlink_with_BFS startlink = new Startlink_with_BFS();
		boolean[] visit = new boolean[startlink.floor[0]];	// BFS를 위한 방문된 정점 배열 선언
		ArrayList<Integer> queue = new ArrayList<>();	// BFS를 위한 Queue 선언
		
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
				startlink.printCount(++startlink.cntMin);
				System.exit(0);;
			}
			
			queue.add(upPost);
			queue.add(downPost);
			visit[upPost - 1] = true;
			visit[downPost - 1] = true;
			startlink.cntMin++;
		}
		
		System.out.println("use the stairs");
	}
	
	private int countDone(boolean[] base) {
		int count = 0;
		
		for(int i = 0; i < base.length; i++) {
			if(base[i]) {
				cntMin++;
			}
		}
		
		return count;
	}
	
	private void printCount(int num) {
		System.out.println((int)((Math.log(num) / Math.log(2)) + 1));
	}
}
