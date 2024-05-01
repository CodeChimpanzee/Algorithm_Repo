#include<iostream>
#include<algorithm>

using namespace std;

int rope[100001];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> rope[i];

    sort(rope, rope + n);
    
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, rope[i] * (n - i));
    cout << ans << "\n";
}