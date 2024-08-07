import java.util.List;
import java.util.Scanner;
import java.util.ArrayList;

public class Main {
	static int N;
	static int[][] sco;
	static int ans = Integer.MIN_VALUE;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		
		int[] hitter = new int[9];
		boolean[] v = new boolean[9];
		sco = new int[N][9];
		
		for(int i = 0; i < N; i++)
			for(int j = 0; j < 9; j++)
				sco[i][j] = sc.nextInt();
		
		hitter[3] = 0;
		v[0] = true;
		
		seq(0, v, hitter);
		System.out.println(ans);
	}
	
	public static void seq(int k, boolean[] v, int[] hitter) {
		if(k == 9) {
			ans = Math.max(baseball(hitter), ans);
			return;
		}
		if(k == 3) {
			seq(k+1, v, hitter);
			return;
		}
		
		for(int i = 0; i < 9; i++) {
			if(v[i]) continue;
			v[i] = true;
			hitter[k] = i;
			seq(k+1, v, hitter);
			v[i] = false;
		}
	}
	
	public static int baseball(int[] hitter) {
		int score = 0;
		int cidx = 0;
		for(int inn = 0; inn < N; inn++) {
			int outcnt = 0;
			int[] base = new int[3];
			while(outcnt < 3) {
				int cur = sco[inn][hitter[cidx]];
				if(cur == 0) {
					outcnt++;
				}
				else if(cur == 1) {
					score += base[2];
					base[2] = base[1];
					base[1] = base[0];
					base[0] = 1;
				}
				else if(cur == 2) {
					score += base[2] + base[1];
					base[2] = base[0];
					base[1] = 1;
					base[0] = 0;
				}
				else if(cur == 3) {
					score += base[2] + base[1] + base[0];
					base[2] = 1;
					base[1] = 0;
					base[0] = 0;
				}
				else if(cur == 4) {
					score += base[2] + base[1] + base[0] + 1;
					base[2] = 0;
					base[1] = 0;
					base[0] = 0;
				}
				cidx = (cidx + 1) % 9;
			}
		}
		
		return score;
	}
}