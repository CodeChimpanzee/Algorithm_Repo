#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int main()
{
    int t; cin >> t;
    cout.setf(ios::fixed);
    cout.precision(14);
    while(t--)
    {
        int n; cin >> n;
        vector<pair<int, int>> points = vector<pair<int, int>>(n);
        for(int i = 0; i < n; i++)
            cin >> points[i].first >> points[i].second;

        vector<int> comb = vector<int>(n, 0);
        for(int i = 0; i < n / 2; i++)
            comb[i] = 1;
        
        double ans = 1e9;
        do
        {
            double sumx = 0, sumy = 0;
            for(int i = 0; i < n; i++)
            {
                sumx += (double)points[i].first * (comb[i] ? 1 : -1);
                sumy += (double)points[i].second * (comb[i] ? 1 : -1);
            }
            ans = min(ans, sqrt((sumx * sumx) + (sumy * sumy)));
        } while (prev_permutation(comb.begin(), comb.end()));

        cout << ans << "\n";       
    }
}