package ch11;

import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

public class HashMapEx2 {
	public static void main(String[] args) {
		HashMap map = new HashMap();
		map.put("김자바", new Integer(90));
		map.put("김자바", new Integer(100));
		map.put("이자바", new Integer(100));
		map.put("강자바", new Integer(80));
		map.put("인자바", new Integer(90));
		
		Set set = map.entrySet();  //key와 value를 뽑기위해 entrySet을 이용하여 Collection Set으로
 		Iterator it = set.iterator();
		
		while (it.hasNext()) {
			Map.Entry e =(Map.Entry)it.next(); 
			System.out.println("이름 : "+e.getKey()+", 점수 : "+e.getValue());
		}
		
		set = map.keySet(); // key를 모아 Collection Set으로
		System.out.println("참가자 명단 : "+set);

		Collection values = map.values(); // value를 모아 Collection으로
		it = values.iterator();
		
		int total =0;
		
		while(it.hasNext()) {
			Integer i = (Integer)it.next();
			total += i.intValue();
		}
		
		System.out.println("총점 : "+total);
		System.out.println("평균 : "+(float)total/set.size());
		System.out.println("최고점수  : "+ Collections.max(values));
		System.out.println("최저점수 : "+Collections.min(values));
	}
}
