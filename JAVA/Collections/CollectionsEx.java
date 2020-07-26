package ch11;

import java.util.ArrayList;
import java.util.List;
import static java.util.Collections.*; 

public class CollectionsEx {
	public static void main(String[] args) {
		List list = new ArrayList();
		System.out.println(list);
		
		addAll(list, 1,2,3,4,5);
		System.out.println(list);
		
		rotate(list,2); // 오른쪽으로 두칸씩 이동
		System.out.println(list);
 
		swap(list,0,2); //첫 번째와 세번쨰를 swap
		System.out.println(list);
		
		shuffle(list); // 저장된 요소의 위치를 임의로 변경
		System.out.println(list);
	
		sort(list);
		System.out.println(list);

		sort(list,reverseOrder()); // 역순 정렬 => reverse(list)와 동일
		System.out.println(list);
		
		int idx = binarySearch(list, 3); // 3이 저장된 위치의 index 반환, 없으면 -1
		System.out.println("index of 3 : " + idx );
	
		System.out.println("max = "+max(list));
		System.out.println("min = "+min(list));
		System.out.println("min = "+max(list,reverseOrder()));
		
		fill(list,9); // 모든 값 9로
		System.out.println("after fill(9) -> list \n" +list);
		
		//list와 같은 크기의 새로운 list 생성 후 2로 채운다. (결과 변경불가)
		List newList = nCopies(list.size(), 2);
		System.out.println("newList : "+newList);
		
		//공통 요소없으면 true
		System.out.println(disjoint(list, newList));
		
		
		copy(list,newList); //list의 값을 <-- newList의 값으로 copy
		System.out.println("list : "+ list);
		System.out.println("newList : "+ newList);
		
		replaceAll(list,2,1); // list의 값이 2인 요소를 모두 1로 replace
		System.out.println("list = "+ list);
	}
}
