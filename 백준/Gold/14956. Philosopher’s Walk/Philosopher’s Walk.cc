#include<iostream>

using namespace std;

pair<int, int> philosophers_work(int n, int m);

int main()
{
    int n, m; cin >> n >> m;
    pair<int, int> ans = philosophers_work(n, m);
    cout << ans.first << " " << ans.second << "\n";
}

pair<int, int> philosophers_work(int n, int m)
{
    if(n == 2)
    {
        switch(m)
        {
            case 1 :
            return {1, 1};
            case 2 :
            return {1, 2};
            case 3 :
            return {2, 2};
            case 4 :
            return {2, 1};
        }
    }

    int t = n * n / 4;
    pair<int, int> coord = philosophers_work(n / 2, (m - 1) % t + 1);
    switch((m - 1) / t)
    {
        case 0 :
        return {coord.second, coord.first};
        case 1 :
        return {coord.first, n / 2 + coord.second};
        case 2 :
        return {n / 2 + coord.first, n / 2 + coord.second};
        case 3 :
        return {n - coord.second + 1, n / 2 - coord.first + 1};
    }
}