#include<iostream>
#include<algorithm>
#define DMIN -10000001

using namespace std;

int dat[500001];

int xbinsearch(int from, int to, int num)
{
    while(from + 1 < to)
    {
        int mid = (from + to) / 2;
        if(dat[mid] > num)
            to = mid;
        else
            from = mid;
    }
    return from;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    dat[0] = DMIN;
    for(int i = 1; i <= n; i++)
        cin >> dat[i];
    sort(dat, dat + n + 1);
        
    int m; cin >> m;
    for(int i = 0; i < m; i++)
    {
        int t; cin >> t;
        cout << xbinsearch(0, n + 1, t) - xbinsearch(0, n + 1, t - 1) << " ";
    }
}