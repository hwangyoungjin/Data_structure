package java_jungsuk3_PracticeProblem;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;

/**
 * 문제11-7의 Student클래스에 총점(total)과 전교등수(schoolRank)를 저장하기위한 
 * 인스턴스변수를 추가하였다. Student클래스의 기본정렬을 이름(name)이 아닌 총점(total)을 
 * 기준으로 한 내림차순으로 변경한 다음, 총점을 기준으로 각 학생의 전교등수를 
 * 계산하고 전교등수를 기준으로 오름차순 정렬하여 출력하시오.
 * @author USER
 *
 */
class Student12 implements Comparable{
	String name;
	int ban;
	int no;
	int kor;
	int eng;
	int math;
	
	int total; // 총점
	int schoolRank; // 전교등수
	
	Student12(String name, int ban, int no, int kor, int eng, int math) {
		this.name = name;
		this.ban = ban;
		this.no = no;
		this.kor = kor;
		this.eng = eng;
		this.math = math;
		
		total = kor+eng+math;
	}
	int getTotal() {
		return total;
	}
	float getAverage() {
		return (int)((getTotal()/ 3f)*10+0.5)/10f;
	}
	public String toString() {
		return name
		+","+ban
		+","+no
		+","+kor
		+","+eng
		+","+math
		+","+getTotal()
		+","+getAverage()
		+","+schoolRank // 새로추가
		;
	}
	
	@Override
	public int compareTo(Object o) {//총점기준 내림차순으로 정렬한다.
		if(o instanceof Student12) {
			Student12 st = (Student12)o;
			return st.getTotal() - this.getTotal(); //내림차순!
		}		
		return -1;
	}
} // class Student12

class Exercise11_8 {
	
	public static void calculateSchoolRank(List list) {
		Collections.sort(list); // 먼저 list를 총점기준 내림차순으로 정렬한다.
		int prevRank = -1; // 이전 전교등수
		int prevTotal = -1; // 이전 총점
		int length = list.size(); // 총 학생 수 
		/*
		(2) 아래의 로직에 맞게 코드를 작성하시오.
		1. 반복문을 이용해서 list에 저장된 Student객체를 하나씩 읽는다.
		1.1 총점(total)이 이전총점(prevTotal)과 같으면
		이전 등수(prevRank)를 등수(schoolRank)로 한다.
		1.2 총점이 서로 다르면,
		등수(schoolRank)의 값을 알맞게 계산해서 저장한다.
		이전에 동점자 였다면, 그 다음 등수는 동점자의 수를 고려해야 한다.
		(실행결과 참고)
		1.3 현재 총점과 등수를 이전총점(prevTotal)과 이전등수(prevRank)에
		저장한다.
		*/
		Student12 st = null;
		Iterator it = list.iterator();
		while(it.hasNext()) { //총점이 1등인사람부터 나온다.
			st = (Student12)it.next();
				
			if(prevRank == -1) { // 1등부터
				st.schoolRank = 1;
				prevRank = st.schoolRank;
				prevTotal = st.getTotal();
			}
			else { //2등부터
				if(st.getTotal() == prevTotal) { //동점자
					st.schoolRank = prevRank;
					prevRank++;
				}
				else {//동점자 x
					prevTotal = st.getTotal();
					prevRank++;
					st.schoolRank = prevRank;
				}
				
			}
		}//while end
	}//calculateSchoolRank
	
	public static void main(String[] args) {
		ArrayList list = new ArrayList();
		list.add(new Student12("이자바",2,1,70,90,70));
		list.add(new Student12("안자바",2,2,60,100,80));
		list.add(new Student12("홍길동",1,3,100,100,100));
		list.add(new Student12("남궁성",1,1,90,70,80));
		list.add(new Student12("김자바",1,2,80,80,90));
		
		
		calculateSchoolRank(list);
		Iterator it = list.iterator();
		while(it.hasNext())
		System.out.println(it.next());
	}
}