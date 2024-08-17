import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	static int[][] dat;
	static int[][] rec;
	static int N, M;
	static int[] dr = {1, -1, 0, 0};
	static int[] dc = {0, 0, 1, -1};
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt(); M = sc.nextInt();
		
		dat = new int[N+2][M+2];
		rec = new int[N+2][M+2];
		
		for(int i = 1; i <= N; i++) {
			String line = sc.next();
			for(int j = 1; j <= M; j++) {
				dat[i][j] = line.charAt(j-1) -'0';
				rec[i][j] = 1;
			}
		}
		
		for(int i = 1; i <= 9; i++) 
			flood(i, new boolean[N+2][M+2]);
		
		int ans = 0;
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= M; j++)
				ans += rec[i][j] - dat[i][j];
		System.out.println(ans);
	}
	
	public static void flood(int h, boolean[][] v) {
		Queue<int[]> q = new ArrayDeque<int[]>();
		q.offer(new int[] {0, 0});
		
		while(!q.isEmpty()) {
			int[] cur = q.poll();
			for(int d = 0; d < 4; d++) {
				int nr = cur[0] + dr[d], nc = cur[1] + dc[d];
				if(oob(nr, nc)) continue;
				if(v[nr][nc]) continue;
				if(dat[nr][nc] > h) continue;
				
				q.offer(new int[] {nr, nc});
				v[nr][nc] = true;
			}
		}

		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= M; j++)
				if(!v[i][j])
					rec[i][j]++;
	}
	
	public static boolean oob(int r, int c) {
		return (r < 0 || r >= N+2 || c < 0 || c >= M+2);
	}
}