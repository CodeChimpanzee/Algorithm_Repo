#include<iostream>

using namespace std;

int dp[1000001];
int num;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> num;
    dp[1] = 0;
    for(int i = 2; i <= num; i++)
    {
        int tmin = dp[i-1] + 1;
        if(i % 2 == 0) tmin = min(tmin, dp[i/2] + 1);
        if(i % 3 == 0) tmin = min(tmin, dp[i/3] + 1);
        dp[i] = tmin;
    }
    cout << dp[num];
}