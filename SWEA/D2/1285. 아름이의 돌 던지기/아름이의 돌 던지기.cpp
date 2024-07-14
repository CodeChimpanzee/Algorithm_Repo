#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int t; cin >> t;
    for(int tc = 1; tc <=t; tc++)
    {
     	int dat[1001];
        int n; cin >> n;
        for(int i = 0; i < n; i++)
        {
         	int q; cin >> q;
            dat[i] = abs(q);
        }
        sort(dat, dat + n);
        
        int ans = 0;
        for(int i = 0; i < n, dat[i] == dat[0]; i++)
            ans++;
        cout << "#" << tc << " " << dat[0] << " " << ans << "\n";
    }
}