#include<iostream>

using namespace std;

int count[2000002];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int t; cin >> t;
        count[t + 1000000]++;
    }
    for(int i = 0; i < 2000002; i++)
    {
        for(int j = 0; j < count[i]; j++)
        {
            cout << i - 1000000 << "\n";
        }
    }
}