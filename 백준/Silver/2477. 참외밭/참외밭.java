import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt();
		int[] dx = {1, -1, 0, 0};
		int[] dy = {0, 0, 1, -1};
		
		Point[] pts = new Point[6];
		Point cur = new Point(0, 0);
		for(int i = 0; i < 6; i++) {
			pts[i] = new Point(cur.x, cur.y);
			int dir = sc.nextInt() - 1;
			int step = sc.nextInt();
			cur.x += dx[dir] * step;
			cur.y += dy[dir] * step;
		}
		
		int xmax = Integer.MIN_VALUE, xmin = Integer.MAX_VALUE;
		int ymax = Integer.MIN_VALUE, ymin = Integer.MAX_VALUE;
		for(int i = 0; i < 6; i++) {
			xmax = Math.max(xmax, pts[i].x);
			xmin = Math.min(xmin, pts[i].x);
			ymax = Math.max(ymax, pts[i].y);
			ymin = Math.min(ymin, pts[i].y);
		}
		int big_area = (xmax - xmin) * (ymax - ymin);
		
		Point[] small = new Point[3];
		int idx = 0;
		for(int i = 0; i < 6; i++) {
			if((pts[i].x == xmax || pts[i].x == xmin) && (pts[i].y == ymax || pts[i].y == ymin)) {
				//Already chosen, does nothing
			}
			else {
				small[idx++] = pts[i];
			}
		}

		xmax = Integer.MIN_VALUE; xmin = Integer.MAX_VALUE;
		ymax = Integer.MIN_VALUE; ymin = Integer.MAX_VALUE;
		for(int i = 0; i < 3; i++) {
			xmax = Math.max(xmax, small[i].x);
			xmin = Math.min(xmin, small[i].x);
			ymax = Math.max(ymax, small[i].y);
			ymin = Math.min(ymin, small[i].y);
		}
		int small_area = (xmax - xmin) * (ymax - ymin);
		System.out.println((big_area - small_area) * K);
	}

	
}

class Point {
	int x;
	int y;
	
	Point(int x, int y) {
		this.x = x;
		this.y = y;
	}
}