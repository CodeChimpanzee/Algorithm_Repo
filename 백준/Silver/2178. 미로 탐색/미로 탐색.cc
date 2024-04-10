#include<iostream>
#include<queue>
#include<vector>
#include<string>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<vector<bool>> data(n, vector<bool>(m));
    vector<vector<bool>> visit(n, vector<bool>(m, false));
    vector<vector<int>> depth(n, vector<int>(m, 1));

    for(int i = 0; i < n; i++)
    {
        string t; cin >> t;
        for(int j = 0; j < m; j++)
            data[i][j] = (t[j] == '1') ? true : false;
    }

    queue<pair<int, int>> bfs;

    bfs.push({0, 0});
    visit[0][0] = true;
    while(!bfs.empty())
    {
        pair<int, int> cur = bfs.front();

        if((cur.first == n-1) && (cur.second == m-1)) break;
        for(int i = 0; i < 4; i++)
        {
            int cx = cur.first + dx[i], cy = cur.second + dy[i];
            if(cx < 0 || cx >= n || cy < 0 || cy >= m) continue;
            if(data[cx][cy] && !visit[cx][cy])
            {
                visit[cx][cy] = true;
                bfs.push({cx, cy});
                depth[cx][cy] = depth[cur.first][cur.second] + 1;
            }
        }
        bfs.pop();
    }

    cout << depth[n-1][m-1];
}