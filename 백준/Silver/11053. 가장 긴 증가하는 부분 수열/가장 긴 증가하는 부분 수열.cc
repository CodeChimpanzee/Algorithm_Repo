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
    {
        cin >> dat[i];
        dp[i] = 1;
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            if(dat[i] > dat[j])
                dp[i] = max(dp[i], dp[j] + 1);
    
    cout << *max_element(dp + 1, dp + 1 + n) << "\n";
}