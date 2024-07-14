import java.util.Scanner;

public class Solution {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			int N = sc.nextInt(), len = 0;
			StringBuilder ans = new StringBuilder();
			for(int i = 0; i < N; i++)
			{
				String alpha = sc.next();
				int k = sc.nextInt();
				for(int j = 0; j < k; j++)
				{
					ans.append(alpha);
					if(++len % 10 == 0)
						ans.append('\n');
				}
			}
			System.out.println("#" + tc);
			System.out.println(ans.toString());
		}
	}
}
