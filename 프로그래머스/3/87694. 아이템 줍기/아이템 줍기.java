import java.util.*;
class Solution {
    static int[][] map = new int[101][101];
    public int solution(int[][] rectangle, int characterX, int characterY, int itemX, int itemY) {
        drawEdge(rectangle);
        
        int[] dr = {1, -1, 0, 0};
        int[] dc = {0, 0, 1, -1};
        
        int answer = 0;
        Queue<int[]> q = new ArrayDeque<>();
        boolean[][] v = new boolean[map.length][map[0].length];
        q.offer(new int[] {characterY*2, characterX*2, 0});
        v[characterY*2][characterX*2] = true;
        
        while(!q.isEmpty()) {
            int[] cur = q.poll();
            int r = cur[0], c = cur[1];
            if(cur[0] == itemY*2 && cur[1] == itemX*2) {
                answer = cur[2]/2;
                break;
            }
            for(int d = 0; d < 4; d++){
                int nr = cur[0] + dr[d], nc = cur[1] + dc[d];
                if(oob(nr, nc)) continue;
                if(map[nr][nc] != 1) continue;
                if(v[nr][nc]) continue;
                
                v[nr][nc] = true;
                q.offer(new int[] {nr, nc, cur[2] + 1});
            }

        }
        return answer;
    }
    
    static void drawEdge(int[][] rectangle)
    {
        for(int i = 0; i < rectangle.length; i++) {
            int ldc = rectangle[i][0]*2, ldr = rectangle[i][1]*2;
            int ruc = rectangle[i][2]*2, rur = rectangle[i][3]*2;
            
            for(int r = ldr; r <= rur; r++)
                for(int c = ldc; c <= ruc; c++) {
                    if(r == ldr || r == rur || c == ldc || c == ruc){
                        if(map[r][c] ==2)
                            continue;
                        map[r][c] = 1;
                    }
                    else
                        map[r][c] = 2;
                }
        }
    }
    
    public static boolean oob(int r, int c) {
        return (r < 0 || r >= map.length || c < 0 || c >= map[0].length);
    }
}