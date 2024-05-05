#include<iostream>
#include<algorithm>

using namespace std;

int dat[500001];

int xbinsearch(int st, int ed, int t)
{
    while(st + 1 < ed)
    {
        int md = (st + ed) / 2;
        if(dat[md] > t)
            ed = md;
        else
            st = md; 
    }
    return dat[st];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n; dat[0] = -10000001;
    for(int i = 1; i <= n; i++)
        cin >> dat[i];
    sort(dat, dat + n + 1);

    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int t; cin >> t;
        cout << (xbinsearch(0, n + 1, t) == t) << " ";
    }
}