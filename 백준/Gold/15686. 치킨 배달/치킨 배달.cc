#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<pair<int, int>> home, chicken;
int n, m;

int dist(pair<int, int> &a, pair<int, int> &b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            int t; cin >> t;
            if(t == 1) home.push_back({i, j});
            if(t == 2) chicken.push_back({i, j});
        }
    
    int choose[15];
    fill(choose, choose + m, 1); // 유지
    fill(choose + m, choose + chicken.size(), 0); // 폐업

    int ans = 1e8;
    do
    {
        int asum = 0;
        for(int i = 0; i < home.size(); i++)
        {
            int dmin = 1e3;
            for(int j = 0; j < chicken.size(); j++)
            {
                if(choose[j] == 0) continue;
                int dnow = dist(home[i], chicken[j]);
                dmin = min(dmin, dnow);
            }
            asum += dmin;
        }
        ans = min(ans, asum);
    } while (prev_permutation(choose, choose + chicken.size()));

    cout << ans;
}