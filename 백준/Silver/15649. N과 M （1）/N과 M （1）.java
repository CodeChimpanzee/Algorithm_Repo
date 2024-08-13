import java.util.Scanner;

public class Main {
	public static StringBuilder sb = new StringBuilder(); 
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), M = sc.nextInt();
		int[] dat = new int[N];
		for (int i = 0; i < dat.length; i++) 
			dat[i] = i+1;
		
		sequence(0, new boolean[N], dat, new int[M]);
		System.out.println(sb);
	}
	
	public static void sequence(int k, boolean[] v, int[] dat, int[] sel) {
		if(k == sel.length) {
			for(int i = 0; i < sel.length; i++) {
				sb.append(sel[i]);
				sb.append(" ");
			}
			sb.append("\n");
			return;
		}
		
		for(int i = 0; i < dat.length; i++) {
			if(v[i]) continue;
			sel[k] = dat[i];
			v[i] = true;
			sequence(k+1, v, dat, sel);
			v[i] = false;
		}
	}
}