#include<iostream>

using namespace std;

int dat[20];
int n, s;
int cnt = 0;

void sum_of_part(int depth, int st, int k);

int main()
{
    cin >> n >> s;
    for(int i = 0; i < n; i++)
        cin >> dat[i];
    sum_of_part(0, 0, 0);
    cout << cnt;
}

void sum_of_part(int depth, int st, int k)
{
    if(depth > 0 && k == s) cnt++;
    for(int i = st; i < n; i++)
    {
        sum_of_part(depth + 1, i + 1, k + dat[i]);
    }
}