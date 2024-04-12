#include<iostream>

using namespace std;

void find_seq(int depth);

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
        dat[depth] = i + 1;
        find_seq(depth + 1);
    }
}