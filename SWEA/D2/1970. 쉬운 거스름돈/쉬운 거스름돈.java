import java.util.Arrays;
import java.util.Scanner;
import java.util.function.IntConsumer;

public class Solution {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int cost[] = {50000, 10000, 5000, 1000, 500, 100, 50, 10};

		for (int tc = 1; tc <= T; tc++) {
			int N = sc.nextInt();
			int dat[] = new int[cost.length];
			for(int i = 0; i < cost.length; i++)
			{
				dat[i] += N / cost[i];
				N -= dat[i] * cost[i];
			}
			System.out.println("#" + tc);
			Arrays.stream(dat).forEach(i -> System.out.print(i + " "));
            System.out.println();
		}
	}
}
