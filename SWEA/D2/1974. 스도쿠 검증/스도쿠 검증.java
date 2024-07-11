import java.util.Arrays;
import java.util.Scanner;

public class Solution {
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();

		for(int test_case = 1; test_case <= T; test_case++)
		{
		    int dat[][] = new int[9][9];
		    boolean check = true;
		    for(int i = 0; i < 81; i++)
		        dat[i/9][i%9] = sc.nextInt();

		    for(int i = 0; i < 9; i++)
		    {
			    boolean check_nums[] = new boolean[10];
			    for(int j = 0; j < 9; j++)
			    	if(!check_nums[dat[i][j]])
			    		check_nums[dat[i][j]] = true;
			    	else
			    		check = false;
		    }

		    for(int j = 0; j < 9; j++)
		    {
			    boolean check_nums[] = new boolean[10];
			    for(int i = 0; i < 9; i++)
			    	if(!check_nums[dat[i][j]])
			    		check_nums[dat[i][j]] = true;
			    	else
			    		check = false;
		    }

		    for(int i = 0; i < 9; i++)
		    {
			    boolean check_nums[] = new boolean[10];
			    for(int j = 0; j < 9; j++)
			    	if(!check_nums[dat[(i/3)*3 + j/3][(i%3)*3 + j%3]])
			    		check_nums[dat[(i/3)*3 + j/3][(i%3)*3 + j%3]] = true;
			    	else
			    		check = false;
		    }
		    
		    System.out.println("#" + test_case + " " + (check ? 1 : 0));
		}
	}
}
