#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> a, b, c, d;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    a = vector<int>(n); b = vector<int>(n);
    c = vector<int>(n); d = vector<int>(n);
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i] >> d[i];

    vector<int> ab, cd;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            ab.push_back(a[i] + b[j]);
            cd.push_back(c[i] + d[j]);
        }
    sort(ab.begin(), ab.end());
    sort(cd.begin(), cd.end()); // for cache-hit ratio
    
    long long ans = 0;
    for(int i = 0; i < (int)cd.size(); i++)
    {
        int t = -cd[i];
        ans += (upper_bound(ab.begin(), ab.end(), t) - lower_bound(ab.begin(), ab.end(), t));
    }

    cout << ans << "\n";
}