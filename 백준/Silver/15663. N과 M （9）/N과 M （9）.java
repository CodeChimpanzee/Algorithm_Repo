import java.util.Arrays;
import java.util.Scanner;

public class Main{
	static StringBuilder sb = new StringBuilder();
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), M = sc.nextInt();
		
		int[] arr = new int[N];
		for (int i = 0; i < arr.length; i++) {
			arr[i] = sc.nextInt();
		}
		Arrays.sort(arr);
		
		seq(0, arr, new int[M], new boolean[N]);
		System.out.println(sb);
	}
	
	public static void seq(int k, int[] arr, int[] sel, boolean[] v) {
		if(k == sel.length) {
			for (int i = 0; i < sel.length; i++) {
				sb.append(sel[i]);
				sb.append(" ");
			}
			sb.append("\n");
			return;
		}
		
		int past = -1;
		for(int i = 0; i < arr.length; i++) {
			if(v[i]) continue;
			if(past == arr[i]) continue;
			
			sel[k] = arr[i];
			v[i] = true;
			past = arr[i];
			seq(k+1, arr, sel, v);
			v[i] = false;
		}
	}
}