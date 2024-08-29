import java.util.*;
import java.io.*;
 
public class Main {
	public static int[] unf;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	int V = Integer.parseInt(br.readLine()), E = Integer.parseInt(br.readLine());
    	
    	unf = new int[V];
    	for(int i = 0; i < V; i++)
    		unf[i] = i;
    	
    	PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> o1[2]-o2[2]);
    	for(int i = 0; i < E; i++) {
    		String[] line = br.readLine().split(" ");
    		pq.offer(new int[] {Integer.parseInt(line[0])-1,
    				Integer.parseInt(line[1])-1,
    				Integer.parseInt(line[2])});
    	}
    	
    	int ans = 0;
    	while(!pq.isEmpty()) {
    		int[] cur = pq.poll();
    		if(find(cur[0]) == find(cur[1])) continue;
    		
    		union(cur[0], cur[1]);
    		ans += cur[2];
    	}
    	System.out.println(ans);
    }
    
    public static void union(int a, int b) {
    	int ra = find(a);
    	int rb = find(b);
    	if(ra != rb) unf[ra] = rb;
    }
    
    public static int find(int v) {
    	if(unf[v] == v) return v;
    	return unf[v] = find(unf[v]);
    }
}
