#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> graph;
vector<int> pre_size;
vector<int> ans;
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    graph.push_back(vector<int>());
    cin >> n >> m;

    ans = vector<int>(n + 1, 0);
    pre_size = vector<int>(n + 1, 1);

    for(int i = 1; i <= n; i++)
    {
        graph[0].push_back(i);
        graph.push_back(vector<int>());
    }
    for(int i = 1; i <= m; i++)
    {
        int t1, t2; cin >> t1 >> t2;
        graph[t1].push_back(t2);
        pre_size[t2]++;
    }

    queue<int> bfs; bfs.push(0);
    while(!bfs.empty())
    {
        int cur = bfs.front(); bfs.pop();
        for(int i = 0; i < graph[cur].size(); i++)
        {
            int cc = graph[cur][i];
            ans[cc] = max(ans[cc], ans[cur] + 1);
            pre_size[cc]--;
            if(pre_size[cc] == 0)
                bfs.push(cc);
        }
    }

    for(int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}