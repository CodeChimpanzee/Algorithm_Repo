#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n; cin >> m >> n;
    int cnt_zero = 0, max_depth = 0;

    vector<vector<int>> data(n, vector<int>(m));
    vector<vector<int>> depth(n, vector<int>(m, 0));
    queue<pair<int, int>> bfs;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            int t; cin >> t;
            data[i][j] = t;

            if(t == 0)  cnt_zero++;
            if(t == 1)  bfs.push({i, j});
        } 

    while(!bfs.empty())
    {
        pair<int, int> cur = bfs.front();
        for(int i = 0; i < 4; i++)
        {
            int cx = cur.first + dx[i], cy = cur.second + dy[i];
            if(cx < 0 || cx >= n || cy < 0 || cy >= m)
                continue;
            if(data[cx][cy] == 0)
            {
                bfs.push({cx, cy});
                data[cx][cy] = 1;
                cnt_zero--;

                depth[cx][cy] = depth[cur.first][cur.second] + 1;
                if(depth[cx][cy] > max_depth) max_depth = depth[cx][cy];
            }
        }
        bfs.pop();
    }

    if(cnt_zero > 0) max_depth = -1;
    cout << max_depth;
}