import java.util.Scanner;

public class Solution {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int tc = 1; tc <= T; tc++) {
			String test = sc.next();
			int len = test.length();
			boolean is_pal = true;
			
			for(int i = 0; i <= len / 2; i++)
				if(test.charAt(i) != test.charAt(len - 1 - i))
					is_pal = false;
			
			System.out.println("#" + tc + " " + (is_pal ? 1 : 0));
		}
	}
}
