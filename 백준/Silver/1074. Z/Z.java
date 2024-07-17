import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int r = sc.nextInt(), c = sc.nextInt();
		
		System.out.println(sol(r, c, N));
	}
	
	private static int sol(int r, int c, int n) {
		if(n == 1) {return r * 2 + c;}
		int cell = (1 << (n-1));
		int rr = r / cell * cell;
		int cc = c / cell * cell;
		return (rr * 2 + cc) * cell + sol(r - rr, c - cc, n-1);
	}
}
