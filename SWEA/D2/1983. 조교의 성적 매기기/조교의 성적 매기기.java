import java.util.Arrays;
import java.util.Scanner;

public class Solution {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		String score[] = {"D0", "C-", "C0", "C+", "B-", "B0", "B+", "A-", "A0", "A+"};
		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			int N = sc.nextInt(), K = sc.nextInt();
			double dat[] = new double[N];
			for(int i = 0; i < N; i++)
				dat[i] = sc.nextDouble() * 0.35 + sc.nextDouble() * 0.45 + sc.nextDouble() * 0.2;
			
			double tgt = dat[K-1];
			Arrays.sort(dat);
			for(int i = 0; i < N; i++)
				if(dat[i] == tgt)
				{
					System.out.println("#" + tc + " " + score[i / (N/10)]);
					break;
				}
		}
	}
}
