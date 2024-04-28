#include<iostream>
#include<numeric>
#include<vector>

using namespace std;

vector<vector<int>> dp = vector<vector<int>>(1001, vector<int>(10));
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i <= 9; i++)
        dp[1][i] = 1;

    for(int i = 2; i <= 1000; i++)
        for(int j = 0; j <= 9; j++)
            dp[i][j] = accumulate(dp[i - 1].begin() + j, dp[i - 1].end(), 0) % 10007;

    cout << accumulate(dp[n].begin(), dp[n].end(), 0) % 10007;
}