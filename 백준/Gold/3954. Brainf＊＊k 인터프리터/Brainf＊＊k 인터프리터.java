import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class Main {
	static int[] pair;
	static int memsize, codsize, inpsize;
	static int mptr, cptr, iptr;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for(int tc = 1; tc <= T; tc++) {
			memsize = sc.nextInt();
			codsize = sc.nextInt();
			inpsize = sc.nextInt();
			mptr = 0; cptr = 0; iptr = 0;
			
			String code = sc.next() + "_";
			String inp = sc.next();
			
			int[] memory = new int[memsize];
			
			pair = new int[codsize];
			initPair(code);
			run(memory, code, inp);
			
			if(cptr == codsize)
				System.out.println("Terminates");
			else {
				boolean[] chk = run(memory, code, inp);
				while(true) {
					while(code.charAt(cptr) != ']') {
						if(code.charAt(cptr) == '[')
							cptr = pair[cptr];
						cptr++;
					}
					if(!chk[cptr + 1]) {
						System.out.println("Loops" + " " + pair[cptr] + " "+ cptr);
						break;
					}
					cptr++;
				}
			}
		}
	}
	
	public static boolean[] run(int[] memory, String code, String inp) {
		boolean[] codchk = new boolean[codsize+1];
		
		for(int cnt = 1; cnt <= 50000000 && cptr < codsize; cnt++) {
			char cop = code.charAt(cptr);
			codchk[cptr] = true;
			
			switch(cop) {
			case '-' :
				memory[mptr] = (memory[mptr] - 1 + 256) % 256;
				break;
			case '+' :
				memory[mptr] = (memory[mptr] + 1) % 256;
				break;
			case '<' :
				mptr = (mptr + 1) % memsize;
				break;
			case '>' :
				mptr = (mptr - 1 + memsize) % memsize;
				break;
			case ',' :
				int cin = (iptr < inpsize) ? inp.charAt(iptr++) : 255;
				memory[mptr] = cin;
				break;
			case '[' :
				if(memory[mptr] == 0)
					cptr = pair[cptr];
				break;
			case ']' :
				if(memory[mptr] != 0)
					cptr = pair[cptr];
				break;
			}
			
			cptr++;
		}
		return codchk;
	}
	
	public static void initPair(String code) {
		Deque<Integer> loop = new ArrayDeque<Integer>();
		for(int i = 0; i < code.length(); i++) {
			int cur = code.charAt(i);
			if(cur == '[')
				loop.offerFirst(i);
			else if(cur == ']') {
				int opener = loop.pollFirst();
				pair[opener] = i;
				pair[i] = opener;
			}
		}
	}
}