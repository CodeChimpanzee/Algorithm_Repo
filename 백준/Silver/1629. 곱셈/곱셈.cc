#include<iostream>

using namespace std;
using ll = long long;

ll recursive_abmodc(ll a, ll b, ll c);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a, b, c; cin >> a >> b >> c;
    cout << recursive_abmodc(a, b, c);
}

ll recursive_abmodc(ll a, ll b, ll c)
{
    if(b == 1) return a % c;
    ll t = recursive_abmodc(a, b/2, c) % c;
    t = (t * t) % c;
    if(b % 2 == 0)
        return t;
    else
        return (t * (a % c)) % c;
}