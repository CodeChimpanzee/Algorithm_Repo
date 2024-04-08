#include<iostream>
#include<stack>

#define HMAX 100000001

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    stack<pair<int, int>> tower;
    tower.push({0, HMAX}); 

    int n, h;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> h;
        while(tower.top().second < h)
            tower.pop();
        cout << tower.top().first << " ";
        tower.push({i, h});
    }
}
