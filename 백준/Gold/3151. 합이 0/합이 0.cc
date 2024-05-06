#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long n, ans = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<int> dat = vector<int> (n);
    for(int i = 0; i < n; i++)
        cin >> dat[i];
    sort(dat.begin(), dat.end());

    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
        {
            auto st = dat.begin() + j + 1;
            auto tgt = - (dat[i] + dat[j]);
            ans += upper_bound(st, dat.end(), tgt) - lower_bound(st, dat.end(), tgt);
        }
    
    cout << ans;
}