import java.util.*;
 
public class Solution {
	public static int[] unf;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        
        for(int tc = 1; tc <= T; tc++) {
        	int N = sc.nextInt();
        	unf = new int[N];
        	for(int i = 0; i < N; i++)
        		unf[i] = i;
        	
        	int[][] isl = new int[N][2];
        	for(int i = 0; i < N; i++)
        		isl[i][0] = sc.nextInt();
        	for(int i = 0; i < N; i++)
        		isl[i][1] = sc.nextInt();
        	
        	PriorityQueue<long[]> pq = new PriorityQueue<>((o1, o2) -> {
        		if(o1[2] < o2[2]) return -1;
        		else if(o1[2] == o2[2]) return 0;
        		else return 1;
        	});
        	for(int i = 0; i < N; i++)
            	for(int j = 0; j < N; j++)
            		pq.offer(new long[] {i, j, distSq(isl[i], isl[j])});
        	
        	long ans = 0, cnt = 0;
        	while(!pq.isEmpty()) {
        		long[] cur = pq.poll();
        		if(find((int)cur[0]) == find((int)cur[1]))
        			continue;
        		
        		union((int)cur[0], (int)cur[1]);
        		ans += cur[2];
        		if(++cnt == N-1)
        			break;
        	}
        	System.out.println("#" + tc + " " + Math.round(sc.nextDouble() * ans));
        }
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
    
    public static long distSq(int[] i1, int[] i2) {
    	long dx = (i1[0] - i2[0]);
    	long dy = (i1[1] - i2[1]);
    	return dx * dx + dy * dy;
    }
}
