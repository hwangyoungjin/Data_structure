package ch11;

import java.util.ArrayList;
import java.util.Collections;

public class ArrayListEx1 {
	public static void main(String[] args) {
		ArrayList list1 = new ArrayList(10); // 10 size를 갖는 ArrayList
		list1.add(new Integer(5)); 
		list1.add(new Integer(4)); 
		list1.add(new Integer(3)); 
		list1.add(new Integer(0)); 
		list1.add(new Integer(1)); 
		list1.add(new Integer(2)); 
		
		ArrayList list2 = new ArrayList(list1.subList(1,4)); // list1의 1~4번째의 객체로 새로운 list2를 만든다
		System.out.println("list1 : "+list1+"\n"+"list2 : "+list2+"\n");
		
		Collections.sort(list1); // list1 정렬
		Collections.sort(list2); // list2 정렬
		System.out.println("list1 : "+list1+"\n"+"list2 : "+list2+"\n");
		
		list2.add("B");
		list2.add("C");		
		list2.add("A");
		System.out.println("list1 : "+list1+"\n"+"list2 : "+list2+"\n");
		list2.add(3,"A"); // index = 3 위치에 "A" 를 추가! 
		System.out.println("list1 : "+list1+"\n"+"list2 : "+list2+"\n");
		list2.set(3, "AA"); // index =3 위치의 값을 "AA"로 입력 (새로추가x)
		System.out.println("list1 : "+list1+"\n"+"list2 : "+list2+"\n");
		
		//list1에서 list2와 겹치는 부분만 남기고 나머지는 삭제
		System.out.println("list1.retainAll(list2) -> "+list1.retainAll(list2));
		System.out.println("list1 : "+list1+"\n"+"list2 : "+list2+"\n");
		
		//list2에서 list1에 포함된 객체들 삭제
		for(int i=list2.size()-1; i>=0; i--) { // list2 크기만큼 검사
			//point!! - 삭제시 앞 빈공간을 뒤에서 채우기 때문에 뒤에서부터 검사해야한다.
			
			if(list1.contains(list2.get(i))) { // list2에 list1이 포함되었는지 체크
				list2.remove(i); // 포함되어있으면 해당 index위치에 객체 삭제
			}
		}
		
		System.out.println("list1 : "+list1+"\n"+"list2 : "+list2+"\n");
		
	
	}
}
