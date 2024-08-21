import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.Reader;
import java.util.Arrays;
import java.util.Scanner;

public class Main{
	static int[][][][] dat;
	static boolean crev, rrev;
	static int rot;
	static int N, M, R;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] line = br.readLine().split(" "); 
		N = Integer.parseInt(line[0]); M = Integer.parseInt(line[1]);
		R = Integer.parseInt(line[2]);
		dat = new int[2][2][N/2][M/2];
		for(int i = 0; i < N/2; i++) {
			line = br.readLine().split(" "); 
			for(int j = 0; j < M/2; j++)
				dat[0][0][i][j] = Integer.parseInt(line[j]);
			for(int j = 0; j < M/2; j++)
				dat[0][1][i][j] = Integer.parseInt(line[M/2+j]);
		}
		for(int i = 0; i < N/2; i++) {
			line = br.readLine().split(" "); 
			for(int j = 0; j < M/2; j++)
				dat[1][0][i][j] = Integer.parseInt(line[j]);
			for(int j = 0; j < M/2; j++)
				dat[1][1][i][j] = Integer.parseInt(line[M/2+j]);
		}

		String ops = br.readLine();
		for(int i = 0; i < ops.length(); i+=2) {
			switch(ops.charAt(i)) {
			case '1' : arrUDmirror(); break;
			case '2' : arrLRmirror(); break;
			case '3' : arrRrot2(); break;
			case '4' : arrLrot2(); break;
			case '5' : arrRrot1(); break;
			case '6' : arrLrot1(); break; 
			}
		}
			
		print();
	}

	public static void print() {
		int[][][][] rdat = (rot % 2 == 0) ? new int[2][2][N/2][M/2] : new int[2][2][M/2][N/2];
		int[] str = {0, 0, N/2-1, N/2-1};
		int[] stc = {0, M/2-1, M/2-1, 0};
		int nr = str[rot], nc = stc[rot];
		if(rrev)
			nr = N/2-1 - nr;
		if(crev)
			nc = M/2-1 - nc;
		
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++) {
				if(nr == 0 && nc == 0) {
					for(int r = 0; r < N/2; r++)
						for(int c = 0; c < M/2; c++)
							if(rot % 2 == 0)
								rdat[i][j][r][c] = dat[i][j][r][c];
							else
								rdat[i][j][c][r] = dat[i][j][r][c]; 
				} else if(nr == N/2-1 && nc == 0) {
					for(int r = N/2-1; r >= 0; r--)
						for(int c = 0; c < M/2; c++)
							if(rot % 2 == 0)
								rdat[i][j][N/2-1-r][c] = dat[i][j][r][c];
							else
								rdat[i][j][c][N/2-1-r] = dat[i][j][r][c]; 
				} else if(nr == 0 && nc == M/2-1) {
					for(int r = 0; r < N/2; r++)
						for(int c = M/2-1; c >= 0; c--)
							if(rot % 2 == 0)
								rdat[i][j][r][M/2-1-c] = dat[i][j][r][c];
							else
								rdat[i][j][M/2-1-c][r] = dat[i][j][r][c]; 
				} else if(nr == N/2-1 && nc == M/2-1) {
					for(int r = N/2-1; r >= 0; r--)
						for(int c = M/2-1; c >= 0; c--)
							if(rot % 2 == 0)
								rdat[i][j][N/2-1-r][M/2-1-c] = dat[i][j][r][c];
							else
								rdat[i][j][M/2-1-c][N/2-1-r] = dat[i][j][r][c]; 
				}
			}

		for(int i = 0; i < rdat[0][0].length; i++) {
			for(int j = 0; j < rdat[0][0][i].length; j++)
				System.out.print(rdat[0][0][i][j] + " ");
			for(int j = 0; j < rdat[0][0][i].length; j++)
				System.out.print(rdat[0][1][i][j] + " ");
			System.out.println();
		}
		for(int i = 0; i < rdat[0][0].length; i++) {
			for(int j = 0; j < rdat[0][0][i].length; j++)
				System.out.print(rdat[1][0][i][j] + " ");
			for(int j = 0; j < rdat[0][0][i].length; j++)
				System.out.print(rdat[1][1][i][j] + " ");
			System.out.println();
		}
	}
	
	public static void arrSwap(int i1, int j1, int i2, int j2) {
		int[][] tmp = dat[i1][j1];
		dat[i1][j1] = dat[i2][j2];
		dat[i2][j2] = tmp;
	}
	
	public static void arrUDmirror() {
		arrSwap(0, 0, 1, 0);
		arrSwap(0, 1, 1, 1);
		if(rot % 2 == 0)
			rrev = !rrev;
		else
			crev = !crev;
	}
	
	public static void arrLRmirror() {
		arrSwap(0, 0, 0, 1);
		arrSwap(1, 0, 1, 1);
		if(rot % 2 == 0)
			crev = !crev;
		else
			rrev = !rrev;
	}
	
	public static void arrLrot1() {
		arrSwap(0, 0, 1, 1);
		arrSwap(0, 0, 0, 1);
		arrSwap(1, 1, 1, 0);
	}
	
	public static void arrRrot1() {
		arrSwap(0, 0, 1, 1);
		arrSwap(0, 0, 1, 0);
		arrSwap(1, 1, 0, 1);
	}
	
	public static void arrLrot2() {
		arrLrot1();
		rrev = !rrev;
		crev = !crev;
		rot = (rot - 1 + 4) % 4;
	}
	
	public static void arrRrot2() {
		arrRrot1();
		rrev = !rrev;
		crev = !crev;
		rot = (rot + 1) % 4;
	}
}