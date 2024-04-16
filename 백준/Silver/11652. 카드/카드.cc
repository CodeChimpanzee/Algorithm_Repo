#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
using ll = long long;

vector<ll> dat;
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        ll t; cin >> t;
        dat.push_back(t);
    }

    sort(dat.begin(), dat.end());

    int cmax = 0;
    int cnow = cmax;
    ll dmax = dat[0];
    ll dnow = dmax;

    for(int i = 1; i < n; i++)
    {
        if(dat[i] == dnow)
        {
            cnow++;
            if(cnow > cmax)
            {
                cmax = cnow;
                dmax = dnow;
            }
        }
        else
        {
            cnow = 0;
            dnow = dat[i];
        }
    }

    cout << dmax;
}
