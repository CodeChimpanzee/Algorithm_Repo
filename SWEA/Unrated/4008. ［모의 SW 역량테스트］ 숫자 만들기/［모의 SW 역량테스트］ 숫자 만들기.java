import java.util.Scanner;

public class Solution {
	static int[] nums;
	static int[] ops;
	static int amax, amin;
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for (int tc = 1; tc <= T; tc++) {
			int N = sc.nextInt();
			nums = new int[N];
			ops = new int[N-1];
			
			amax = Integer.MIN_VALUE;
			amin = Integer.MAX_VALUE;

			// sorted
			int idx = 0;
			for(int i = 0; i < 4; i++) {
				int curn = sc.nextInt();
				for(int j = 0; j < curn; j++)
					ops[idx++] = i;
			}
			
			for(int i = 0; i < N; i++)
				nums[i] = sc.nextInt();
			
			seq(0, new int[N-1], new boolean[N-1]);
			System.out.println("#" + tc + " " + (amax - amin));
		}
	}
	
	public static void seq(int k, int[] sel, boolean[] v) {
		if(k == sel.length) {
			int res = nums[0];
			for(int i = 0; i < sel.length; i++) {
				switch(sel[i]) {
				case 0 :
					res += nums[i+1];
					break;
				case 1 :
					res -= nums[i+1];
					break;
				case 2 :
					res *= nums[i+1];
					break;
				case 3 :
					res /= nums[i+1];
					break;
				}
			}
			
			amax = Math.max(amax, res);
			amin = Math.min(amin, res);
			return;
		}
		
		int past = -1;
		for(int i = 0; i < ops.length; i++) {
			if(v[i]) continue;
			if(past == ops[i]) continue;
			
			v[i] = true;
			past = ops[i];
			sel[k] = ops[i];
			seq(k+1, sel, v);
			v[i] = false;
		}
	}
}
