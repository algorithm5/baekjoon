package net.daehui.algorithm.problem13.truck;

import java.util.ArrayList;
import java.util.Scanner;

public class Truck {
	private int n;	// 트럭의 갯수
	private int w;	// 다리의 길이
	private int L;	// 다리의 최대 하중
	private int[] trucWeight;	// 트럭 별 무게
	private int minTime;	// 모든 트럭이 다리를 건너는 최단 시간
	
	public Truck() {
		Scanner scan = new Scanner(System.in);
		String[] input;

		input = scan.nextLine().split(" ");
		this.n = Integer.parseInt(input[0]);	// 사용자로부터 트럭의 갯수 입력
		this.w = Integer.parseInt(input[1]);	// 사용자로부터 다리의 길이 입력
		this.L = Integer.parseInt(input[2]);	// 사용자로부터 다리의 최대 하중 입력
		this.trucWeight = new int[this.n];
		
		input = scan.nextLine().split(" ");
		for(int i = 0; i < this.trucWeight.length; i++) {
			this.trucWeight[i] = Integer.parseInt(input[i]);	// 사용자로부터 트럭 별 무게 입력
		}
		
		this.minTime = 0;
		
		scan.close();
	}
	
	public static void main(String[] args) {
		Truck truck = new Truck();
		
		truck.calMinTime();	// 모든 트럭이 다리를 건너는 최단 시간 계산
		truck.printMinTime();	// 모든 트럭이 다리를 건너는 최단 시간 출력
	}
	
	private void calMinTime() {	// 모든 트럭이 다리를 건너는 최단 시간 계산하는 함수
		ArrayList<TruckUnit> queue = new ArrayList<TruckUnit>();
		
		for(int i = 0; i < this.trucWeight.length; ) {
			if(this.getCurrentWeight(queue) + this.trucWeight[i] <= this.L) {	// 현재 다리를 건너는 트럭의 단위 무게 합계룰 계산
				queue.add(new TruckUnit(this.trucWeight[i++]));
				this.countCurrentTime(queue);	// 현재 다리를 건너는 트럭의 단위 시간을 카운트
			}
			else {
				this.countCurrentTime(queue);
			}
			
			if(queue.get(0).getUnitTime() == this.w) {
				queue.remove(0);
			}
		}
		
		while(!queue.isEmpty()) {
			this.countCurrentTime(queue);
			
			if(queue.get(0).getUnitTime() == this.w) {
				queue.remove(0);
			}
		}
	}
	
	private int getCurrentWeight(ArrayList<TruckUnit> current) {	// 현재 다리를 건너는 트럭의 단위 무게 합계룰 계산하는 함수
		int currentWeight = 0;
		
		for(int i = 0; i < current.size(); i++) {
			currentWeight += current.get(i).getUnitWeight();
		}
		
		return currentWeight;
	}
	
	private void countCurrentTime(ArrayList<TruckUnit> current) {	// 현재 다리를 건너는 트럭의 단위 시간을 카운트 하는 함수
		for(int i = 0; i < current.size(); i++) {
			current.get(i).countUnitTime();
		}
		
		this.minTime++;
	}
	
	private void printMinTime() {	// 모든 트럭이 다리를 건너는 최단 시간 출력하는 함수
		System.out.println(this.minTime + 1);
	}
}

class TruckUnit {	// 트럭 유닛
	private int unitWeight;
	private int unitTime;
	
	public TruckUnit(int unitWeight) {
		this.unitWeight = unitWeight;
		this.unitTime = 0;
	}
	
	public void countUnitTime() {
		this.unitTime++;
	}
	
	public int getUnitWeight() {
		return this.unitWeight;
	}
	
	public int getUnitTime() {
		return this.unitTime;
	}
}
