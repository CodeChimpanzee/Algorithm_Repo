import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Solution {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		
		for(int tc = 1; tc <= T; tc++) {
			int N = Integer.parseInt(br.readLine());
			int[][] coord = new int[N*N + 1][2];
			for(int i = 0; i < N; i++) {
				String[] line = br.readLine().split(" ");
				for(int j = 0; j < line.length; j++) {
					int num = Integer.parseInt(line[j]);
					coord[num][0] = i;
					coord[num][1] = j;
				}
			}
			
			int max_num = 1;
			int max_len = 1;
			L : for(int i = 1; i < N * N; i++) {
				int cur = i;
				int cur_len = 1;
				while(prox(coord[i], coord[i + 1])) {
					cur_len++;
					if(++i >= N * N)
						break;
				}
				
				if(max_len < cur_len) {
					max_num = cur;
					max_len = cur_len;
				}
			}
			
			System.out.println("#" + tc + " " + max_num + " " + max_len);
		}
	}	
	
	public static boolean prox(int[] p1, int[] p2) {
		return (Math.abs(p1[0] - p2[0]) + Math.abs(p1[1] - p2[1])) == 1;
	}
}