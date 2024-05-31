#include<iostream>

using namespace std;
int comb[30][30];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    comb[1][0] = 1; comb[1][1] = 1;
    for(int i = 2; i < 30; i++)
    {
        comb[i][0] = 1;
        comb[i][i] = 1;
        for(int j = 1; j < i; j++)
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
    }

    while(t--)
    {
        int w, e; cin >> w >> e;
        cout << comb[e][w] << "\n";
    }
}