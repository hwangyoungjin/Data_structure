package ch11;

import java.util.Collection;
import java.util.Comparator;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;
import java.util.Spliterator;
import java.util.function.UnaryOperator;

public class MyVector implements List{
	

	public static void main(String[] args) {
		MyVector vec = new MyVector();
		vec.add("1");
		vec.add("2");
		vec.add("3");
		vec.add("4");
		System.out.println(vec);
		vec.indexOf("3");
		vec.set(2, "9");
		System.out.println(vec);
		
	}
	
	Object[] data = null; // 객체를 담기위한 객체 배열을 선언
	int capacity = 0;
	int size=0;
	
	public MyVector(int capacity) {
		if(capacity<0) {
			throw new IllegalArgumentException("유효하지않는 값입니다. : "+capacity);
		}
		this.capacity = capacity;
		data = new Object[capacity];
	}
	
	public MyVector() {
		this(10);
	}
	
	
	//최소한의 저장공간[capacity]를 확보하는 메서드
	public void ensureCapacity(int minCapacity) {
		if(minCapacity - data.length >0) { // 현재 용량이 최소저장공간보다 작다면 
			setCapacity(minCapacity);
		}
	}
	
	@Override
	public boolean add(Object obj) {
		//새로운 객체 생성전 저장할 공간 확보
		ensureCapacity(size+1);
		data[size++] = obj;
		return true;
	}

	@Override
	public Object get(int index) {
		if(index < 0 || index >= size) {
			throw new IndexOutOfBoundsException("범위를 벗어났습니다");
		}
		return data[index];
	}
	
	@Override
	public Object remove(int index) {
		Object oldObj = null;
		if(index < 0 || index >= size) {
			throw new IndexOutOfBoundsException("범위를 벗어났습니다");
		}
		oldObj = data[index];
		
		//삭제하고자 하는 객체가 마지막 객체가 아니라면, 배열복사를 통해 빈자리를 채워줘야한다.
		if(index != size-1) {
			System.arraycopy(data, index+1, data, index, size-index-1);
		}
		
		//마지막 데이터를 null로 한다. 배열 0 부터시작이므로 마지막 요소 index는 size-1 이다
		data[size-1] = null;
		size--;
		return oldObj;
	}


	@Override
	public boolean remove(Object obj) {
		for(int i=0; i<size; i++){
			if(obj.equals(data[i])) {
				remove(i);
				return true;
			}
		}
		return false;
	}
		

	public void trimToSize() {
		setCapacity(size);
	}
	
	private void setCapacity(int capacity) {
		//크기가 동일하면 변경x
		if(this.capacity == capacity){
			return; 
		}
		Object[] tmp = new Object[capacity];
		System.arraycopy(data, 0, tmp, 0, size);
		data = tmp;
		this.capacity = capacity;
 	}
	
	@Override
	public void clear() {
		for(int i=0; i<size; i++) {
			data[i] = null;
		}
		size = 0;
	}
	
	@Override
	//저장된 모든 객체를 객체배열로 반환
	public Object[] toArray(Object[] a) {
		Object[] result = new Object[size];
		System.arraycopy(data, 0, result, 0, size);
		return result;
	}

	@Override
	public boolean isEmpty() {
		return size == 0;
	}
	
	@Override
	public int size() {
		return size;
	}
	
	public int capacity() {
		return capacity;
	}


	@Override
	public boolean contains(Object o) { 
		return indexOf(o) >= 0; // 해당 객체의 위치가 -1이면 존재X 나머진 모두 존재
	}
	
	public boolean equals(Object o) {//객체 비교
		return super.equals(o);
	}
	
	@Override // 주어진 element를 지정된 index에 저장
	public Object set(int index, Object element) {
		if (index >= size) {
		    throw new ArrayIndexOutOfBoundsException(index);
		}
        
		Object oldValue = data[index];
		data[index] = element;
		return oldValue;
	}
	
	@Override
	public void add(int index, Object element) {
		if(index >= size) { // index 번호 초과한경우
			throw new ArrayIndexOutOfBoundsException("번호 초과");
		}
		ensureCapacity(index+1); // 초과안했다면 capacity 확인
		System.arraycopy(data, index+1, data, index, size-index); //index 이후 범위 복사
		data[index] = element; 
		size++;
		
	}

	@Override // 해당 object가 존재하는 위치 반환
	public int indexOf(Object o) {
		if(o==null) {
			for(int i=0; i<size; i++) {
				if(data[i]==null) {
					return i;
				}
			}
		}
		else {
			for(int i=0; i<size; i++) {
				if(data[i].equals(o)) {
					return i;
				}
			}
		}
		return -1;
	}

	@Override //역방향부터 검사 체크
	public int lastIndexOf(Object o) {
		for(int i=size-1; i>=0; i--) {
			if(data[i].equals(o)) {
				return i;
			}
		}
		return -1;
	}
	
	public String toString() {
		String str = "[ ";
		for(int i=0; i<size; i++) {
			str += data[i];
			if(i != size -1) {
				str += ", ";
			}
		}
		str += " ]";
		return str;
	}
	
	/***********List에서 상속받고 내용추가 x 인 메소드***************/
	
	@Override
	public Iterator iterator() {
		// TODO Auto-generated method stub
		return null;
	}


	@Override
	public Object[] toArray() {
		// TODO Auto-generated method stub
		return null;
	}


	@Override
	public boolean containsAll(Collection c) {
		// TODO Auto-generated method stub
		return false;
	}


	@Override
	public boolean addAll(Collection c) {
		// TODO Auto-generated method stub
		return false;
	}


	@Override 
	public boolean addAll(int index, Collection c) {
		// TODO Auto-generated method stub
		return false;
	}


	@Override
	public boolean removeAll(Collection c) {
		// TODO Auto-generated method stub
		return false;
	}


	@Override
	public boolean retainAll(Collection c) {
		// TODO Auto-generated method stub
		return false;
	}


	@Override // jdk1.8부터 List인터페이스 에서 디폴트메서드로 추가
	public void replaceAll(UnaryOperator operator) {
		// TODO Auto-generated method stub
		List.super.replaceAll(operator);
	}


	@Override // jdk1.8부터 List인터페이스 에서 디폴트메서드로 추가
	public void sort(Comparator c) {
		// TODO Auto-generated method stub
		List.super.sort(c);
	}


	@Override
	public ListIterator listIterator() {
		// TODO Auto-generated method stub
		return null;
	}


	@Override
	public ListIterator listIterator(int index) {
		// TODO Auto-generated method stub
		return null;
	}


	@Override
	public List subList(int fromIndex, int toIndex) {
		return null;
	}


	@Override // jdk1.8부터 List인터페이스 에서 디폴트메서드로 추가
	public Spliterator spliterator() {
		// TODO Auto-generated method stub
		return List.super.spliterator();
	}
	
}
