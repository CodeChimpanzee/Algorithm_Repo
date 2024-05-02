#include<iostream>

using namespace std;

int gcd(int n, int m)
{
    if(m == 0) return n;
    return gcd(m, n % m);
}

int lcm(int n, int m)
{
    return n / gcd(n, m) * m;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--)
    {
        int m, n, x, y; cin >> m >> n >> x >> y;
        int ans = -1;
        for(int i = x; i <= lcm(m, n); i += m)
            if(i % n == y % n)
                ans = i;
        cout << ans << "\n";
    }
}