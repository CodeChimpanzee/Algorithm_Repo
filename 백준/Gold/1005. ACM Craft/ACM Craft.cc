#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--)
    {
        int n, k; cin >> n >> k;
        vector<int> ctime = vector<int>(n + 1);
        for(int i = 1; i <= n; i++)
            cin >> ctime[i];
        ctime[0] = 0;

        vector<vector<int>> graph = vector<vector<int>> (n + 1);
        vector<int> pre = vector<int> (n + 1, 0);
        for(int i = 1; i <= k; i++)
        {
            int tf, ts; cin >> tf >> ts;
            graph[tf].push_back(ts);
            pre[ts]++;
        }

        for(int i = 1; i <= n; i++)
            if(pre[i] == 0)
            {
                graph[0].push_back(i);
                pre[i]++;
            }    

        int w; cin >> w;
        vector<int> tot_time = vector<int>(n + 1, 0);
        queue<int> bfs;

        bfs.push(0);
        while(!bfs.empty())
        {
            int cur = bfs.front(); bfs.pop();
            for(int node : graph[cur])
            {
                tot_time[node] = max(tot_time[node], tot_time[cur] + ctime[node]);
                pre[node]--;
                if(pre[node] == 0)
                    bfs.push(node);
            }
        }

        cout << tot_time[w] << "\n";
    }
}