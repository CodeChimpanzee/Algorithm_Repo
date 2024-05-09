#include<iostream>

using namespace std;
using ll = long long;

ll l, r, x, y;

int main()
{
    cin >> l >> r >> x >> y;
    if(l > r) swap(l, r);
    x = abs(x);
    if(!(0 <= y && y < x)) cout << "Unknwon Number\n";
    else
    {
        ll lq = l / x; // l = lq * x + lmod
        if(l < 0) lq--;

        ll nt = lq * x + y;
        if(nt < l) nt += x;

        if(nt > r || nt + x <= r) cout << "Unknwon Number\n";
        else cout << nt << "\n";
    }
}