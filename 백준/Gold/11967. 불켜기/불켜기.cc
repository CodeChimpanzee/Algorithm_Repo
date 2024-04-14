#include<iostream>
#include<queue>

using namespace std;


int n, m;
bool is_on[101][101];
bool visit[101][101];
queue<pair<int, int>> swt[101][101];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y, a, b; cin >> x >> y >> a >> b;
        swt[x][y].push({a, b});
    }
    queue<pair<int, int>> bfs;
    bfs.push({1, 1});
    visit[1][1] = true;
    is_on[1][1] = true;
    while(!bfs.empty())
    {
        pair<int, int> cur = bfs.front();

        while(!swt[cur.first][cur.second].empty())
        {
            pair<int, int> cur_swt = swt[cur.first][cur.second].front();
            for(int i = 0; i < 4; i++)
            {
                int cx = cur_swt.first + dx[i], cy = cur_swt.second + dy[i];
                if(cx < 1 || cx > n || cy < 1 || cy > n) continue;
                if(visit[cx][cy]) // 불이 켜진 방에 접근할 수 있는가
                {
                    visit[cur_swt.first][cur_swt.second] = true;
                    bfs.push({cur_swt.first, cur_swt.second});
                    break;
                }
            }
            is_on[cur_swt.first][cur_swt.second] = true;
            swt[cur.first][cur.second].pop();
        }
        
        for(int i = 0; i < 4; i++)
        {
            int cx = cur.first + dx[i], cy = cur.second + dy[i];
            if(cx < 1 || cx > n || cy < 1 || cy > n || visit[cx][cy]) continue; // 경계, 방문 체크
            if(!is_on[cx][cy]) continue; // 불 꺼진 방 체크

            visit[cx][cy] = true;
            bfs.push({cx, cy}); 
        }
        bfs.pop();
    }

    int on_count = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(is_on[i][j])
                on_count++;

    cout << on_count;
}