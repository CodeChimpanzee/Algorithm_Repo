#include<iostream>

using namespace std;
using ll = long long;

int cable[10001];
int k, n;

ll parametric_search(ll st, ll ed, ll tgt)
{
    ll mid, mn;

    while(st + 1 < ed)
    {
        mid = (st + ed) / 2;

        mn = 0;
        for(int i = 0; i < k; i++)
            mn += cable[i] / mid;

        if(mn > tgt)
            st = mid;
        else
            ed = mid;
    }

    return st;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll imax = (1LL << 31);
    cin >> k >> n;
    for(int i = 0; i < k; i++)
        cin >> cable[i];
    
    cout << parametric_search(1, imax, n - 1);
}