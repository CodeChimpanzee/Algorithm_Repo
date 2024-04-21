#include<iostream>

using namespace std;

int dp[301];
int stairs[301];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int sum = 0;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> stairs[i];
        sum += stairs[i];
    }

    dp[0] = 0;
    dp[1] = stairs[1];
    dp[2] = stairs[2];
    for(int i = 3; i < n; i++)
    {
        dp[i] = min(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i]);
    }

    cout << sum - min(dp[n - 1], dp[n - 2]) << "\n";
}
