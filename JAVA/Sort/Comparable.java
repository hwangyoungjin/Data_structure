package java_jungsuk3_PracticeProblem;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Iterator;

/**
 * 다음에 제시된 Student클래스가 Comparable인터페이스를 구현하도록 변경해서 이름(name)이 기본 정렬기준이 되도록 하시오.
 * 
 * @author USER
 *
 */
class Students implements Comparable{
	String name;
	int ban;
	int no;
	int kor, eng, math;

	Students(String name, int ban, int no, int kor, int eng, int math) {
		this.name = name;
		this.ban = ban;
		this.no = no;
		this.kor = kor;
		this.eng = eng;
		this.math = math;
	}

	int getTotal() {
		return kor + eng + math;
	}

	float getAverage() {
		return (int) ((getTotal() / 3f) * 10 + 0.5) / 10f;
	}

	public String toString() {
		return name + "," + ban + "," + no + "," + kor + "," + eng + "," + math + "," + getTotal() + "," + getAverage();
	}

	
	 @Override public int compareTo(Object o) { 
		 if(o instanceof Students) {
			 Students student = (Students)o; // String클래스의 compareTo()를 호출 return
			 return this.name.compareTo(student.name); // String클래스의 compareTo()를 호출 return
		 } 
		 return -1; 
	 }
}

class Exercise11_5 {
	public static void main(String[] args) {
		ArrayList list = new ArrayList();
		
		list.add(new Students("홍길동",1,1,100,100,100));
		list.add(new Students("남궁성",1,2,90,70,80));
		list.add(new Students("김자바",1,3,80,80,90));
		list.add(new Students("이자바",1,4,70,90,70));
		list.add(new Students("안자바",1,5,60,100,80));
		
		Collections.sort(list);
		Iterator it = list.iterator();
		
		while(it.hasNext())
			System.out.println(it.next());
	}
}