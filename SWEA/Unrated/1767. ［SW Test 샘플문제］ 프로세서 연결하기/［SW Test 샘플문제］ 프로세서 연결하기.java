import java.util.Arrays;
import java.util.Scanner;

public class Solution {
	static int dr[] = {1, -1, 0, 0};
	static int dc[] = {0, 0, 1, -1};
	static int N;
	static int[][] map;
	static int cmax;
	static int cans;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for(int tc = 1; tc <= T; tc++) {
			N = sc.nextInt();
			map = new int[N][N];
			Proc[] proc = new Proc[12];
			
			cmax = Integer.MIN_VALUE;
			cans = Integer.MAX_VALUE;
			int pcnt = 0;
			for(int i = 0; i < N; i++)
				for(int j = 0; j < N; j++) {
					map[i][j] = sc.nextInt();
					if(map[i][j] == 1)
						proc[pcnt++] = new Proc(i, j);
				}
			
			proc = Arrays.copyOf(proc, pcnt);
			solve(0, 0, 0, proc);
			System.out.println("#" + tc + " " + cans);
		}
	}
	
	public static void solve(int idx, int con, int len, Proc[] proc) {
		if(cmax > con + (proc.length - idx))
			return;
		if(idx == proc.length) {
			if(con > cmax){
				cans = len;
				cmax = con;
			}
			else if(con == cmax)
				cans = Math.min(cans, len);
			return;
		}
		int r = proc[idx].r, c = proc[idx].c;
		if(r == 0 || c == 0 || r == N-1 || c == N-1)
			solve(idx + 1, con + 1, len, proc);
		
		for(int d = 0; d < 4; d++) {
			if(check(d, r, c)) {
				int l = paint(d, r, c, 1);
				solve(idx + 1, con + 1, len + l, proc);
				paint(d, r, c, 0);
			}
			else {
				solve(idx + 1, con, len, proc);
			}
		}
	}
	
	public static boolean check(int dir, int r, int c) {
		int nr = r + dr[dir], nc = c + dc[dir];
		while(!(nr < 0 || nr >= N || nc < 0 || nc >= N)) {
			if(map[nr][nc] != 0)
				return false;
			nr += dr[dir];
			nc += dc[dir];
		}
		return true;
	}	
		
	public static int paint(int dir, int r, int c, int num) {
		int nr = r + dr[dir], nc = c + dc[dir];
		int cnt = 0;
		while(!(nr < 0 || nr >= N || nc < 0 || nc >= N)) {
			map[nr][nc] = num;
			nr += dr[dir];
			nc += dc[dir];
			cnt++;
		}
		return cnt;
	}
}

class Proc{
	int r, c;
	public Proc(int r, int c) {
		this.r = r;
		this.c = c;
	}
}