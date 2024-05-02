#include<iostream>

using namespace std;

int n, k;

int main()
{
    cin >> n >> k;
    int ans = 1;
    for(int i = n; i > n - k; i--)
        ans *= i;
    for(int i = 2; i <= k; i++)
        ans /= i;
    cout << ans;
}