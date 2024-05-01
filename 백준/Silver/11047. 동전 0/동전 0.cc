#include<iostream>

using namespace std;

int coin[11];
int n, k;

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> coin[i];

    int ans = 0;
    for(int i = n; i >= 1; i--)
    {
        while(coin[i] <= k)
        {
            k -= coin[i];
            ans++;
        }
    }

    cout << ans << "\n";
}