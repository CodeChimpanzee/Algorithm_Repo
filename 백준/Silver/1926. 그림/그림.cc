#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n; cin >> m;
    int smax = 0, sum = 0, cnt = 0;
    queue<pair<int, int>> trav;
    vector<vector<int>> data(n, vector<int>(m));
    vector<vector<bool>> visit(n, vector<bool>(m));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> data[i][j];
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(visit[i][j] || data[i][j] == 0)
                continue;
            
            sum = 0;
            cnt++;
            trav.push({i, j});
            visit[i][j] = true;
            while(!trav.empty())
            {
                pair<int, int> cur = trav.front();
                sum++;
                trav.pop();

                if(cur.first - 1 >= 0 && data[cur.first - 1][cur.second] == 1 && !visit[cur.first - 1][cur.second])
                {
                    visit[cur.first - 1][cur.second] = true;
                    trav.push({cur.first - 1, cur.second});
                }
                if(cur.first + 1 < n && data[cur.first + 1][cur.second] == 1 && !visit[cur.first + 1][cur.second])
                { 
                    visit[cur.first + 1][cur.second] = true;
                    trav.push({cur.first + 1, cur.second});
                }
                if(cur.second - 1 >= 0 && data[cur.first][cur.second - 1] == 1 && !visit[cur.first][cur.second - 1])
                { 
                    visit[cur.first][cur.second - 1] = true;
                    trav.push({cur.first, cur.second - 1});
                }
                if(cur.second + 1 < m && data[cur.first][cur.second + 1] == 1 && !visit[cur.first][cur.second + 1])
                { 
                    visit[cur.first][cur.second + 1] = true;
                    trav.push({cur.first, cur.second + 1});
                }
            }

            if(smax < sum)
                smax = sum;
        }
    
    cout << cnt << '\n' << smax;
}