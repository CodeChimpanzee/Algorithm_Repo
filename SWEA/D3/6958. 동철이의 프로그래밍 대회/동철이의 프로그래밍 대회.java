import java.util.Arrays;
import java.util.Scanner;

public class Solution {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int tc = 1; tc <= T; tc++) {
			int N = sc.nextInt(), M = sc.nextInt();
			int dat[] = new int[N];
			for(int i = 0; i < N; i++)
				for(int j = 0; j < M; j++)
					dat[i] += sc.nextInt();
			
			Arrays.sort(dat);
			int ptr = N-2;
			for(; ptr >= 0 && dat[ptr] == dat[N-1]; ptr--);
			System.out.println("#" + tc + " " + (N-1-ptr) + " " + dat[N-1]);
		}
	}
}
