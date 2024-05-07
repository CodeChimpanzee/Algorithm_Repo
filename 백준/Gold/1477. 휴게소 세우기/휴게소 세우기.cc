#include<iostream>
#include<algorithm>

using namespace std;

int dat[53];
int n, m, l;

int parametric_search(int st, int ed, int t)
{
    while(st < ed)
    {
        int md = (st + ed) / 2;
        int mn = 0;
        for(int i = 0; i <= n; i++)
            mn += (dat[i] - 1) / md;
        
        if(mn > t)
            st = md + 1;
        else
            ed = md;
    }
    return st;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> l;
    dat[0] = 0; dat[n + 1] = l;
    for(int i = 1; i <= n; i++)
        cin >> dat[i];
    sort(dat, dat + n + 2);
    
    for(int i = 0; i <= n; i++)
        dat[i] = dat[i + 1] - dat[i];

    cout << parametric_search(1, l, m) << "\n";
}