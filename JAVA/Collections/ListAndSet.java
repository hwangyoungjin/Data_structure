package java_jungsuk3_PracticeProblem;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Stack;
import java.util.TreeSet;

public class Exercise11_2 {
	public static void main(String[] args) {
		ArrayList list = new ArrayList();
		list.add(3);
		list.add(6);
		list.add(2);
		list.add(2);
		list.add(2);
		list.add(7);
		
		//ArrayList -> set : 중복 제거  : 3 6 2 7
		HashSet set = new HashSet(list);
		
		//Set -> TreeSet : BST : 2 3 6 7
		TreeSet tset = new TreeSet(set);

		Stack stack = new Stack();
		// 저장 순서 2->3->6->7
		stack.addAll(tset);
		
		// 출력 순서 : 7->6->3->2
		while(!stack.empty()) { //비었을때까지 뽑아내기
			System.out.println(stack.pop());
		}
	}
}
