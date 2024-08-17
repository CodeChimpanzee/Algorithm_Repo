import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {
	static int N, M, D;
	static int ans = -1;
	static int[][] initMap;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt(); M = sc.nextInt();
		D = sc.nextInt();
		initMap = new int[N][M];
		
		for(int i = 0; i < N; i++)
			for(int j = 0; j < M; j++)
				initMap[i][j] = sc.nextInt();
		
		comb(0, 0, new int[3]);
		System.out.println(ans);
	}
	
	public static void comb(int idx, int k, int[] sel) {
		if(k == sel.length) {
			simulate(sel);
			return;
		}
		if(idx == M)
			return;

		comb(idx+1, k, sel);
		sel[k] = idx;
		comb(idx+1, k+1, sel);
	}
	
	public static void simulate(int[] sel) {
		List<Enemy> el = new ArrayList<>();
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++)
				if(initMap[i][j] == 1)
					el.add(new Enemy(i, j));
		}
		
		int[][] apos = new int[sel.length][2];
		for(int i = 0; i < sel.length; i++)
			apos[i] = new int[] {N, sel[i]};

		int sum = 0;
		for(int turn = 0; turn <= N; turn++) {
			//Mark
			for(int i = 0; i < sel.length; i++)  {
				int dmemo = D;
				Enemy target = null;
				for(int j = 0; j < el.size(); j++) {
					int[] cur = apos[i];
					Enemy cem = el.get(j);
					int cdist = mdist(cur[0], cur[1], cem.r, cem.c);
					if(cdist > dmemo) continue;
					if(cdist == dmemo)
						if(target != null && cem.c > target.c) continue;
					
					dmemo = cdist;
					target = cem;
				}
				
				if(target != null)
					target.mark = true;
			}

			//Shoot
			for(int j = 0; j < el.size(); j++) 
				if(el.get(j).mark) {
					el.remove(j--);
					sum++;
				}
			
			//Proceed
			for(int i = 0; i < sel.length; i++)
				apos[i][0]--;
			for(int j = 0; j < el.size(); j++)
				if(el.get(j).r >= apos[0][0])
					el.remove(j--);
		}
		
		ans = Math.max(ans, sum);
	}
	
	public static int mdist(int r1, int c1, int r2, int c2) {
		return Math.abs(r1 - r2) + Math.abs(c1 - c2);
	}
}
	
class Enemy {
	int r, c;
	boolean mark = false;
	public Enemy(int r, int c) {
		this.r = r;
		this.c = c;
	}
}