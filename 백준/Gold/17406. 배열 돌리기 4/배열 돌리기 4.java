import java.util.ArrayDeque;
import java.util.Scanner;

public class Main {
	static int[][] op;
	static int[][] dat;
	static int N, M, K, ans;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt(); M = sc.nextInt(); K = sc.nextInt();
		dat = new int[N][M];
		op = new int[K][3];
		
		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++)
				dat[i][j] = sc.nextInt();
		
		for(int i = 0; i < K; i++) {
			op[i][0] = sc.nextInt() - 1;
			op[i][1] = sc.nextInt() - 1;
			op[i][2] = sc.nextInt();
		}
		
		ans = Integer.MAX_VALUE;
		seq(0, new int[K], new boolean[K]);
		System.out.println(ans);
	}
	
	public static void seq(int idx, int[] sel, boolean[] v) {
		if(idx == v.length) {
			int rsum = simulate(sel);
			ans = Math.min(ans, rsum);
			return;
		}
		
		for(int i = 0; i < v.length; i++) {
			if(v[i]) continue;
			sel[idx] = i;
			v[i] = true;
			seq(idx + 1, sel, v);
			v[i] = false;
		}
	}
	
	public static int simulate(int[] sel) {
		int[] dr = {0, 1, 0, -1};
		int[] dc = {1, 0, -1, 0};

		int[][] cmap = new int[N][M];
		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++)
				cmap[i][j] = dat[i][j];
		
		for(int i = 0; i < sel.length; i++) {
			int[] cur = op[sel[i]];
			for(int s = 1; s <= cur[2]; s++) {
				int cr = cur[0] - s, cc = cur[1] - s;
				int step = s << 1;

				ArrayDeque<Integer> dq = new ArrayDeque<Integer>();
				for(int d = 0; d < 4; d++) {
					for(int k = 0; k < step; k++) {
						dq.offerLast(cmap[cr][cc]);
						cr += dr[d]; cc += dc[d];
					}
				}
				dq.offerFirst(dq.pollLast());
				cr = cur[0] - s; cc = cur[1] - s;
				for(int d = 0; d < 4; d++) {
					for(int k = 0; k < step; k++) {
						cmap[cr][cc] = dq.pollFirst();
						cr += dr[d]; cc += dc[d];
					}
				}
			}
		}
		
		int rmin = Integer.MAX_VALUE;
		for(int i = 0; i < N; i++) {
			int rsum = 0;
			for(int j = 0; j < M; j++)
				rsum += cmap[i][j];
			rmin = Math.min(rmin, rsum);
		}
		
		return rmin;
	}
}
		