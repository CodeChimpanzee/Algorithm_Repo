#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>

using namespace std;

unordered_map<string, int> counter;
int n, m, k;
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};
char dat[11][11];

int cidx(int idx, int n)
{
    return (idx + n) % n;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    vector<string> chk_list(k);
    for(int i = 0; i < n; i++)
    {
        string t; cin >> t;
        for(int j = 0; j < m; j++)
            dat[i][j] = t[j];
    }

    for(int i = 0; i < k; i++)
        cin >> chk_list[i];

    queue<pair<pair<int, int>, string>> q;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            q.push({{i, j}, string(&dat[i][j], 1)});
        }

    while(!q.empty())
    {
        auto cur = q.front(); q.pop();
        counter[cur.second]++;
        if(cur.second.size() == 5) continue;
        for(int i = 0; i < 8; i++)
        {
            int cx = cidx(cur.first.first + dx[i], n);
            int cy = cidx(cur.first.second + dy[i], m);

            q.push({{cx, cy}, cur.second + dat[cx][cy]});
        }
    }

    for(int i = 0; i < k; i++)
        cout << counter[chk_list[i]] << "\n";
}