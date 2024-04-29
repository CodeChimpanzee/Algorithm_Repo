#include<iostream>

using namespace std;

int dp[100001];
int n;

int main()
{
    cin >> n;
    fill(dp, dp + n + 1, 1000);
    
    dp[0] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= 316; j++)
            if(i >= j * j)
                dp[i] = min(dp[i], dp[i - j * j] + 1);

    cout << dp[n] << "\n"; 
}