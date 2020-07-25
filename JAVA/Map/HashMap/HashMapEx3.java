package ch11;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

public class HashMapEx3 {
	static HashMap phoneBook = new HashMap();
	
	public static void main(String[] args) {
		addPhoneNo("친구","이자바","010-111-1111");
		addPhoneNo("친구","김자바","010-222-1111");
		addPhoneNo("친구","김자바","010-333-1111");
		addPhoneNo("회사","김대리","010-444-1111");
		addPhoneNo("회사","김대리","010-555-1111");
		addPhoneNo("회사","박대리","010-666-1111");
		addPhoneNo("회사","이과장","010-77-1111");
		addPhoneNo("세탁","010-888-1111");
		
		printList();
	}
	
	
	//group에 전화번호 추가 method
	static void addPhoneNo(String groupName, String name, String tel) {
		addGroup(groupName); // 그룹 추가
		HashMap group = (HashMap)phoneBook.get(groupName); //해당 그룹의 hashMap 반환
		group.put(tel,name); // 받은 hashMap에 이름은 중복될 수 있으니 tel을 key로 설정
	}
	
	//그룹을 추가하는 method
	static void addGroup(String groupName) {
		if(!phoneBook.containsKey(groupName)) {
			phoneBook.put(groupName, new HashMap());
		}
	}
	
	static void addPhoneNo(String name, String tel) {
		addPhoneNo("기타", name,tel);
	}
	
	//전화번호 부 전체를 출력하는 메소드
	static void printList() {
		Set set = phoneBook.entrySet();
		Iterator it = set.iterator();
		while(it.hasNext()) {
			
			Map.Entry e = (Map.Entry)it.next();
			
			//e의 value는 hashMap이고 그 hashMap의 key-value를 set으로 저장
			Set subSet = ((HashMap)e.getValue()).entrySet(); 
			Iterator subIt = subSet.iterator();
			
			System.out.println(" * " + e.getKey()+"["+subSet.size()+"]");
			
			while(subIt.hasNext()) {
				Map.Entry subE = (Map.Entry)subIt.next(); // 해당 그룹의 entry
				String telNo = (String)subE.getKey();
				String name = (String)subE.getValue();
				System.out.println(name+" "+telNo);
			}
			System.out.println();
		}
	}
}
