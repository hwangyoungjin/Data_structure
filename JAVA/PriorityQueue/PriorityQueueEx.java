package ch11;

import java.util.PriorityQueue;
import java.util.Queue;

public class PriorityQueueEx {
	public static void main(String[] args) {
		Queue pq = new PriorityQueue();
		// 저장시 순서의 관계없이 heap 구조로 저장됨
		pq.offer(3); // pq.offer(new Integer(3)); 오토박싱
		pq.offer(1);
		pq.offer(5);
		pq.offer(2);
		pq.offer(4);
		System.out.println(pq); // pq의 내부 배열 출력
		Object obj = null;
		
		//priorityQueue의 저장된 요소를 하나씩 꺼낸다.
		while((obj=pq.poll()) != null ) { // 꺼낸 요소가 null이 아니라면
			System.out.println(obj);
		}
	}
}
