import java.util.Arrays;
import java.util.Scanner;

public class Solution {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int tc = 1; tc <= T; tc++) {
			int n = sc.nextInt();
			int dat[] = new int[n];
			for(int i = 0; i < n; i++)
				dat[i] = sc.nextInt();
			Arrays.sort(dat);
			
			System.out.print("#" + tc);
			Arrays.stream(dat).forEach(i -> System.out.print(" " + i));
            System.out.println();
		}
	}
}
