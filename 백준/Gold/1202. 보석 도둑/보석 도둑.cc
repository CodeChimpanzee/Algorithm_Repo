#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

vector<pair<int, int>> jewel;
multiset<int> sack;
int n, k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    jewel = vector<pair<int, int>>(n);
    for(int i = 0; i < n; i++)
        cin >> jewel[i].second >> jewel[i].first;
    sort(jewel.begin(), jewel.end(), greater<pair<int, int>>());

    for(int i = 0; i < k; i++)
    {
        int t; cin >> t;
        sack.insert(t);
    }

    long long ans = 0;
    for(int i = 0; i < n; i++)
    {
        auto it = sack.lower_bound(jewel[i].second);
        if(it == sack.end()) continue;
        ans += jewel[i].first;
        sack.erase(it);
    }

    cout << ans << "\n";
}