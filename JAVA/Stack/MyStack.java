package ch11;

import java.util.EmptyStackException;
import java.util.Vector;

public class MyStack extends Vector{
	public Object push(Object item) {
		addElement(item); // item 추가
		return item;
	}
	
	public Object pop() {
		Object obj = peek(); //Stack에 저장된 마지막 객체를 읽어온다.
		//만일 비어있다면 peek() 메서드가 EmptyStackException을 발생시킨다.
		
		//마지막 요소를 삭제. 배열의 index 0 부터 시작하므로 -1
		removeElement(size()-1);
		//마지막 객체 반환
		return obj;
	}
	
	public Object peek() {
		int len = size();
		if(len == 0) {
			throw new EmptyStackException();
		}
		//마지막 요소 반환
		return elementAt(len-1);
	}
	
	public boolean empty() {
		return size() == 0 ;
	}
	
	public int search(Object o) {
		int i = lastIndexOf(o); // 끝에서부터 찾기
		if(i>=0) {
			return size()-1; // 객체 찾으면  맨위에 값의 index를 계산하여 반환
		}
		//못찾으면
		return -1;
	}
	
}
