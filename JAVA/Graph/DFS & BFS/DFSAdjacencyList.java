package dataStructure;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class DFSGraph{
    private int VNumber; //정점의 개수
    private ArrayList<ArrayList<Integer>> dfsGraph; // 그래프
    private boolean[] visitArr; //정점 방문 여부 확인 배열

    public DFSGraph(int VNumber){
        this.VNumber = VNumber;
        this.dfsGraph = new ArrayList<ArrayList<Integer>>(); // 그래프 생성
        // 그래프 초기화
        // put(int x, int y) 에서 입력되는 정점의 값은 0 이상의 정수이나
        // ArrayList의 index는 0 부터 시작이므로 
        // ArrayIndexOutOfBoundsException 방지를 위해 
        // 정점을 담는 인접리스트의 size는 1을 더하여 초기화해줌
        // 즉, 입력받은 정점의 개수에 +1을 해줌
 
        // ex) initSize = 3
        // graph[0]
        // graph[1] -> 2 -> 3
        // graph[2] -> 1 -> 3 -> 4
        // graph[3] -> 1 -> 2 -> 4 -> 5
        
        for(int i=0; i<this.VNumber+1; i++){
            this.dfsGraph.add(new ArrayList<Integer>());
        }
        
        //그래프와 마찬가지로 +1 하여 초기화 
        this.visitArr = new boolean[this.VNumber+1];
    }
    
    //그래프 return
    public ArrayList<ArrayList<Integer>> getGraph(){
        return this.dfsGraph;
    }
    
    //그래프의 특정 vertex return ??
    public ArrayList<Integer> getVertex(int i){
        return this.dfsGraph.get(i);
    }
    
    //그래프 추가(양방향)
    public void put(int x, int y){
        this.dfsGraph.get(x).add(y);
        this.dfsGraph.get(y).add(x);
    }
    
    //그래프 출력
    public void printGraphToAdjList(){
    	//이때 size는 0포함 8이므로 8보다 작은 7까지만
        for(int i=1; i<this.dfsGraph.size(); i++){ 
            System.out.print("vertex" + i + "의 인접리스트 ");
            for(int j=0; j<this.dfsGraph.get(i).size(); j++){
                System.out.print("->"+this.dfsGraph.get(i).get(j));
            }
            System.out.println();
        }
    }
    
    //정점 방문 여부 확인 배열 초기화
    public void clearVisitArr(){
        for(int i=0; i<this.visitArr.length; i++){
            this.visitArr[i]=false;
        }
    }
    
    //그래프 탐색 dfs(재귀호출)
    public void dfs(int vIdx){
        //dfs()에 파라미터로 넘어온 vIdx는 방문확정한 것이므로
        //해당 배열의 해당 인덱스 값을 true 바꿔주고 값 출력
        this.visitArr[vIdx] = true;
        System.out.println(vIdx + " ");
        
        //인접리스트로 구현된 그래프에서
        //해당 index에 맞는 리스트를 가져와서 반복
        for(int i : this.dfsGraph.get(vIdx)) {
        	//해당 vertex가 연결된 리스트에서
        	//방문 하지않았으면 다시 dfs
        	if(this.visitArr[i] == false) {
        		dfs(i);
        	}
        }
    }
    
}

public class DFSAdjacencyList {

    public static void main(String[] args){
    	int VNumber = 0;    // vertex 개수
        int ENumber = 0;    // edge 개수
        
        Scanner scan = new Scanner(System.in);
        VNumber = scan.nextInt();    // vertex
        ENumber = scan.nextInt();    // edge
        
        // 입력받은 정점의 개수로 그래프 초기화
        DFSGraph dfsGraph = new DFSGraph(VNumber);
        
        // 그래프에 정점과 간선 입력
        // 입력받은 간선의 개수만큼 반복
        // ex) 정점 8, 간선 10
        dfsGraph.put(1, 2);
        dfsGraph.put(2, 3);
        dfsGraph.put(1, 5);
        dfsGraph.put(5, 2);
        dfsGraph.put(5, 6);
        dfsGraph.put(4, 7);
        
        //그래프 출력
        dfsGraph.printGraphToAdjList();
        
        
        System.out.println();
        System.out.println("정점 1부터 탐색 : ");
        dfsGraph.clearVisitArr();
        dfsGraph.dfs(1);

     }
}