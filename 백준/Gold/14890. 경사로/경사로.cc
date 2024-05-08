#include<iostream>

using namespace std;

int hmap[101][101];
int path[101];
int n, l;

bool check()
{
    bool occupied[101];
    fill(occupied, occupied + n, false);

    int curs = 1, curh = path[0];
    for(int i = 1; i < n; i++)
    {
        if(path[i] == curh) curs++;
        else if(path[i] < curh) {curs = 1; curh = path[i];}
        else if(path[i] == curh + 1)
        {
            if(curs < l) return false;
            for(int j = 1; j <= l; j++)
            {
                if(occupied[i - j]) return false;
                occupied[i - j] = true; 
            }
            curs = 1; curh = path[i];
        }
        else
            return false;
    }
    
    curs = 1, curh = path[n - 1];
    for(int i = n - 2; i >= 0; i--)
    {
        if(path[i] == curh) curs++;
        else if(path[i] < curh) {curs = 1; curh = path[i];}
        else if(path[i] == curh + 1)
        {
            if(curs < l) return false;
            for(int j = 1; j <= l; j++)
            {
                if(occupied[i + j]) return false;
                occupied[i + j] = true; 
            }
            curs = 1; curh = path[i];
        }
        else
            return false;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> l;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> hmap[i][j];

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            path[j] = hmap[i][j];
        ans += (check() ? 1 : 0);

        for(int j = 0; j < n; j++)
            path[j] = hmap[j][i];
        ans += (check() ? 1 : 0);
    }

    cout << ans << "\n";
}