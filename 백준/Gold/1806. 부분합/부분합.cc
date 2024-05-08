#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> dat;
int n, s;

int parametric_search(int st, int ed, int tgt)
{
    while(st < ed)
    {
        int md = (st + ed) / 2;
        int mn = 0;
        for(int i = md; i <= n; i++)
            mn = max(mn, dat[i] - dat[i - md]);
        if(mn < tgt)
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

    cin >> n >> s;
    dat = vector<int> (n + 1);
    dat[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        int t; cin >> t;
        dat[i] = t + dat[i - 1];
    }

    cout << (dat[n] >= s ? parametric_search(1, n, s) : 0) << "\n";
}