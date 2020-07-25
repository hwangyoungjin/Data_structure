package ch11;

import java.util.HashSet;
import java.util.Objects;
import java.util.Set;

public class HashSetEx1 {
	public static void main(String[] args) {
		Object[] objArr = {"1",new Integer(1),"2","2","3","3","4","4","4"};
		//String "1"과 Integer(1) 은 서로 다른 객체
		
		Set set = new HashSet();
		
		for(int i=0; i<objArr.length; i++) {
			set.add(objArr[i]); // HashSet에 objArr 요소 저장
		}
		System.out.println(set);	
		
		//이름과 나이가 같으면 같은 객체로 인식하도록 
		//Person의 equals 와 hashCode 오버라이딩 했다.
		set.add(new Person(10, "DAN"));
		set.add(new Person(10, "DAN"));
		System.out.println(set);	
		
		
		
		Person p = new Person(20,"son");
		int hashCode1 = p.hashCode();
		int hashCode2 = p.hashCode();
		p.age = 30;
		int hashCode3 = p.hashCode();
		
		System.out.println(hashCode1 +" , "+hashCode2+", "+hashCode3 );
	}
}

class Person{
	String name;
	int age;
	
	Person(int age,String name){
		this.name = name;
		this.age = age;
	}
	
	/*************HashSet의 add는 equals 와 hashCode 사용*****************************/
	
	public boolean equals(Object obj) {
		if(obj instanceof Person) {
			Person p1 = (Person)obj;
			return this.name.equals(p1.name) && this.age == p1.age; 
		}
		return false;
	}
	
	/*
	 * public int hashCode() { return (name+age).hashCode(); // String클래스의 hashCode
	 * 사용 } // String 으로 hash 코드 반환
	 */
	
	public int hashCode() { //  java.util.Objects 클래스의 hash()
		//()안에 클래스의 인스턴스 변수들을 넣으면 된다.
		return Objects.hash(name,age);  // 객체의 주소로 hash 코드 반환
	}
	
	public String toString() {
		return name+":"+age;
	}
	
	
}
