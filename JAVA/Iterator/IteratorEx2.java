package ch11;

import java.util.ArrayList;
import java.util.Iterator;

public class IteratorEx2 {
	public static void main(String[] args) {
		ArrayList original = new ArrayList(10);
		ArrayList copy1 = new ArrayList(10);
		ArrayList copy2 = new ArrayList(10);
		
		for(int i=0; i<10; i++) {
			original.add(i+"");
		}
		
		Iterator it = original.iterator();
		
		while(it.hasNext()) {
			copy1.add(it.next());
		}
		
		System.out.println("= original에서 copy1로 복사 = ");
		System.out.println("original : "+original);
		System.out.println("copy1 : "+copy1);
		System.out.println();
		
		it = original.iterator(); // iterator는 재사용 불가
		while(it.hasNext()) {
			copy2.add(it.next());
		}
		System.out.println("= original에서 copy2로 복사 = ");
		System.out.println("original : "+original);
		System.out.println("copy2 : "+copy1);
		
	}
}
