#include<iostream>

using namespace std;

int dp[10001];
int dat[10001];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> dat[i];
        dp[i] = dat[i];
    }

    dp[0] = 0;
    for(int i = 2; i <= n; i++)
    {
        for(int j = i; j >= 1; j--)
        {
            dp[i] = max(dp[i], dp[j] + dp[i - j]);
        }
    }

    cout << dp[n] << "\n";
}