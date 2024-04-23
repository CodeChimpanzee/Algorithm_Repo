#include<iostream>

using namespace std;

int t[16], p[16];
int dp[16][2];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> t[i] >> p[i];

    dp[1][0] = 0;
    dp[1][1] = 1 + t[1] <= n + 1 ? p[1] : 0;
    for(int i = 2; i <= n; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        if(i + t[i] <= n + 1)
        {
            for(int j = 1; j < i; j++)
                if(j + t[j] <= i)
                    dp[i][1] = max(dp[i][1], dp[j][1]);
            dp[i][1] += p[i];
        }
    }

    cout << max(dp[n][0], dp[n][1]) << "\n";
}