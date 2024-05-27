#include<iostream>

using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int a, b; cin >> a >> b;
        int ans = 1;
        for(int i = 1; i <= b; i++)
            ans = (ans * a) % 10;
        cout << (ans == 0 ? 10 : ans) << "\n";
    }
}