package ch11;

import java.util.Iterator;

public class IteratorWithMyVector2 extends MyVector implements Iterator{
	int cursor =0; // 앞에서 읽어올 요소의 위치
	int lastRet = -1; // 마지막으로 읽어 온 요소의 위치 저장 따라서 cursor보다 항상 -1 작다./
	
	public IteratorWithMyVector2(int capacity) {
		super(capacity);
	}
	public IteratorWithMyVector2() {
		this(10);
	}
	
	public String toString() {
		String tmp ="";
		Iterator it = iterator();
		for(int i=0; it.hasNext(); i++) {
			if(i!=0) {
				tmp+=", ";
			}
			tmp += it.next(); // tmp += it.next().toString();
		}
		return "[ " + tmp + " ]";
	}
	
	public Iterator iterator() { //cursor와 lastRet 초기화
		cursor = 0;
		lastRet  = -1;
		return this;
	}
	public boolean hasNext() {
		return cursor != size();
	}
	
	public Object next() {
		Object next = get(cursor);
		lastRet = cursor++;
		return next;
	}
	
	public void remove() {
		//더이상 삭제할 것이 없으면 IllegalStateException 예외발생
		if(lastRet == -1) {
			throw new IllegalStateException();
		}
		else {
			remove(lastRet); 
			cursor--; // 삭제 후 cursor 감소
			lastRet = -1; // lastRet 초기화
		}
	}
	
	public static void main(String[] args) {
		IteratorWithMyVector2 v =new IteratorWithMyVector2();
		v.add("0");
		v.add("1");
		v.add("2");
		v.add("3");
		v.add("4");
		v.add("5");
		
		System.out.println("삭제 전 : "+ v);
		Iterator it = v.iterator();
		it.next(); // 실행 시 cursor : 1 , lastRet : 0
		System.out.println(v.cursor+" , "+v.lastRet );
		it.remove(); // 실행 시 cursor : 0 , lastRet : -1
		System.out.println(v.cursor+" , "+v.lastRet );
		it.next(); // 실행 시 cursor : 1 , lastRet : 0
		System.out.println(v.cursor+" , "+v.lastRet );
		it.next(); // 실행 시 cursor : 2 , lastRet : 1
		System.out.println(v.cursor+" , "+v.lastRet );
		it.remove(); // 실행 시 cursor : 1 , lastRet : 0
		System.out.println(v.cursor+" , "+v.lastRet );
		System.out.println();
		System.out.println("삭제 후 : "+ v);
	}

}//class end

