#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>

using namespace std;

unordered_map<string, int> apply_map;
int k, l;

bool cmp(pair<string, int>& a, pair<string, int>& b)
{
    return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> k >> l;
    for(int i = 0; i < l; i++)
    {
        string t; cin >> t;
        apply_map[t] = i;
    }

    vector<pair<string, int>> tvec(apply_map.begin(), apply_map.end());
    sort(tvec.begin(), tvec.end(), cmp);

    int lim = min((int)tvec.size(), k);
    for(int i = 0; i < lim; i++)
        cout << tvec[i].first << "\n";
}