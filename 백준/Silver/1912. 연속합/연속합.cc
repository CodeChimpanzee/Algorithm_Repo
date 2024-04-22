#include<iostream>
#include<algorithm>

using namespace std;

int dp[100001];
int dat[100001];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> dat[i];

    dp[1] = dat[1];

    for(int i = 2; i <= n; i++)
        dp[i] = max(dp[i - 1] + dat[i], dat[i]);

    cout << *max_element(dp + 1, dp + 1 + n);
}