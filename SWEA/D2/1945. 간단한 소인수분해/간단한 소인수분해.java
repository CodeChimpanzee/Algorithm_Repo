import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Solution {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			int N = sc.nextInt();
			int pr[] = {2, 3, 5, 7, 11};
			int ans[] = new int[5];
			for(int i = 0; i < 5; i++)
				while(N % pr[i] == 0)
				{
					ans[i]++;
					N /= pr[i];
				}

			System.out.print("#" + tc);
			for(int i = 0; i < 5; i++)
				System.out.print(" " + ans[i]);
			System.out.println();
		}
	}
}
