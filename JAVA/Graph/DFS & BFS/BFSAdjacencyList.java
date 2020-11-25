package dataStructure;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Graph{
	private int vNumber;
	private int ENumber;
	private boolean[] visit;
	private ArrayList<ArrayList<Integer>> graph;

	Graph(int vNumber){
		this.vNumber = vNumber;
		visit = new boolean[vNumber+1];
		graph = new ArrayList<ArrayList<Integer>>();
		
		for(int i=0; i<vNumber+1; i++) {
			graph.add(new ArrayList<Integer>());
		}
	}
	
	void createEdge(int x, int y) {
		graph.get(x).add(y);
		graph.get(y).add(x);
	}
	
	public void bfs(int start) {
		/**initial*/
		//1.큐 생성
		Queue<Integer> queue = new LinkedList<Integer>();
		//2.현재 vertet 넣기
		queue.add(start);
		//3.방문 표시
		visit[start] = true;
		
		/**initial 큐가 비어있지 않았을 때까지 BFS 탐색*/
		while(!queue.isEmpty()) {
			//큐에 맨앞에 들어있는 vertex 뽑아서
			int currentV = queue.poll();
			System.out.println(currentV);
			
			//방금 뽑은 vertex의 연결된 모든 vertex w에 대해
			for(int w : graph.get(currentV)) {
				//방문 안했으면 방문표시 하고 queue에 저장
				if(visit[w] == false) {
					visit[w] = true;
					queue.add(w);
				}
			}
		}
	}
}


public class BFSAdjacencyList {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int vNumber = scan.nextInt();
		int eNumber = scan.nextInt();
		Graph graph = new Graph(vNumber);
		
		
		//edge 추가
		for(int i = 0; i<eNumber; i++) {
			int x = scan.nextInt();
			int y = scan.nextInt();
			graph.createEdge(x, y);
		}
		
		System.out.println("탐색시작");
		graph.bfs(1);
	}
}
