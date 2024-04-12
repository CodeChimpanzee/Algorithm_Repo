#include<iostream>

using namespace std;

void find_seq(int depth);

int dat[9];

int n, m;

int main()
{
    cin >> n >> m;
    dat[0] = 1;
    find_seq(0);
}

void find_seq(int depth)
{
    if(depth == m)
    {
        for(int i = 1; i <= m; i++)
            cout << dat[i] << " ";
        cout << "\n";
        return;
    }
    for(int i = dat[depth]; i <= n; i++)
    {
        dat[depth + 1] = i;
        find_seq(depth + 1);
    }
}