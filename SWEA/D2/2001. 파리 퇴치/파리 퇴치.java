import java.util.Scanner;

public class Solution {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			int N = sc.nextInt(), M = sc.nextInt();
			int dat[][] = new int[N][N];
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					dat[i][j] = sc.nextInt();

			int ans = -1;
			for (int i = 0; i < N - M + 1; i++)
				for (int j = 0; j < N - M + 1; j++) {
					int tsum = 0;
					for (int ii = i; ii < i + M; ii++)
						for (int jj = j; jj < j + M; jj++)
							tsum += dat[ii][jj];
					ans = Math.max(ans, tsum);
				}

			System.out.println("#" + tc + " " + ans);
		}
	}
}
