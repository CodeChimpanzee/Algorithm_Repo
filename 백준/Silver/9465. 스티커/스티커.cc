#include<iostream>
#include<algorithm>

using namespace std;

int dp[100001][2];
int t, n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> dp[i][0];
        for(int i = 1; i <= n; i++) cin >> dp[i][1];

        dp[0][0] = 0; dp[0][1] = 0;
        for(int i = 2; i <= n; i++)
        {
            dp[i][0] += max({dp[i - 1][1], dp[i - 2][0], dp[i - 2][1]});
            dp[i][1] += max({dp[i - 1][0], dp[i - 2][0], dp[i - 2][1]});
        }

        cout << max(dp[n][0], dp[n][1]) << "\n";
    }
}