package backjoon.graph;

import java.util.ArrayList;

public class Graph {
    private int vNum;
    private ArrayList<ArrayList<Integer>> graph;

    /**생성자에서 생성할 vertex를 받는다**/
    Graph(int vNum){
        this.vNum = vNum;
        graph = new ArrayList<>();

        /** 0번은 사용하지 X **/
        for(int i=0; i<=vNum; i++) {
            graph.add(new ArrayList<Integer>());
        }
    }

    /** Edge 연결 - 양방향 **/
    public void createEdge(int x, int y){
        graph.get(x).add(y);
        graph.get(y).add(x);
    }

    /** Graph 출력 **/
    public void printGraph(){
        /** 0번째는 사용x 이므로 1부터 **/
        for(int i=1; i<this.graph.size(); i++){
            System.out.print(i+"번째 vertex의 인접리스트 : ");
            for(int j=0; j<this.graph.get(i).size(); j++){
                System.out.print("->"+this.graph.get(i).get(j));
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        //vertex 7개
        Graph graph = new Graph(7);

        graph.createEdge(1,2);
        graph.createEdge(1,5);
        graph.createEdge(2,3);
        graph.createEdge(2,5);
        graph.createEdge(4,7);
        graph.createEdge(5,6);

        graph.printGraph();
    }
}
