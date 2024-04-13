#include<iostream>
#include<queue>
#include<string>
#include<algorithm>

using namespace std;

char dat[25];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
    int cells[25];
    for(int i = 0; i < 5; i++)
    {
        string t; cin >> t;
        for(int j = 0; j < 5; j++)
        {
            dat[i * 5 + j] = t[j];
            cells[i * 5 + j] = i * 5 + j;
        }
    }

    int choose[25];
    for(int i = 0; i < 25; i++)
        if(i < 7)
            choose[i] = 1;
        else
            choose[i] = 0;

    int ans = 0;
    do
    {
        int cnt_s = 0;
        for(int i = 0; i < 25; i++)
            if(choose[i] == 1)
                if(dat[cells[i]] == 'S')
                    cnt_s++;

        if(cnt_s < 4) continue;

        int first_idx = 0;
        for(; first_idx < 25 && !choose[first_idx]; first_idx++);
        
        bool visit[5][5] = {false};
        queue<pair<int, int>> bfs;
        bfs.push({first_idx / 5, first_idx % 5});
        while(!bfs.empty())
        {
            pair<int, int> cur = bfs.front();
            visit[cur.first][cur.second] = true;
            for(int i = 0; i < 4; i++)
            {
                int cx = cur.first + dx[i], cy = cur.second + dy[i];
                if(cx < 0 || cx >= 5 || cy < 0 || cy >= 5 || choose[cx * 5 + cy] == 0) continue; // 범위 밖, 미선택 패스
                if(visit[cx][cy]) continue; // 선택된 것 중 방문한 것은 제외

                bfs.push({cx, cy});
            }
            bfs.pop();
        }

        int vcount = 0; // 방문한 노드 수
        for(int i = 0; i < 25; i++)
            if(visit[i / 5][i % 5]) vcount++;

        if(vcount == 7)
            ans++;
    } while(prev_permutation(choose, choose + 25));

    cout << ans;
}