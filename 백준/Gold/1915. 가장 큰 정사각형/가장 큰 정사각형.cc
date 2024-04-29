#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int dp[1001][1001];
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        string t; cin >> t;
        for(int j = 1; j <= m; j++)
            if(t[j - 1] == '1')
            {
                dp[i][j] = min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1;
                ans = max(ans, dp[i][j]);
            }
    }

     cout << ans * ans << "\n";
}