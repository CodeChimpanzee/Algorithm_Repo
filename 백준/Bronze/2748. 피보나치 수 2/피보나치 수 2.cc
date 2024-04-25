#include<iostream>

using namespace std;

long long dp[91];
int n;

long long fibonacci(int idx)
{
    if(dp[idx] != -1)
        return dp[idx];
    dp[idx] = fibonacci(idx - 1) + fibonacci(idx - 2); 
    return dp[idx];
}

int main()
{
    cin >> n;
    for(int i = 0; i < 91; i++)
        dp[i] = -1;
    dp[0] = 0; dp[1] = 1;
    
    cout << fibonacci(n) << "\n";
}