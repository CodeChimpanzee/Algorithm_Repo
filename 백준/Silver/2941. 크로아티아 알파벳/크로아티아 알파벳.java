import java.util.HashMap;
import java.util.Scanner;

public class Main {
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		HashMap<String, Integer> atoc = new HashMap<>();
		String ca[] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
		for(int i = 0; i < ca.length; i++)
			atoc.put(ca[i], ca[i].length());
		
		String decrp = sc.next();
		int ptr = 0, ans = 0, len = decrp.length();
		while(ptr < len)
		{
			int step = 1;
			if(atoc.get(decrp.substring(ptr, Math.min(ptr + 2, len))) != null)
				step = 2;
			else if(atoc.get(decrp.substring(ptr, Math.min(ptr + 3, len))) != null)
				step = 3;
			
			ptr += step;
			ans++;
		}
		System.out.println(ans);
	}
}
