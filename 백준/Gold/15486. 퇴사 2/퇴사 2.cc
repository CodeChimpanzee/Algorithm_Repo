#include<iostream>
#define SMAX 1500005

using namespace std;

int t[1500005], p[1500005];
int dp[1500005];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> t[i] >> p[i];

    dp[n] = t[n] == 1 ? p[n] : 0;
    for(int i = n - 1; i >= 1; i--)
    {
        if(i + t[i] > n + 1)
        {
            dp[i] = dp[i + 1]; 
        }
        else
        {
            dp[i] = max(dp[i + t[i]] + p[i], dp[i + 1]);
        }
    }

    cout << dp[1] << "\n";
}