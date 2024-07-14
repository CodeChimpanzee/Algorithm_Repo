import java.util.Scanner;

public class Solution {
	public static boolean OOB(int x, int y, int N)
	{
		return (x < 0 || x >= N || y < 0 || y >= N);
	}
	
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		int dx[] = {1, 0, -1, 0};
		int dy[] = {0, 1, 0, -1};
		
		for (int tc = 1; tc <= T; tc++) {
			int N = sc.nextInt();
			int ans[][] = new int[N][N];
			int cnt = 1, cx = 0, cy = 0, dir = 0;
			
			while(cnt <= N * N)
			{
				ans[cy][cx] = cnt++;
						
				if(OOB(cx + dx[dir], cy + dy[dir], N) || ans[cy + dy[dir]][cx + dx[dir]] != 0)
					dir = (dir + 1) % 4;
				cx += dx[dir];
				cy += dy[dir];
			}
			
			System.out.println("#" + tc);
			for(int i = 0; i < N; i++)
			{
				for(int j = 0; j < N; j++)
					System.out.print(ans[i][j] + " ");
				System.out.println();
			}
		}
	}
}
