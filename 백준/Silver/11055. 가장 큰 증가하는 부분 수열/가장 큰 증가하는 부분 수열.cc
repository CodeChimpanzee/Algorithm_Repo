#include<iostream>
#include<algorithm>

using namespace std;

int dat[1001];
int dp[1001];
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
    {
        int cmax = 0;
        for(int j = 1; j < i; j++)
            if(dat[j] < dat[i])
                cmax = max(dp[j], cmax);
        dp[i] = cmax + dat[i];
    }

    cout << *max_element(dp + 1, dp + n + 1) << "\n";
}