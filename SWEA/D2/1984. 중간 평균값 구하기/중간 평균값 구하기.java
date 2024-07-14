import java.util.Scanner;

public class Solution {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			int dat[] = new int[10];
			int dmin = 10001, dmax = -1;
			int ans = 0;
			for(int i = 0; i < 10; i++)
			{
				dat[i] = sc.nextInt();
				dmin = Math.min(dat[i], dmin);
				dmax = Math.max(dat[i], dmax);
				ans += dat[i];
			}
			
			System.out.println("#" + tc + " " + (Math.round((float)(ans - dmax - dmin) / 8f)));
		}
	}
}
