#include<iostream>
#include<map>

using namespace std;
using ll = long long;

map<ll, ll> acm_record;
ll diff_acm[200001];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> diff_acm[i];
    for(int i = 1; i <= n; i++)
    {
        ll t; cin >> t;
        diff_acm[i] -= t; 
    }
    for(int i = 1; i <= n; i++)
        diff_acm[i] = diff_acm[i - 1] + diff_acm[i];

    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(diff_acm[i] == 0) ans++;
        ans += acm_record[diff_acm[i]]++;
    }
    cout << ans << "\n";
}