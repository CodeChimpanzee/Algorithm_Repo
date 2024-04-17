#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int t, n, m;

int main()
{
    cin >> t;
    while(t--)
    {
        vector<int> dat_a, dat_b;
        cin >> n >> m;
        for(int i = 0; i < n; i++)
        {
            int k; cin >> k;
            dat_a.push_back(k);
        }
        for(int i = 0; i < m; i++)
        {
            int k; cin >> k;
            dat_b.push_back(k);
        }
        sort(dat_a.begin(), dat_a.end());
        sort(dat_b.begin(), dat_b.end());

        auto ita = dat_a.begin();
        auto itb = dat_b.begin();

        int ans = 0, bcnt = 1;
        while(ita != dat_a.end())
        { // A가 B보다 큰 쌍
            if(itb != dat_b.end() - 1 && *(itb + 1) < *ita) {itb++; bcnt++;}
            else
            {
                if(*ita > *itb) {ans += bcnt;}
                ita++;
            }
        }
        
        cout << ans << "\n";
    }
}