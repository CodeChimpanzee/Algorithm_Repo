#include<iostream>
#include<algorithm>

#define IMAX 1000000001

using namespace std;
using ll = long long;

int snack[1000001];
int m, n;

ll parametric_search(ll st, ll en, ll t)
{
    while(st + 1 < en)
    {
        ll md = (st + en) / 2;

        ll mn = 0;
        for(int i = 0; i < n; i++)
            mn += snack[i] / md;

        if(mn < t)
            en = md;
        else
            st = md;
    }

    return st;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll valid = 0;
    cin >> m >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> snack[i];
        valid += snack[i];
    }
    
    if(valid >= m)
        cout << parametric_search(1, IMAX, m);
    else
        cout << 0;
}