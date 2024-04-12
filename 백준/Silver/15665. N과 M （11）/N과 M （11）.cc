#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dat[10];
int ans[10];
int n, m;
int cnt = 0;

void find_seq(int depth);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    fill(dat, dat+10, 10000);
    bool dupli[10001] = {false};
    for(int i = 0; i < n; i++)
    {
        int t; cin >> t;
        if(!dupli[t])
        {
            dat[i] = t;
            dupli[t] = true;
            cnt++;
        }
    }

    sort(dat, dat + n);
    find_seq(0);
}

void find_seq(int depth)
{
    if(depth == m)
    {
        for(int i = 0; i < m; i++)
            cout << ans[i] << " ";
        cout << '\n';
        return;
    }

    for(int i = 0; i < cnt; i++)
    {
        ans[depth] = dat[i]; 
        find_seq(depth + 1);
    }
}