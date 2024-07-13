import java.util.Scanner;

public class Main {
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		String encrypted = sc.next();
		int slen = encrypted.length();
		int r = -1;
		
		for(int i = 1; i * i <= slen; i++)
			if(slen % i == 0)
				r = i;
		
		int c = slen / r;
		StringBuilder decrypted = new StringBuilder();
		for(int i = 0; i < slen; i++)
		{
			decrypted.append(encrypted.charAt((i % c) * r + i / c));
		}
		System.out.println(decrypted.toString());
	}
}
