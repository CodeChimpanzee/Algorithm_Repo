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

    int st = 0, ed = 0;
    ll ans = 2e9;
    while(st <= ed && ed < n)
    {
        ll diff = dat[ed] - dat[st];
        if(diff >= m)
        {
            ans = min(ans, diff);
            st++;
        }
        else
        {
            ed++;
        }
    }
    cout << ans << "\n";
}