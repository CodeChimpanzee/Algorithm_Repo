import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Solution {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			int N = sc.nextInt(), K = sc.nextInt();
			StringBuilder row[] = new StringBuilder[2*N]; 
			StringBuilder tgt = new StringBuilder();

			for(int i = 0; i < 2*N; i++)
				row[i] = new StringBuilder();
			
			for(int i = 0; i < K; i++)
				tgt.append("1");
			
			for(int i = 0; i < N; i++)
			{
				for(int j = 0; j < N; j++)
				{
					String t = sc.next();
					row[i].append(t);
					row[N + j].append(t);
				}
			}

			int ans = 0;
			for(int i = 0; i < 2*N; i++)
			{
				StringTokenizer tok = new StringTokenizer(row[i].toString(), "0");
				while(tok.hasMoreTokens())
					if(tok.nextToken().equals(tgt.toString()))
						ans++;
			}
			
			System.out.println("#" + tc + " " + ans);
		}
	}
}
