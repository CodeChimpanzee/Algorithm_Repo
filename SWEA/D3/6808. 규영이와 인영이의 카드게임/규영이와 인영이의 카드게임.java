import java.util.Scanner;

public class Solution {
	static int win, lose;
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for(int tc = 1; tc <= T; tc++) {
			boolean[] num = new boolean[18];
			int[] sel = new int[9], unsel = new int[9];
			for(int i = 0; i < 9; i++) {
				sel[i] = sc.nextInt();
				num[sel[i]-1] = true;
			}
			for(int i = 0, c = 0; i < 18; i++)
				if(!num[i])
					unsel[c++] = i + 1;

			win = 0; lose = 0;
			sequence(0, new boolean[9], sel, unsel, new int[9]);
			System.out.println("#" + tc + " " + win + " " + lose);
		}
	}
	
	public static void sequence(int k, boolean[] v, int[] sel, int[] unsel, int[] seq) {
		if(k == seq.length) {
			int ssum = 0, usum = 0;
			for(int i = 0; i < seq.length; i++) {
				ssum += (sel[i] > seq[i]) ? sel[i]+seq[i] : 0;
				usum += (sel[i] < seq[i]) ? sel[i]+seq[i] : 0;
			}
			win += (ssum > usum) ? 1 : 0;
			lose += (ssum < usum) ? 1 : 0;
			return;
		}
		
		for(int i = 0; i < unsel.length; i++) {
			if(v[i]) continue;
			seq[k] = unsel[i];
			v[i] = true;
			sequence(k+1, v, sel, unsel, seq);
			v[i] = false;
		}
	}
}