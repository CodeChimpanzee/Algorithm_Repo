#include<iostream>

using namespace std;

int n, k;

int modinv(int i, int mod)
{
    int res = 1, exp = mod - 2;
    while(exp >= 1)
    {
        if(exp % 2 == 1)
            res = (res * i) % mod;
        
        exp >>= 1;
        i = (i * i) % mod;
    }
    return res;
}

int main()
{
    cin >> n >> k;
    int ans = 1;
    for(int i = 1; i <= k; i++)
    {
        ans = (ans * (n - i + 1)) % 10007;
        ans = (ans * modinv(i, 10007)) % 10007;
    }
    cout << ans << "\n";
}