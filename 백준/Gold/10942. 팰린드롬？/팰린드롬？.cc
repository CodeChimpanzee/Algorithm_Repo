#include<iostream>

using namespace std;

bool dp[2001][2001];
int seq[2001];
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> seq[i];

    for(int i = 0; i <= n - 1; i++)
        for(int j = 1; j <= n - i; j++)
            if(seq[j] == seq[j + i])
            {
                if(i < 2)
                    dp[j][j + i] = true;
                else if(dp[j + 1][j + i - 1])
                    dp[j][j + i] = true;
            }

    cin >> m;
    while(m--)
    {
        int s, e; cin >> s >> e;
        cout << dp[s][e] << "\n";
    }
}