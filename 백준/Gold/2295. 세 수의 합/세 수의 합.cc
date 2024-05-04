#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> dat, xy;
vector<pair<int, int>> kz;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for(int i = 0; i < n; i++)
    {
        int t; cin >> t;
        dat.push_back(t);
    }
    sort(dat.begin(), dat.end());

    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
            xy.push_back(dat[i] + dat[j]);
    sort(xy.begin(), xy.end());
    xy.erase(unique(xy.begin(), xy.end()), xy.end());
    
    for(int i = n - 1; i >= 0; i--)
        for(int j = i; j >= 0; j--)
            kz.push_back({dat[i] - dat[j], dat[j]});
    
    int ans = 0;
    for(auto p : kz)
    {
        if(binary_search(xy.begin(), xy.end(), p.first))
            ans = max(ans, p.first + p.second);
    }
    cout << ans << "\n";
}