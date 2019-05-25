package net.daehui.algorithm.problem01.deque;

public class DequeManager {
	int top;
	Object[] deque;
	
	public DequeManager(int size) {
		deque = new Object[size];
		this.top = -1;
	}
	
	public void doFunction(String cmd) {
		if(cmd.equals("pop_front")) {
			this.pop_front();
		}
		else if(cmd.equals("pop_back")) {
			this.pop_back();
		}
		else if(cmd.equals("size")) {
			this.size();
		}
		else if(cmd.equals("empty")) {
			this.empty();
		}
		else if(cmd.equals("front")) {
			this.front();
		}
		else if(cmd.equals("back")) {
			this.back();
		}
		else {
			System.out.println("Wrong command");
		}
	}
	
	public void doFunction(String cmd, int num) {
		if(cmd.equals("push_front")) {
			this.push_front(num);
		}
		else if(cmd.equals("push_back")) {
			this.push_back(num);
		}
		else {
			System.out.println("Wrong command");
		}
	}
	
	private void push_front(int num) {
		if(top > deque.length) {
			System.out.println("Deque is full");
		}
		else {
			if(top == -1) {
				deque[++top] = num;
			}
			else {
				for(int i = top; i > -1; i--) {
					deque[i + 1] = deque[i];
				}
				deque[0] = num;
				top++;
			}
		}
	}
	
	private void push_back(int num) {
		if(top > deque.length) {
			System.out.println("Deque is full");
		}
		else {
			deque[++top] = num;
		}
	}
	
	private void pop_front() {
		if(top == -1) {
			System.out.println(-1);
		}
		else {
			Object popNum = deque[0];
			for(int i = 0; i < top; i++) {
				deque[i] = deque[i + 1];
			}
			deque[top] = null;
			top--;
			
			System.out.println(popNum);
		}
	}
	
	private void pop_back() {
		if(top == -1) {
			System.out.println(-1);
		}
		else {
			Object popNum = deque[top];
			deque[top--] = null;
			System.out.println(popNum);
		}
	}
	
	private void size() {
		System.out.println((top + 1));
	}
	
	private void empty() {
		if(top == -1) {
			System.out.println(1);
		}
		else {
			System.out.println(0);
		}
	}
	
	private void front() {
		if(top == -1) {
			System.out.println(-1);
		}
		else {
			System.out.println(deque[0]);
		}
	}
	
	private void back() {
		if(top == -1) {
			System.out.println(-1);
		}
		else {
			System.out.println(deque[top]);
		}
	}
}
