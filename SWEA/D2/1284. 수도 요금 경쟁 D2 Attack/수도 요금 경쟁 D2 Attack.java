import java.util.Arrays;
import java.util.Scanner;

public class Solution {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int tc = 1; tc <= T; tc++) {
			int P = sc.nextInt(), Q = sc.nextInt(), R = sc.nextInt(),
				S = sc.nextInt(), W = sc.nextInt();
			int A = P * W, B = (W <= R ? Q : Q + (W - R) * S);
			System.out.println("#" + tc + " " + (A < B ? A : B));
		}
	}
}
