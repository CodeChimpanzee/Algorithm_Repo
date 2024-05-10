#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dat[1001][1001];
int ptr[1001];
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cin >> dat[i][j];
        sort(dat[i], dat[i] + m);
    }

    vector<pair<int, int>> order;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            order.push_back({dat[i][j], i});
    sort(order.begin(), order.end());

    int cnt = 0, lim = n * (m - 1);
    int tmax = 0, tmin = 1e9;
    for(int i = 0; i < n; i++)
    {
        tmax = max(tmax, dat[i][0]);
        tmin = min(tmin, dat[i][0]);
    }
    int ans = tmax - tmin;

    while(cnt < lim)
    {
        int cur = order[cnt].second;
        if(ptr[cur] == (m - 1))
            break;
        ptr[cur]++;

        tmax = max(tmax, dat[cur][ptr[cur]]);
        tmin = order[++cnt].first;

        ans = min(ans, tmax - tmin);
    }

    cout << ans << "\n";
}