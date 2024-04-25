#include<iostream>

using namespace std;

int dat[1001];
int dp[1001][31];
int t, w;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t >> w;
    for(int i = 1; i <= t; i++)
        cin >> dat[i];
    
    dp[1][0] = (dat[1] == 1) ? 1 : 0;
    dp[1][1] = (dat[1] == 2) ? 1 : 0;

    for(int i = 2; i <= t; i++)
    {
        dp[i][0] = dp[i - 1][0] + ((dat[i] == 1) ? 1 : 0);
        for(int j = 1; j <= w; j++)
        {
            int cur_tree = (j % 2) + 1;
            int pts = (cur_tree == dat[i]) ? 1 : 0;
            dp[i][j] = max(dp[i - 1][j - 1] + pts, dp[i - 1][j]  + pts);
        }
    }

    int ans = 0;
    for(int j = 0; j <= w; j++)
        ans = max(ans, dp[t][j]);

    cout << ans << "\n";
}