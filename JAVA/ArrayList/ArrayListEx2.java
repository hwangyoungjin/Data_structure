package ch11;

import java.util.ArrayList;
import java.util.List;

public class ArrayListEx2 {
	public static void main(String[] args) {
		final int LIMIT = 10; // 자르고자 하는 글자의 개수
		String source = "0123456789abcdefghijABCDEFGHUJ@#$%^&*()ZZZ";
		int length = source.length();
		
		List list = new ArrayList(length/LIMIT +10); // 크기를 약간 여유있게
		
		for(int i=0; i<length; i+=LIMIT) { //LIMIT 단위로 자르기
			if(i+LIMIT < length) {
				list.add(source.substring(i, i+LIMIT)); //LIMIT 단위로 list에 추가
			}
			else {
				list.add(source.substring(i));
			}
		}
		
		for(int i=0; i<list.size(); i++) {
			System.out.println(list.get(i));
		}
	}//main
}
