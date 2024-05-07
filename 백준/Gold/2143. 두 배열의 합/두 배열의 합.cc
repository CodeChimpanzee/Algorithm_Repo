#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
using ll = long long;

vector<int> a, b;
vector<ll> as, bs;
ll t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    int n, m;
    cin >> n; a.push_back(0);
    for(int i = 1; i <= n; i++)
    {
        int ti; cin >> ti;
        a.push_back(ti + a[i - 1]);
    }
    cin >> m; b.push_back(0);
    for(int i = 1; i <= m; i++)
    {
        int ti; cin >> ti;
        b.push_back(ti + b[i - 1]);
    }

    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            as.push_back(a[j] - a[i - 1]);
    for(int i = 1; i <= m; i++)
        for(int j = i; j <= m; j++)
            bs.push_back(b[j] - b[i - 1]);
    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());

    ll ans = 0;
    for(int i = 0; i < (int)bs.size(); i++)
    {
        ll target = t - bs[i];
        ans += (upper_bound(as.begin(), as.end(), target) - lower_bound(as.begin(), as.end(), target));
    }

    cout << ans << "\n";
}