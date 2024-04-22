#include<iostream>

using namespace std;

int dp[1000005];
int pre[1000005];

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    dp[1] = 0;
    pre[1] = 0;
    for(int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1;
        pre[i] = i - 1;
        
        if(i % 2 == 0 && dp[i] > dp[i / 2] + 1)
        {
            dp[i] = dp[i / 2] + 1;
            pre[i] = i / 2;
        }
        
        if(i % 3 == 0 && dp[i] > dp[i / 3] + 1)
        {
            dp[i] = dp[i / 3] + 1;
            pre[i] = i / 3;
        }
    }

    cout << dp[n] << "\n";
    int idx = n;
    cout << n << " ";
    while(idx > 1)
    {
        cout << pre[idx] << " ";
        idx = pre[idx];
    }
}