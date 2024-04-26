#include<iostream>

using namespace std;

long long dp[1000001];
int t, n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    dp[0] = 1; dp[1] = 1;
    dp[2] = 2; dp[3] = 4;

    for(int i = 4; i <= 1000000; i++)
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;

    while(t--)
    {
        cin >> n;
        cout << dp[n] << "\n";
    }
}