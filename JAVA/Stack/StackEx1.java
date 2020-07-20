package ch11;

import java.util.Stack;

public class StackEx1 {
	public static Stack back = new Stack(); //현재위치는 back의 마지막 위치
	public static Stack forward = new Stack();
	
	public static void main(String[] args) {
		goURL("1.네이트");
		goURL("2.야후");
		goURL("3.네이버");
		goURL("4.다음");
		
		printStatus();
		System.out.println();
		
		goBack();
		System.out.println("=뒤로가기 버튼 누른 후 ");
		printStatus();
		System.out.println();

		goBack();
		System.out.println("=뒤로가기 버튼 누른 후 ");
		printStatus();
		System.out.println();
		
		goForward();
		System.out.println("=앞으로가기 버튼 누른 후 ");
		printStatus();
		System.out.println();
		
		goURL("young.com");
		System.out.println("=새로운 사이트로 이동 후 ");
		printStatus();
		System.out.println();
		
	}
	
	public static void goURL(String url) { // 뒤로갈때 마다 저장
		back.push(url);
		if(!forward.empty()) { // 새로 URL 들어가면 Forward 리셋
			forward.clear();
		}
	}
	public static void goForward() {
		if(!forward.empty()) {
			back.push(forward.pop());
		}
	}
	
	public static void goBack() {
		if(!back.empty()) {
			forward.push(back.pop());
		}
	}
	
	public static void printStatus() {
		System.out.println("back : " + back);
		System.out.println("forward : "+ forward);
		System.out.println("현재 화면은 '"+back.peek()+"' 입니다.");
	}
}

