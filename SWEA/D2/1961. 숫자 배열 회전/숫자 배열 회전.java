import java.util.Scanner;

public class Solution {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int tc = 1; tc <= T; tc++) {
			int N = sc.nextInt();
			int dat[][][] = new int[4][N][N];
			
			for(int i = 0; i < N * N; i++)
				dat[0][i/N][i%N] = sc.nextInt();
			
			for(int r = 1; r < 4; r++)
				for(int i = 0; i < N; i++)
					for(int j = 0; j < N; j++)
						dat[r][i][j] = dat[r-1][j][N-1-i];
			
			System.out.println("#" + tc);
			for(int i = 0; i < N; i++)
            {
				for(int r = 3; r >= 1; r--)
				{
					for(int j = 0; j < N; j++)
						System.out.print(dat[r][i][j]);
					System.out.print(" ");
				}
				System.out.println();
            }
		}
	}
}
