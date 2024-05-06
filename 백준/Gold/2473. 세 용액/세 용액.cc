#include<iostream>
#include<algorithm>
#include<vector>

#define IMAX 3147483647LL

using namespace std;
using ll = long long;

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<ll> dat(n);
    for(int i = 0; i < n; i++)
        cin >> dat[i];
    sort(dat.begin(), dat.end());

    ll amin = IMAX;
    tuple<ll, ll, ll> ans;
    for(int i = 0; i < n - 2; i++)
        for(int j = i + 1; j < n - 1; j++)
        {
            auto st = dat.begin() + j + 1;
            auto ed = dat.rend() - j - 2;
            ll t = - (dat[i] + dat[j]);
            ll lb = *lower_bound(st, dat.end() - 1, t);
            ll ub = *lower_bound(dat.rbegin(), ed, t, greater<ll>());

            if(amin > abs(lb - t))
                { ans = {dat[i], dat[j], lb}; amin = abs(lb - t); }
            if(amin > abs(ub - t))
                { ans = {dat[i], dat[j], ub}; amin = abs(ub - t); }
        }

    cout << get<0>(ans) << " " << get<1>(ans) << " " << get<2>(ans) << "\n";
}