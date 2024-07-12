import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt(), B = sc.nextInt(), C = sc.nextInt(), D = sc.nextInt();
		for(int i = 0; i < 3; i++)
		{
			int t = sc.nextInt()-1;
			System.out.println((t % (A+B) >= A ? 0 : 1) + (t % (C+D) >= C ? 0 : 1));
		}
	}
}
