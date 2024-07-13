import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), M = sc.nextInt();
		Integer dat[] = new Integer[N];
		
		for(int i = 0; i < N; i++)
			dat[i] = sc.nextInt();
		
		Arrays.sort(dat, (a, b) -> {
			Integer t = (b-1) % 10 - (a-1) % 10;
			return (t != 0) ? t : a - b;
		}); // 끝이 0인걸 먼저 처리
		int ans = 0, cut = 0, i = 0;
		for(; i < N; i++)
		{
			ans += dat[i] / 10;
			cut += dat[i] / 10 - 1;
			if(dat[i] % 10 != 0)
				cut++;
			if(cut >= M)
				break;
		}
		
		if(cut > M)
			ans -= (cut - M + ((dat[i] % 10 == 0) ? 1 : 0));
		
		System.out.println(ans);
	}
}
