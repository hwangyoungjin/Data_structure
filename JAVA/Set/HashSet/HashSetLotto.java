package ch11;

import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;

public class HashSetLotto {
	public static void main(String[] args) {
		
		Set set = new HashSet();
		
		
		//Set은 중복을 허용하지 않기 때문에 6번 반복해서 random값 저장
		for(int i=0; set.size()<6; i++) {
			int num = (int)(Math.random()*45+1);
			set.add(new Integer(num));
		}
		
		
		//저장되어 있는 set의 요소 값을 list로 넣고
		List list = new LinkedList(set);
		//LinkedList이므로 collection의 sort(List list)로 정렬 
		Collections.sort(list);
		System.out.println(set);
	}
}
