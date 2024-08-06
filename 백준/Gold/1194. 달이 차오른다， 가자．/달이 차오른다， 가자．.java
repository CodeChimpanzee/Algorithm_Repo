import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), M = sc.nextInt();
		int str = -1, stc = -1;
		int ans = -1;
		
		int[] dr = {1, -1, 0, 0};
		int[] dc = {0, 0, 1, -1};
		
		char[][] map = new char[N][M];
		boolean[][][] v = new boolean[1<<6][N][M];
		
		for(int i = 0; i < N; i++) {
			String line = sc.next();
			for(int j = 0; j < M; j++) {
				map[i][j] = line.charAt(j);
				if(map[i][j] == '0') {
					str = i;
					stc = j;
				}
			}
		}
		
		Queue<int[]> q = new ArrayDeque<>();
		q.add(new int[] {str, stc, 0, 0}); // r, c, step, key
		v[0][str][stc] = true;
		L : while(!q.isEmpty()) {
			int[] cur = q.poll();
			int cr = cur[0], cc = cur[1], cstep = cur[2], ckey = cur[3];
			for(int d = 0; d < 4; d++) {
				int nr = cr + dr[d], nc = cc + dc[d];
				if(oob(nr, nc, N, M)) continue;
				if(v[ckey][nr][nc]) continue;
				if(map[nr][nc] == '#') continue;
				
				if(map[nr][nc] == '1') {
					ans = cstep + 1;
					break L;
				} else if(map[nr][nc] >= 'a' && map[nr][nc] <= 'f') {
					int nkey = ckey | (1 << (map[nr][nc] - 'a'));
					q.add(new int[] {nr, nc, cstep + 1, nkey});
					v[nkey][nr][nc] = true;
				} else if(map[nr][nc] >= 'A' && map[nr][nc] <= 'F') {
					int chk = (ckey & (1 << (map[nr][nc] - 'A')));
					if(chk > 0) { // have key
						q.add(new int[] {nr, nc, cstep + 1, ckey});
						v[ckey][nr][nc] = true;
					}
				} else { // '0' or '.'
					q.add(new int[] {nr, nc, cstep + 1, ckey});
					v[ckey][nr][nc] = true;
				}
			}
		}
		
		System.out.println(ans);
	}
	
	public static boolean oob(int r, int c, int N, int M) {
		return (r < 0 || r >= N || c < 0 || c >= M);
	}
}