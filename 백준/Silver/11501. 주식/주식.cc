#include<iostream>

using namespace std;

int stock[1000001];
int t, n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> stock[i];

        long long sum = 0;
        int smax = stock[n - 1];
        for(int i = n - 1; i >= 1; i--)
        {
            sum += max(smax - stock[i - 1], 0);
            smax = max(smax, stock[i - 1]);
        }

        cout << sum << "\n";
    }
}