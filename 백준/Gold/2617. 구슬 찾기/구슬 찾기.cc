#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int find_nodes_bfs(vector<vector<int>> &graph);
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vector<vector<int>> graph_u(n), graph_d(n);

    while(m--)
    {
        int t1, t2;
        cin >> t1 >> t2;
        graph_u[t1-1].push_back(t2-1);
        graph_d[t2-1].push_back(t1-1);
    }

    cout << find_nodes_bfs(graph_u) + find_nodes_bfs(graph_d);
}

int find_nodes_bfs(vector<vector<int>> &graph)
{
    int center = (n + 1) / 2;
    int cnt = 0;
    queue<int> bfs;

    for(int i = 0; i < n; i++)
    {
        vector<bool> visit(n, false);
        int nnodes = 0;

        bfs.push(i);
        visit[i] = true;
        while(!bfs.empty())
        {
            int cur = bfs.front();

            for(int ii = 0; ii < graph[cur].size(); ii++)
            {
                if(!visit[graph[cur][ii]])
                {
                    bfs.push(graph[cur][ii]);
                    visit[graph[cur][ii]] = true;
                    nnodes++;
                }
            }

            bfs.pop();
        }

        if(nnodes >= center) cnt++;
    }
    return cnt;
}