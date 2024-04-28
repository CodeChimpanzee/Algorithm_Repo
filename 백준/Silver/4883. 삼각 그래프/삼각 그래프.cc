#include<iostream>
#include<algorithm>

using namespace std;

int dat[100001][3];
int dp[100001][3];
int n, k = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    while(n != 0)
    {
        k++;

        for(int i = 1; i <= n; i++)
            cin >> dat[i][0] >> dat[i][1] >> dat[i][2];

        dp[1][0] = 1001; // MAX
        dp[1][1] = dat[1][1]; dp[1][2] = dp[1][1] + dat[1][2];
        for(int i = 2; i <= n; i++)
        {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + dat[i][0];
            dp[i][1] = min({dp[i][0], dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + dat[i][1];
            dp[i][2] = min({dp[i][1], dp[i - 1][1], dp[i - 1][2]}) + dat[i][2];
        }

        cout << k << ". " << dp[n][1] << "\n";
        cin >> n;
    }
}