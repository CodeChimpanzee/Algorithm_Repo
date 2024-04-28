#include<iostream>
#define OFS(x) (x + 1000000)
#define ABSDIV 1000000000

using namespace std;

int dp[2000002];
int n;

int main()
{
    cin >> n;
    dp[OFS(0)] = 0; dp[OFS(1)] = 1;
    for(int i = 2; i <= n; i++)
        dp[OFS(i)] = (dp[OFS(i - 1)] + dp[OFS(i - 2)]) % ABSDIV;
    for(int i = -1; i >= n; i--)
        dp[OFS(i)] = (dp[OFS(i + 2)] - dp[OFS(i + 1)]) % ABSDIV;

    if(dp[OFS(n)] == 0) {cout << 0 << "\n" << 0;}
    else {cout << (dp[OFS(n)] < 0 ? -1 : 1) << "\n" << abs(dp[OFS(n)]);}
}
