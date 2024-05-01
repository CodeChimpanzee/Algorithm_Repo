#include<iostream>
#include<algorithm>

using namespace std;

pair<pair<int, int>, pair<int, int>> flower[100001];
int n;

bool is_prior(pair<int, int> a, pair<int, int> b)
{
    bool flag = false;
    if(a.first < b.first)
        flag = true;
    if(a.first == b.first && a.second <= b.second)
        flag = true;
    return flag;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> flower[i].first.first >> flower[i].first.second >> flower[i].second.first >> flower[i].second.second;

    sort(flower, flower + n);

    int ans = 0, i = 0;
    pair<int, int> cur = {3, 1}, nxt = {3, 1}, ed = {12, 1};
    while(!is_prior(ed, cur))
    {
        while(is_prior(flower[i].first, cur) && i < n)
        {
            if(is_prior(nxt, flower[i].second))
                nxt = flower[i].second;
            i++;
        }
        if(is_prior(nxt, cur)) {ans = 0; break;}
        cur = nxt;
        ans++;
    }

    cout << ans;
}