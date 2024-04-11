#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int dx[2] = {0, 1};
int dy[2] = {1, 1};

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);

    int n; cin >> n;

    int data[500][500];
    int sum[500][500];
    bool visit[500][500];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cin >> data[j][i];
            sum[j][i] = data[j][i];
            visit[j][i] = false;
        }
    }

    queue<pair<int, int>> bfs;
    bfs.push({0, 0});

    while(!bfs.empty())
    {
        pair<int, int> cur = bfs.front();
        for(int ii = 0; ii < 2; ii++)
        {
            int cx = cur.first + dx[ii], cy = cur.second + dy[ii];
            if(cy >= n || visit[cur.first][cur.second]) continue;
            bfs.push({cx, cy});

            int temp_sum = sum[cur.first][cur.second] + data[cx][cy];
            if(temp_sum > sum[cx][cy]) sum[cx][cy] = temp_sum;
        }

        visit[cur.first][cur.second] = true;
        bfs.pop();
    }

    int max_sum = 0;
    for(int i = 0; i < n; i++)
        if(sum[i][n-1] > max_sum) max_sum = sum[i][n-1];
    
    cout << max_sum << "\n";
}