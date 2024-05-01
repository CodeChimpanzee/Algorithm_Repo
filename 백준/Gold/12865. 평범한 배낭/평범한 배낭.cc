#include<iostream>

using namespace std;

int dp[100001];
int cd[101][2]; // w, v
int n, k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> cd[i][0] >> cd[i][1];

    for(int i = 1; i <= n; i++)
        for(int j = k; j >= 1; j--)
            if(j >= cd[i][0])
                dp[j] = max(dp[j], dp[j - cd[i][0]] + cd[i][1]);

    cout << dp[k] << "\n";
}