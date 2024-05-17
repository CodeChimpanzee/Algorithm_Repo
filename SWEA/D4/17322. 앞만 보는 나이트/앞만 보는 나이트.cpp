#include<iostream>

using namespace std;
using ll = long long;

ll divp = 1e9 + 7;
ll facto[1000001];
int inv_mat[2][2] = {{2, -1},{-1, 2}};

ll mod_inv(ll a, ll p)
{
    if(p == 0) return 1;
    if(p & 1) return (mod_inv(a, p - 1) * a) % divp;
    ll half = mod_inv(a, p/2);
    return (half * half) % divp;
}

int main()
{
    facto[0] = 1;
    for(int i = 1; i <= 1000000; i++)
        facto[i] = (facto[i-1] * i) % divp;
    
    int t; cin >> t;
    for(int q = 1; q <= t; q++)
    {
     	int x, y; cin >> x >> y;
        int ox = inv_mat[0][0] * x + inv_mat[0][1] * y;
        int oy = inv_mat[1][0] * x + inv_mat[1][1] * y;
        
        cout << "#" << q << " ";
        if((ox % 3) || (oy % 3) || (ox < 0) || (oy < 0))
        {
            cout << "0" << "\n";
            continue;
        }
        
        int iox = ox / 3, ioy = oy / 3;
        ll ans = (facto[iox + ioy] * mod_inv(facto[iox], divp - 2)) % divp;
        ans = (ans * mod_inv(facto[ioy], divp - 2)) % divp;
        cout << ans << "\n";
    }
}