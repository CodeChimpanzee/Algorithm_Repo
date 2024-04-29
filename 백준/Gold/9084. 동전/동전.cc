#include<iostream>

using namespace std;

int dp[10001];
int coin[21];
int t, n, money;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> coin[i];
        cin >> money;
        fill(dp, dp + money + 1, 0);

        dp[0] = 1;
        for(int i = 1; i <= n; i++)
            for(int j = coin[i]; j <= money; j++)
                dp[j] += dp[j - coin[i]];

        cout << dp[money] << "\n";  
    }
}