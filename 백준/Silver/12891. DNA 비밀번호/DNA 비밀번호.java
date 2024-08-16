import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class Main {
	static int[] acgt, cur_acgt;
	static int ans = 0;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int S = sc.nextInt(), P = sc.nextInt();
		String dna = sc.next();
		
		acgt = new int[4];
		for(int i = 0; i < acgt.length; i++) 
			acgt[i] = sc.nextInt();
		
		cur_acgt = new int[4];
		for(int i = 0; i < P; i++)
			cur_acgt[atoi(dna.charAt(i))]++;
		for(int i = P; i < S; i++) {
			if(chk())
				ans++;
			cur_acgt[atoi(dna.charAt(i-P))]--;
			cur_acgt[atoi(dna.charAt(i))]++;
		}
		
		if(chk())
			ans++;
		System.out.println(ans);
	}
	
	public static boolean chk() {
		boolean flag = true;
		for(int c = 0; c < 4; c++)
			if(acgt[c] > cur_acgt[c])
				flag = false;
		return flag;
	}
	
	public static int atoi(char a) {
		if(a == 'A')
			return 0;
		if(a == 'C')
			return 1;
		if(a == 'G')
			return 2;
		if(a == 'T')
			return 3;
		return -1;
	}
}

