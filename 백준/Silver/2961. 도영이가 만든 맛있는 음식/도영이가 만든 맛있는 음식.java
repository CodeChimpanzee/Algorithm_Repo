import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class Main {
	static int[] bitt, sour;
	static int ans = Integer.MAX_VALUE;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		sour = new int[N];
		bitt = new int[N];
		
		for(int i = 0; i < N; i++) {
			sour[i] = sc.nextInt();
			bitt[i] = sc.nextInt();
		}
		
		subset(0, new boolean[N]);
		System.out.println(ans);
	}
	
	private static void subset(int idx, boolean[] sel) {
		if(idx == sel.length) {
			boolean flag = true;
			for(int i = 0; i < sel.length; i++)
				if(sel[i]) flag = false;
			if(flag) return;
			
			int ss = 1, bs = 0;
			for(int i = 0; i < sel.length; i++) {
				if(!sel[i]) continue;
				ss *= sour[i];
				bs += bitt[i];
			}
			
			ans = Math.min(ans, Math.abs(bs - ss));
			return;
		}
		
		sel[idx] = true;
		subset(idx+1, sel);
		sel[idx] = false;
		subset(idx+1, sel);
	}
}