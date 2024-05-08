#include<iostream>
#include<vector>

#define AMAX 10

using namespace std;

bool bar[12][35];
int n, m, h;

bool solve_match()
{
    for(int i = 1; i <= n; i++)
    {
        int cur = i;
        for(int j = 1; j <= h; j++)
        {
            if(bar[cur - 1][j]) cur--;
            else if(bar[cur][j]) cur++;
        }
        if (cur != i)
            return false;
    }
    return true;
}

int solve_ladder(int ii, int jj, int add_cnt)
{
    if(add_cnt > 3)
        return AMAX;
    if(solve_match())
        return add_cnt;

    int ans = AMAX;
    for(int i = ii; i < n; i++, jj = 1)
        for(int j = jj; j <= h; j++)
        {
            if(bar[i - 1][j] || bar[i][j] || bar[i + 1][j]) continue;
            bar[i][j] = true;
            ans = min(ans, solve_ladder(i, j + 1, add_cnt + 1));
            bar[i][j] = false;
        }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> h;
    for(int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        bar[b][a] = true;
    }
    
    int ans = solve_ladder(1, 1, 0);
    cout << (ans == AMAX ? -1 : ans) << "\n";
}