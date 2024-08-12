import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

public class Solution {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int[] dr = {1, -1, 0, 0};
		int[] dc = {0, 0, 1, -1};
		
		int T = sc.nextInt();
		
		for(int tc = 1; tc <= T; tc++) {
			int ans = 1;
			int N = sc.nextInt();
			int[][] map = new int[N][N];
			boolean[][] eaten = new boolean[N][N];
			for(int i = 0; i < N; i++)
				for(int j = 0; j < N; j++)
					map[i][j] = sc.nextInt();
			
			for(int day = 1; day <= 100; day++) {
				for(int i = 0; i < N; i++)
					for(int j = 0; j < N; j++)
						if(map[i][j] == day)
							eaten[i][j] = true;
				
				int piece = 0;
				int[][] flood = new int[N][N];
				for(int i = 0; i < N; i++)
					for(int j = 0; j < N; j++) {
						if(eaten[i][j]) continue;
						if(flood[i][j] != 0) continue;

						piece++;
						Queue<int[]> q = new ArrayDeque<int[]>();
						q.offer(new int[] {i, j});
						while(!q.isEmpty()) {
							int[] cur = q.poll();
							for(int d = 0; d < 4; d++) {
								int nr = cur[0] + dr[d], nc = cur[1] + dc[d];
								if(oob(nr, nc, N)) continue;
								if(eaten[nr][nc]) continue;
								if(flood[nr][nc] != 0) continue;
								
								flood[nr][nc] = piece;
								q.offer(new int[] {nr, nc});
							}
						}
					}
				
				ans = Math.max(ans, piece);
			}
			
			System.out.println("#" + tc + " " + ans);
		}
	}
	
	public static boolean oob(int r, int c, int N) {
		return (r < 0 || r >= N || c < 0 || c >= N);
	}
}