#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

#define x first
#define y second

int n, m; // 행 열
int g, r; // 배양액 개수

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

pair<int, int> candidate[10]; // 배양액 후보지
int map_state[51][51];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> g >> r;
    int candid_cnt = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            int k; cin >> k;
            if(k == 2) candidate[candid_cnt++] = {i, j};
            map_state[i][j] = k;
        }

    int choose[10];
    fill(choose, choose + r, 2);
    fill(choose + r, choose + g + r, 1);
    fill(choose + g + r, choose + candid_cnt, 0);
    
    int flower_max = 0;
    do
    {
        queue<pair<int, int>> bfs;
        pair<int, int> visit[51][51]; // first 0 미방문 1 초록 2 빨강 3 꽃, second 시간
        int flower_cnt = 0;
            
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                visit[i][j] = {0, -1};

        for(int i = 0; i < candid_cnt; i++)
        {
            if(choose[i] == 0) continue;
            bfs.push(candidate[i]);
            visit[candidate[i].x][candidate[i].y] = {choose[i], 0};
        }

        while(!bfs.empty())
        {
            pair<int, int> cur = bfs.front();

            if(visit[cur.x][cur.y].first == 3) {bfs.pop(); continue;}
            for(int i = 0; i < 4; i++)
            {
                int cx = cur.x + dx[i], cy = cur.y + dy[i];
                if(cx < 1 || cx > n || cy < 1 || cy > m) continue;
                if(map_state[cx][cy] == 0) continue; // 호수는 통과 불가
                if(visit[cx][cy].first == 3) continue; // 꽃은 통과 불가
                if(visit[cx][cy].first != 0) // 방문한 땅
                {
                    if((visit[cx][cy].second == visit[cur.x][cur.y].second + 1)
                    && (visit[cx][cy].first != visit[cur.x][cur.y].first)) // 동시 방문 체크
                    {
                        visit[cx][cy].first = 3;
                        flower_cnt++;
                    }
                }
                else // 빈 땅
                {
                    visit[cx][cy] = {visit[cur.x][cur.y].first, visit[cur.x][cur.y].second + 1};
                    bfs.push({cx, cy});
                }
            }

            bfs.pop();
        }
        flower_max = max(flower_max, flower_cnt);
    } while (prev_permutation(choose, choose + candid_cnt));

    cout << flower_max;
}