import java.util.Scanner;

public class Solution {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int tc = 1; tc <= T; tc++) {
			int N = sc.nextInt(), M = sc.nextInt();
			int kernel[] = new int[N];
			int image[] = new int[M];
			int ans = Integer.MIN_VALUE;
			
			for(int i = 0; i < N; i++)
				kernel[i] = sc.nextInt();
			for(int i = 0; i < M; i++)
				image[i] = sc.nextInt();
			
			if(N > M)
			{ //Swap reference
				int temp[] = kernel;
				kernel = image;
				image = temp;
			}
			int klen = kernel.length, ilen = image.length;
			
			for(int i = 0; i <= ilen - klen; i++)
			{
				int tsum = 0;
				for(int ii = 0; ii < klen; ii++)
					tsum += kernel[ii] * image[i + ii];
				ans = Math.max(ans, tsum);
			}
			
			System.out.println("#" + tc + " " + ans);
		}
	}
}
