package net.daehui.algorithm.problem19.tooManyTraps;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class TooManyTraps {
	private int N;
	private int M;
	private ArrayList<Integer> shoes;
	private ArrayList<Integer> blanket;
	private ArrayList<Integer> jump;
	
	public TooManyTraps() {
		this.initialization();
	}
	
	public static void main(String[] args) {
		TooManyTraps tooManyTraps = new TooManyTraps();
		
		if(tooManyTraps.calJump()) {
			tooManyTraps.printJump();
		}
		else {
			System.out.println("-1");
		}
	}
	
	private void initialization() {
		Scanner scan = new Scanner(System.in);
		String[] input = null;
		
		input = scan.nextLine().split(" ");
		this.N = Integer.parseInt(input[0]);
		this.M = Integer.parseInt(input[1]);
		
		this.shoes = new ArrayList<Integer>();
		this.blanket = new ArrayList<Integer>();
		this.jump = new ArrayList<Integer>();
		
		input = scan.nextLine().split(" ");
		for(int i = 0; i < this.N; i++) {
			this.shoes.add(Integer.parseInt(input[i]));
		}
		
		input = scan.nextLine().split(" ");
		for(int i = 0; i < this.M; i++) {
			if(i == 0) {
				this.blanket.add(Integer.parseInt(input[i]));
			}
			else {
				this.blanket.add(Integer.parseInt(input[i]) - Integer.parseInt(input[i - 1]));
			}
		}
		
		
		for(int i = 0; i < this.N; i++) {
			this.jump.add((i + 1));
		}
		
		scan.close();
	}
	
	private boolean calJump() {
		Collections.sort(this.shoes);
		Collections.sort(this.blanket);
		
		if(this.calSum(shoes) == this.calSum(blanket)) {
			return false;
		}
		
		for(int i = 0, j = 0; ; ) {
			if(this.shoes.get(i) < this.blanket.get(j)) {
				i++;
			}
			else if(this.shoes.get(i) == this.blanket.get(j)) {
				Collections.swap(this.jump, i, i + 1);
				i++;
			}
			else {
				j++;
			}
			
			if(j == this.blanket.size() - 1) {
				break;
			}
		}
		
		return true;
	}
	
	private int calSum(ArrayList<Integer> list) {
		int sum = 0;
		
		for(int i = 0; i < list.size(); i++) {
			sum += list.get(i);
		}
		
		return sum;
	}
	
	private void printJump() {
		for(int i = 0; i < this.jump.size(); i++) {
			System.out.print(this.jump.get(i) + " ");
		}
	}
}
