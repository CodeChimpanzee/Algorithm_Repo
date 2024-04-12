#include<iostream>
#include<vector>

#define HP first
#define ATK second

using namespace std;

int n, bmax = 0;
vector<pair<int, int>> eggs;
bool broken[10] = {false};
void egg_breaker(int st, int brk);

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int s, w; cin >> s >> w;
        eggs.push_back({s, w});
    }

    egg_breaker(0, 0);
    cout << bmax;
}

void egg_breaker(int cur, int brk)
{
    if(cur == n)
    {
        if(brk > bmax) bmax = brk;
        return;
    }
    if(broken[cur] || brk == n - 1)
    {
        egg_breaker(cur + 1, brk);
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(i == cur || broken[i]) continue;

        int bcount = 0;

        eggs[cur].HP -= eggs[i].ATK;
        eggs[i].HP -= eggs[cur].ATK;

        if(eggs[i].HP <= 0)
        {
            broken[i] = true;
            bcount++;
        }

        if(eggs[cur].HP <= 0)
        {
            broken[cur] = true;
            bcount++;
        }

        egg_breaker(cur + 1, brk + bcount);
        
        broken[cur] = false;
        broken[i] = false;

        eggs[cur].HP += eggs[i].ATK;
        eggs[i].HP += eggs[cur].ATK;
    }
}
