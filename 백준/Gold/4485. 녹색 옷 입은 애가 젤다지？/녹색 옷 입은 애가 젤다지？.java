import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] dr = {1, -1, 0, 0};
		int[] dc = {0, 0, 1, -1};
		int N = sc.nextInt();
		int tc = 1;
		while(N != 0) {
			int[][] dat = new int[N][N];
			int[][] dp = new int[N][N];
			for(int i = 0; i < N; i++)
				for(int j = 0; j < N; j++) {
					dat[i][j] = sc.nextInt();
					dp[i][j] = Integer.MAX_VALUE;
				}
			
			PriorityQueue<int[]> pq = new PriorityQueue<int[]>((o1, o2) -> {
				return o1[0] - o2[0];
			});

			pq.add(new int[] {dat[0][0], 0, 0});
			dp[0][0] = dat[0][0];
			L : while(!pq.isEmpty()) {
				int[] cur = pq.poll();
				for(int k = 0; k < 4; k++) {
					int nr = cur[1] + dr[k], nc = cur[2] + dc[k];
					if(OOB(nr, nc, N)) continue;
					
					int tmp = cur[0] + dat[nr][nc];
					if(tmp < dp[nr][nc]) {
						dp[nr][nc] = tmp;
						pq.add(new int[] {tmp, nr, nc});
					}
					
					//if(nr == N-1 && nc == N-1) break L;
				}
			}
			
			System.out.println("Problem " + (tc++) + ": " + dp[N-1][N-1]);
			N = sc.nextInt();
		}
	}
	
	public static boolean OOB(int r, int c, int N) {
		return (r < 0 || r >= N || c < 0 || c >= N);
	}
}