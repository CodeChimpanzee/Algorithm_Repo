#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

ll dat[100001];
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> dat[i];
    dat[n] = 1e10;
    sort(dat, dat + n);

    ll ans = 2e9; 
    for(int i = 0; i < n - 1; i++)
        ans = min(ans, *lower_bound(dat + i + 1, dat + n, dat[i] + m) - dat[i]);
    cout << ans << "\n";
}