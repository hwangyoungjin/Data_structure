package ch11;

import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Queue;
import java.util.Scanner;

public class QueueEx1 {
	static Queue q = new LinkedList();
	static final int MAX_SIZE = 5; // Queue에 최대 5개까지만 저장되도록 한다.
	
	public static void main(String[] args) {
		System.out.println("help를 입력하면 도움말을 볼 수 있습니다.");
		
		while(true) {
			System.out.println(">>");
			try {
				//화면으로 부터 라이단위로 입력 받는다.
				Scanner scan = new Scanner(System.in);
				String input = scan.nextLine().trim();
				if("".equals(input)) {
					continue;
				}
				if(input.equalsIgnoreCase("q")) {
					System.exit(0); //대소문자 구분 없이 q 입력하면 종료
				}
				else if(input.equalsIgnoreCase("help")) {
					System.out.println(" help - 도움말을 보여줍니다.");
					System.out.println(" q or Q  - 프로그램을 종료");
					System.out.println(" history - 최근의 입력한 명령어를 " + MAX_SIZE + "개 보여줍니다.");
				}
				else if(input.equalsIgnoreCase("history")) {
					int i=0;
					//입력받은 명령어 저장
					save(input);
					
					//LinkedList의 내용을 보여준다.
					LinkedList tmp = (LinkedList)q;
					ListIterator it = tmp.listIterator();
					while(it.hasNext()) {
						System.out.println(++i+"."+it.next());
			
					}
				}
				else {
					save(input);
					System.out.println(input);
				}
			} catch (Exception e) {
				System.out.println("입력 오류 입니다.");
			}
		}// while end
	}//main end
	
	public static void save(String input) {
		//input이 ""이 아니면 Queue 에 저장
		if(!"".equals(input)) {
			q.offer(input);
		}
		
		//Queue의 최대 크기를 넘으면 제일 처음 입력된것을 삭제
		if(q.size() > MAX_SIZE) { // size는 Collection 인터페이스에서 정의
			q.remove();
		}
	}
} // end of class