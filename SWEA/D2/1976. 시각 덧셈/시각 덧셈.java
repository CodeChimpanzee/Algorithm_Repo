import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Solution {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			int H0 = sc.nextInt(), M0 = sc.nextInt();
			int H1 = sc.nextInt(), M1 = sc.nextInt();
			int c = (M0 + M1) / 60;
			System.out.println("#" + tc + " " +
					((H0 + H1 + c - 1) % 12 + 1) + " " +
					(M0 + M1) % 60);
		}
	}
}
