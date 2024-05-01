#include<iostream>
#include<algorithm>

using namespace std;

int pp[1000];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> pp[i];

    sort(pp, pp + n);

    int ans = pp[0];
    for(int i = 1; i < n; i++)
    {
        pp[i] += pp[i - 1];
        ans += pp[i];
    }
    cout << ans << "\n";
}