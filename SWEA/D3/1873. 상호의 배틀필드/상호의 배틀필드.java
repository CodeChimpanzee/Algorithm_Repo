import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Solution {
	public static boolean OOB(int x, int y, int H, int W) {
		return (x >= H || x < 0 || y >= W || y < 0);
	}

	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int dx[] = {1, -1, 0, 0};
		int dy[] = {0, 0, 1, -1};

		for (int tc = 1; tc <= T; tc++) {
			int H = sc.nextInt(), W = sc.nextInt();
			int tankd = -1, tankx = -1, tanky = -1;
			String maps[][] = new String[H][W];
			Map<String, String> atos = new HashMap<>();
			Map<String, Integer> dict = new HashMap<>();
			
			dict.put(">", 2); atos.put("R", ">");
			dict.put("<", 3); atos.put("L", "<");
			dict.put("v", 0); atos.put("D", "v");
			dict.put("^", 1); atos.put("U", "^");

			for (int i = 0; i < H; i++) {
				String mapline = sc.next();
				for (int j = 0; j < W; j++) {
					maps[i][j] = "" + mapline.charAt(j);
					if (dict.get(maps[i][j]) != null) {
						tankx = i;
						tanky = j;
						tankd = dict.get(maps[i][j]);
					}
				}
			}

			int N = sc.nextInt();
			String cmdline = sc.next();
			for (int i = 0; i < N; i++) {
				char ccmd = cmdline.charAt(i); 
				int cx, cy;
				switch(ccmd)
				{
				case 'S' :
					cx = tankx + dx[tankd];
					cy = tanky + dy[tankd];
					while(!OOB(cx, cy, H, W))
					{
						if(maps[cx][cy].equals("#")) break;
						if(maps[cx][cy].equals("*"))
						{
							maps[cx][cy] = ".";
							break;
						}
						cx += dx[tankd];
						cy += dy[tankd];
					}
					break;
				case 'U' :
				case 'D' :
				case 'L' :
				case 'R' :
					maps[tankx][tanky] = atos.get(ccmd + "");
					tankd = dict.get(maps[tankx][tanky]);
					cx = tankx + dx[tankd];
					cy = tanky + dy[tankd];
					if(!OOB(cx, cy, H, W) && maps[cx][cy].equals("."))
					{
						maps[tankx][tanky] = ".";
						maps[cx][cy] = atos.get(ccmd + "");
						tankx = cx;
						tanky = cy;
					}
					break;
				}
			}
			
			System.out.print("#" + tc + " ");
			for (int i = 0; i < H; i++) {
				for (int j = 0; j < W; j++) {
					System.out.print(maps[i][j]);
				}
				System.out.println();
			}
		}
	}
}
