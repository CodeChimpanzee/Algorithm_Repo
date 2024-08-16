import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String formula = sc.next();
		StringBuilder ans = new StringBuilder();
		
		Deque<Character> stack = new ArrayDeque<>();
		for(int i = 0; i < formula.length(); i++) {
			char cur = formula.charAt(i);
			char top = (stack.peekFirst() != null) ? stack.peekFirst() : ' ';
			if(cur >= 'A' && cur <= 'Z')
				ans.append(cur);
			if(cur == '+' || cur == '-') {
				while(!stack.isEmpty() &&
						stack.peekFirst() != '(') {
					ans.append(stack.pollFirst());
				}
				stack.offerFirst(cur);
			}
			
			if(cur == '*' || cur == '/') {
				while(!stack.isEmpty() && (
						stack.peekFirst() == '*' || stack.peekFirst() == '/')) {
					ans.append(stack.pollFirst());
				}

				stack.offerFirst(cur);
			}
			if(cur == '(') {
				stack.offerFirst(cur);
			}
			if(cur == ')') {
				while(!stack.isEmpty() &&
						stack.peekFirst() != '(')
					ans.append(stack.pollFirst());
				stack.pollFirst();
			}
		}
		
		while(!stack.isEmpty())
			ans.append(stack.pollFirst());
		
		System.out.println(ans);
	}
}