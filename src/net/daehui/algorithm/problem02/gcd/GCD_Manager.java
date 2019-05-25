package net.daehui.algorithm.problem02.gcd;

public class GCD_Manager {
	int accGCD;
	
	public GCD_Manager() {
		this.accGCD = 0;
	}
	
	public void doFunction(int pre, int post) {
		accGCD(findGCD(pre, post));
	}
	
	public int doFunction() {
		return this.accGCD;
	}
	
	private int findGCD(int pre, int post) {
		int smallOne;
		if(pre < post) {
			smallOne = pre;
		}
		else {
			smallOne = post;
		}
		
		int gcd = 0;
		for(int i = 1; i <= smallOne; i++) {
			if(((pre % i) == 0) && ((post % i) == 0)) {
				gcd = i;
			}
		}
		
		return gcd;
	}
	
	private void accGCD(int gcd) {
		accGCD += gcd;
	}
}
