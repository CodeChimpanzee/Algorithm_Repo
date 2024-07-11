import java.util.Arrays;
import java.util.Scanner;

public class Solution {
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for(int test_case = 1; test_case <= T; test_case++)
		{
			int N = sc.nextInt();
			int vec = 0, ans = 0;
			for(int i = 0; i < N; i++)
			{
				int com = sc.nextInt();
				if(com != 0)
				{
					int com_s = sc.nextInt();
					vec += (com == 1) ? com_s : -com_s;
					vec = Math.max(vec, 0);
				}
				ans += vec;
			}
			System.out.println("#" + test_case + " " + ans);
		}
	}
}
