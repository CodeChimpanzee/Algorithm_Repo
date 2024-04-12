#include<iostream>

using namespace std;

void find_seq(int k);
int dat[8];
bool visit[8] = {false};
int n, m; 

int main()
{
    cin >> n >> m;
    find_seq(0);
}

void find_seq(int depth)
{
    if(depth == m)
    {
        for(int i = 0; i < m; i++)
            cout << dat[i] << " ";
        cout << "\n";
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(visit[i]) continue;
        dat[depth] = i+1;
        visit[i] = true;
        find_seq(depth + 1);
        visit[i] = false;
    }
}