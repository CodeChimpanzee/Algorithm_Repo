#include<iostream>
#include<algorithm>
#define INF 100001

using namespace std;

int dat[10002][2];
int dp[10002][3];
int t, n, w;

void solve()
{  
    dp[1][0] = (dat[1][0] + dat[1][1] <= w) ? 1 : 2;
    dp[1][1] = 1; dp[1][2] = 1;

    for(int i = 2; i <= n; i++)
    {
        bool bx = (dat[i][0] + dat[i][1] <= w);
        bool ux = (dat[i][0] + dat[i - 1][0] <= w);
        bool dx = (dat[i][1] + dat[i - 1][1] <= w);

        dp[i][1] = min(dp[i - 1][0] + 1, dp[i - 1][2] + 2 - ux);
        dp[i][2] = min(dp[i - 1][0] + 1, dp[i - 1][1] + 2 - dx);
        
        dp[i][0] = min({dp[i - 1][0] + 2 - bx, dp[i][1] + 1, dp[i][2] + 1, dp[i - 2][0] + 4 - ux - dx});
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while(t--)
    {
        cin >> n >> w;
        for(int r = 0; r < 2; r++)
            for(int i = 1; i <= n; i++)
                cin >> dat[i][r];

        bool ucrs = (dat[1][0] + dat[n][0] <= w);
        bool dcrs = (dat[1][1] + dat[n][1] <= w);
        if(n == 1) {ucrs = false; dcrs = false;}

        solve();
        int ans = dp[n][0];

        if(ucrs)
        {
            int tmp = dat[1][0];
            dat[1][0] = INF;

            solve();
            ans = min(ans, dp[n][2]);
            dat[1][0] = tmp;
        }
        if(dcrs)
        {
            int tmp = dat[1][1];
            dat[1][1] = INF;
            
            solve();
            ans = min(ans, dp[n][1]);
            dat[1][1] = tmp;
        } 
        if(ucrs && dcrs)
        {
            int tmp0 = dat[1][0], tmp1 = dat[1][1];
            dat[1][0] = INF; dat[1][1] = INF;
            
            solve();
            ans = min(ans, dp[n - 1][0]);
            dat[1][0] = tmp0; dat[1][1] = tmp1;
        }                         

        cout << ans << "\n";
    }
}