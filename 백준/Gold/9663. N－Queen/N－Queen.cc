#include<iostream>

using namespace std;

int n;
bool column[16] = {false};
bool diagu[32] = {false}, diagd[32] = {false};
int nqueen(int depth);

int main()
{
    cin >> n;
    cout << nqueen(0);
}

int nqueen(int depth)
{
    if(depth == n) return 1;

    int tsum = 0;
    //depth 행 i열에 놓을 수 있는가

    for(int i = 0; i < n; i++)
    {
        if(column[i] || diagd[depth+i] || diagu[n-depth+i]) continue;
        column[i] = true;
        diagd[depth+i] = true;
        diagu[n-depth+i] = true;
        tsum += nqueen(depth + 1);
        column[i] = false;
        diagd[depth+i] = false;
        diagu[n-depth+i] = false;
    }
    return tsum;
}