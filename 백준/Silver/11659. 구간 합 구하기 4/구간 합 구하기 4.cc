#include<iostream>

using namespace std;

int dat[100001];
int sum_front[100002], sum_back[100002];
int sum_total = 0;
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> dat[i];
        sum_total += dat[i];
    }

    sum_front[0] = 0;
    sum_front[1] = dat[1];
    sum_back[n + 1] = 0;
    sum_back[n] = dat[n];
    for(int i = 2; i <= n; i++)
    {
        sum_front[i] = sum_front[i - 1] + dat[i];
        sum_back[n - i + 1] = sum_back[n - i + 2] + dat[n - i + 1];
    }

    for(int i = 1; i <= m; i++)
    {
        int from, to; cin >> from >> to;
        cout << sum_total - sum_front[from - 1] - sum_back[to + 1] << "\n";
    }
}