import java.util.Scanner;

public class Main {
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int L = sc.nextInt(), N = sc.nextInt();
		int dat[] = new int[L+1];
		
		int emax = -1, emaxi = -1;
		int rmax = -1, rmaxi = -1;
		for(int i = 1; i <= N; i++)
		{
			int from = sc.nextInt(), to = sc.nextInt();
			if(to - from + 1 > emax)
			{
				emax = to - from + 1;
				emaxi = i;
			}
			
			int cnt = 0;
			for(int j = from; j <= to; j++)
			{
				if(dat[j] == 0)
				{
					dat[j] = i;
					cnt++;
				}
			}
			if(cnt > rmax)
			{
				rmax = cnt;
				rmaxi = i;
			}
		}
		
		System.out.println(emaxi);
		System.out.println(rmaxi);
	}
}
