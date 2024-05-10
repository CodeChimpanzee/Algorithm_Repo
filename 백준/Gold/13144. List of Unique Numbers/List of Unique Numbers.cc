#include<iostream>

using namespace std;

bool flag[100001];
int dat[100001];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> dat[i];

    int st = 0, ed = 0;
    long long ans = 0;
    for(; ed < n; ed++)
    {
        while(flag[dat[ed]])
            flag[dat[st++]] = false;
        ans += (ed - st + 1);
        flag[dat[ed]] = true;
    }
    cout << ans << "\n";
}