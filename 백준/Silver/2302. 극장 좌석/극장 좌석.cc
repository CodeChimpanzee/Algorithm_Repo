#include<iostream>

using namespace std;

int dp[41];
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    dp[1] = 1; dp[2] = 2;
    for(int i = 3; i <= 40; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    int st = 0, ans = 1;
    for(int i = 0; i < m; i++)
    {
        int t; cin >> t;
        int seat_cnt =  max(t - st - 1, 1);

        ans *= dp[seat_cnt];
        st = t;
    }
    ans *= dp[max(n - st, 1)];

    cout << ans << "\n";
}