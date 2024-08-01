import java.util.Scanner;

public class Main {
	static boolean[][] hrz = new boolean[10][10];
	static boolean[][] vrt = new boolean[10][10];
	static boolean[][] cll = new boolean[10][10];
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[][] sudoku = new int[10][10];
		for(int i = 0; i < 9; i++)
			for(int j = 0; j < 9; j++) {
				int t = sc.nextInt();
				sudoku[i][j] = t;
				hrz[i][t] = true;
				vrt[j][t] = true;
				cll[(i/3*3)+j/3][t] = true;
			}
		
		solve(sudoku, 0);
		for(int i = 0; i < 9; i++) {
			for(int j = 0; j < 9; j++)
				System.out.print(sudoku[i][j] + " ");
			System.out.println();
		}
	}
	
	public static boolean solve(int[][] sudoku, int idx) {
		if(idx == 81) 
			return true;
		
		int r = idx / 9, c = idx % 9;
		int n = (r/3*3) + c/3;
		if(sudoku[r][c] != 0)
			return solve(sudoku, idx + 1);
			
		for(int i = 1; i <= 9; i++) {
			if(!hrz[r][i] && !vrt[c][i] && !cll[n][i]) {
				sudoku[r][c] = i;
				hrz[r][i] = true;
				vrt[c][i] = true;
				cll[n][i] = true;
				if(solve(sudoku, idx + 1))
					return true;
				hrz[r][i] = false;
				vrt[c][i] = false;
				cll[n][i] = false;
				sudoku[r][c] = 0;
			}
		}
		
		return false;
	}
}