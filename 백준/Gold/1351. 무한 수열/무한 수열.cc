#include<iostream>
#include<unordered_map>

using namespace std;
using ll = long long;

unordered_map<ll, ll> memo;

ll n, p, q;
ll solve(ll num)
{
    if(memo.find(num) != memo.end())
        return memo[num];

    ll m = solve(num / p) + solve(num / q); 
    memo[num] = m;
    return m;
}

int main()
{
    cin >> n >> p >> q;
    memo[0] = 1;
    cout << solve(n) << "\n";
}