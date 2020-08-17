package java_jungsuk3_PracticeProblem;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Iterator;

/**
 * 다음에 제시된 Student11클래스의 평균점수가 정렬기준이 되도록 하시오.
 * @author USER
 *
 */
class Student11{
	String name;
	int ban;
	int no;
	int kor, eng, math;

	Student11(String name, int ban, int no, int kor, int eng, int math) {
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

}

class Exercise11_5 {
	public static void main(String[] args) {
		ArrayList list = new ArrayList();
		
		list.add(new Student11("홍길동",1,1,100,100,100));
		list.add(new Student11("남궁성",1,2,90,70,80));
		list.add(new Student11("김자바",1,3,80,80,90));
		list.add(new Student11("이자바",1,4,70,90,70));
		list.add(new Student11("안자바",1,5,60,100,80));
		
		System.out.println("평균점수로 정렬");
		Collections.sort(list,new Comparator(){ //익명클래스
			//Student의 평균점수를 기준으로 정렬
			@Override
			public int compare(Object o1, Object o2) { //2개의 평균점수를 비교하여 결과 값 반환
				if(o1 instanceof Student11 && o2 instanceof Student11) {
					Student11 s1 = (Student11) o1;
					Student11 s2 = (Student11) o2;
					return (int) (s1.getAverage() - s2.getAverage());
				}
				return -1;
			}
		});
		
		Iterator it = list.iterator();
		
		while(it.hasNext())
			System.out.println(it.next());
		
	}
}