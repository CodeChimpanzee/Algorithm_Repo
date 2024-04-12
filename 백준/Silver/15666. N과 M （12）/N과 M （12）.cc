#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void find_seq(int depth, int st);
vector<int> dat;
int ans[9];
bool visit[9] = {false};
int n, m;

int main()
{
    cin >> n >> m;
    bool num[10000] = {false};
    for(int i = 0; i < n; i++)
    {
        int t; cin >> t;
        if(num[t]) continue;
        dat.push_back(t);
        num[t] = true;
    }
    sort(dat.begin(), dat.end());
    ans[0] = dat[0];
    find_seq(0, 0);
}

void find_seq(int depth, int st)
{
    if(depth == m)
    {
        for(int i = 0; i < m; i++)
            cout << ans[i] << " ";
        cout << "\n";
        return; 
    }
    for(int i = st; i < dat.size(); i++)
    {
        ans[depth] = dat[i];
        find_seq(depth + 1, i);
    }
}