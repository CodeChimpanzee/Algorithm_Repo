#include<iostream>

using namespace std;

void find_seq(int depth);
int dat[9];
bool visit[9] = {false};
int n, m;
int main()
{
    cin >> n >> m;
    dat[0] = 0;
    find_seq(0);
}

void find_seq(int depth)
{
    if(depth == m)
    {
        for(int i = 1; i <= m; i++)
            cout << dat[i] + 1 << " ";
        cout << "\n";
    }
    else
    {
        for(int i = dat[depth]; i < n; i++)
        {
            if(visit[i]) continue;
            dat[depth+1] = i;
            visit[i] = true;
            find_seq(depth + 1);
            visit[i] = false;
        }
    }
    return;
}