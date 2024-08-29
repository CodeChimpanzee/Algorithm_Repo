import java.util.*;

public class Main {
    static int[][] map;
    static int N, M;
    static List<int[]> clist, hlist;
    static int ans = Integer.MAX_VALUE;
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt(); M = sc.nextInt();
        map = new int[N][N];
        clist = new ArrayList<>();
        hlist = new ArrayList<>();
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++) {
            	map[i][j] = sc.nextInt();
            	if(map[i][j] == 1)
            		hlist.add(new int[] {i, j});
            	if(map[i][j] == 2)
            		clist.add(new int[] {i, j});
            }
        
        comb(0, 0, new int[M]);
        System.out.println(ans);
    }
	
	public static void comb(int k, int idx, int[] sel) {
		if(k == sel.length) {
			int tsum = 0;
			for(int i = 0; i < hlist.size(); i++) {
				int[] curHome = hlist.get(i);
				int curDist = Integer.MAX_VALUE;
				for(int j = 0; j < sel.length; j++) {
					int[] curChk = clist.get(sel[j]);
					curDist = Math.min(curDist, dist(curHome, curChk));
				}
				tsum += curDist;
			}
			ans = Math.min(ans, tsum);
			return;
		}
		if(idx == clist.size())
			return;
		
		comb(k, idx+1, sel);
		sel[k] = idx;
		comb(k+1, idx+1, sel);
	}
	
	public static int dist(int[] a, int[] b) {
		return Math.abs(a[0]-b[0]) + Math.abs(a[1]-b[1]);
	}
}
