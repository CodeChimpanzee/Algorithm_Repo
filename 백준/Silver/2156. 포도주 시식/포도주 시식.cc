#include<iostream>

using namespace std;

int dat[10001];
int dp[10001][2];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> dat[i];

    dp[1][0] = dat[1]; dp[1][1] = 0;
    dp[2][0] = dat[2]; dp[2][1] = dat[1] + dat[2];
    for(int i = 3; i <= n; i++)
    {
        for(int j = 1; j < i - 1; j++)
        {
            dp[i][0] = max(dp[i][0], max(dp[j][0], dp[j][1]) + dat[i]);
        }
        dp[i][1] = dp[i - 1][0] + dat[i];
    }

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans = max(ans, dp[i][0]);
        ans = max(ans, dp[i][1]);
    }

    cout << ans << "\n";
}