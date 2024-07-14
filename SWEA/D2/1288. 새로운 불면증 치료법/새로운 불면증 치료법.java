import java.util.Arrays;
import java.util.Scanner;

public class Solution {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int tc = 1; tc <= T; tc++) {
			int n = sc.nextInt();
			int check = 0, cnt = 0;
			while(check != ((1 << 10) - 1))
			{
				int s = (++cnt) * n;
				while(s > 0)
				{
					check |= 1 << (s % 10);
					s /= 10;
				}
			}
			System.out.println("#" + tc + " " + (cnt * n));
		}
	}
}
