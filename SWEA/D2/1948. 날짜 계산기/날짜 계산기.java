import java.util.Scanner;

public class Solution {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int dat[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
		for(int i = 1; i < 12; i++)
			dat[i] += dat[i-1];
		
		for (int tc = 1; tc <= T; tc++) {
			int d1 = dat[sc.nextInt() - 1] + sc.nextInt();
			int d2 = dat[sc.nextInt() - 1] + sc.nextInt();
			System.out.println("#" + tc + " " + (d2 - d1 + 1));
		}
	}
}
