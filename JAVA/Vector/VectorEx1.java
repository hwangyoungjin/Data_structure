package ch11;

import java.util.Vector;

public class VectorEx1 {
	public static void main(String[] args) {
			Vector v = new Vector(5); // 용량이 (Capacity) 5인 Vector를 생성
			v.add("1");
			v.add("2");
			v.add("3");
			print(v);
	
			v.trimToSize(); // 빈공간 없애기 (배열의 크기는 변경불가 )-> 새로운 객체 생성
			System.out.println("====after trimToSize=====");
			print(v);
			
			v.ensureCapacity(6); // Vector의 capacity가 최소 6이 되도록한다. 햔재 3이므로 크기6인 배열 새로운 객체 생성
			System.out.println("====after ensureCapacity=====");
			print(v);
			
			v.clear();
			System.out.println("====after clear=====");
			print(v);
	}
	
	public static void print(Vector v) {
		System.out.println(v);
		System.out.println("size : "+v.size());
		System.out.println("capacity : "+v.capacity());
	}
}
