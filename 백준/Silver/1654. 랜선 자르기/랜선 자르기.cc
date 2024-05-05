#include<iostream>

using namespace std;
using ll = long long;

int cable[10001];
int k, n;

ll parametric_search(ll st, ll ed, ll tgt)
{
    ll mid, mn;

    while(st < ed)
    {
        mid = (st + ed + 1) / 2;

        mn = 0;
        for(int i = 0; i < k; i++)
            mn += cable[i] / mid;

        if(mn >= tgt)
            st = mid;
        else
            ed = mid - 1;
    }

    return st;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll imax = (1 << 31) - 1;
    cin >> k >> n;
    for(int i = 0; i < k; i++)
        cin >> cable[i];
    
    cout << parametric_search(1, imax, n);
}