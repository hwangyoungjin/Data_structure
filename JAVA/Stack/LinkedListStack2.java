package report3;

import java.util.Scanner;

class Node{
	private int data;
	private Node next;
	
	public Node(int data) {
		this.data = data;
		this.next = null;
	}
	public Node(int data, Node next) {
		this.data = data;
		this.next = next;
	}
	
	public int getData() {
		return this.data;
	}
	public Node getNext() {
		return this.next;
	}
	public void setNext(Node next) {
		this.next = next;
	}
}
class Stack{
	private Node top;
	
	public Stack() {
		top = null;
	}
	
	public void push(int number) {
		if(isEmpty()) { // 비어있을 경우
			top = new Node(number); //노드 생성
			
		}
		else { //하나 이상 있는경우
			//새 node만들어서 top의 node를 next로 가리키고
			Node newNode = new Node(number);
			newNode.setNext(top);
			//새 node를 다시 top이 가리킨다
			top = newNode;
		}
	}
	public Node top() {
		if(isEmpty()) { //비어있는 경우
			System.out.println("Error in push-stack is empty");
			return null;
		}
		else { //하나 이상 있는경우
			return top;
		}
	}
	public void pop() {
		if(isEmpty()) { //비어있는 경우
			System.out.println("Error in push-stack is empty");
		}
		else { //하나 이상 있는경우
			Node cur = top;
			top = top.getNext();
		}
	}
	
	public boolean isEmpty() {
		return top == null;
	}
}

public class LinkedListStack2{
	public static void main(String[] args) {
		Stack stack = new Stack();
		Scanner scan = new Scanner(System.in);
		for(int i=0; i<3; i++) {
			System.out.print("push : " );
			stack.push(scan.nextInt());
		}
		
		Node current = null;
		for(int i=0; i<4; i++) {
			System.out.print("pop : ");
			current = stack.top(); 
			if(current != null) {
				System.out.println(current.getData());
				stack.pop();
			}
		}	
	}
}
