#include<iostream>

using namespace std;
using ll = long long;

pair<ll, pair<ll, ll>> xGCD(ll a, ll b)
{
    ll r0 = a, r1 = b;
    ll s0 = 1, s1 = 0;
    ll t0 = 0, t1 = 1;
    ll q;
    ll tmp;
    while(r1)
    {
        q = r0 / r1;

        tmp = r1;
        r1 = r0 % r1;
        r0 = tmp;

        tmp = s1;
        s1 = s0 - q * s1;
        s0 = tmp;

        tmp = t1;
        t1 = t0 - q * t1; 
        t0 = tmp;
    }
    return {r0, {s0, t0}};
}

int main()
{
    ll n, a;
    cin >> n >> a;
    auto g = xGCD(a, n);
    cout << n - a << " ";
    if(g.first == 1)
        cout << (g.second.first + n) % n << "\n";
    else
        cout << -1 << "\n";
}