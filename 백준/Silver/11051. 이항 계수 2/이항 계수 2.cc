#include<iostream>

using namespace std;

int dp[1001][1001];
int n, k;

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= 1000; i++)
    {
        dp[i][0] = 1;
        for(int j = 1; j < i; j++)
        {  
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007; 
        }
        dp[i][i] = 1;
    }
    cout << dp[n][k] << "\n";
}