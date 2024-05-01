#include<iostream>
#include<algorithm>

using namespace std;

pair<int, int> schedule[100001];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> schedule[i].second >> schedule[i].first;

    sort(schedule + 1, schedule + n + 1);
    
    int ans = 0, cur = 0;
    for(int i = 1; i <= n; i++)
    {
        if(cur > schedule[i].second) continue;
        cur = schedule[i].first;
        ans++;
    }

    cout << ans << "\n";
}