import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for(int tc = 1; tc <= 10; tc++) {
			int n = sc.nextInt(), st = sc.nextInt();
			boolean[] v = new boolean[101];
			List<Integer>[] graph = new ArrayList[101];
			for(int i = 0; i <= 100; i++) {
				graph[i] = new ArrayList<Integer>();
			}
			
			for(int i = 0; i < n; i+=2) {
				int from = sc.nextInt(), to = sc.nextInt();
				graph[from].add(to);
			}
			
			int ans = -1, last_ans = -1;
			int step = 0;
			Queue<Integer> q = new ArrayDeque<>();
			q.offer(st);
			v[st] = true;
			
			while(!q.isEmpty()) {
				last_ans = ans;
				ans = -1;
				int slim = q.size();
				for(int s = 0; s < slim; s++) {
					int cur = q.poll();
					for(int i = 0; i < graph[cur].size(); i++) {
						int nxt = graph[cur].get(i);
						if(v[nxt]) continue;
						
						q.offer(nxt);
						v[nxt] = true;
						ans = Math.max(ans, nxt);
					}
				}
				step++;
			}
			
			System.out.println("#" + tc + " " + last_ans);
		}
	}
}