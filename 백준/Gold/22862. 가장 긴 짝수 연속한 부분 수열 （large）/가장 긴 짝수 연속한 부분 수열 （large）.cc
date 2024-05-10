#include<iostream>

using namespace std;

int dat[1000001];
int n, k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> dat[i];

    int st = 0, ed = 0;
    int cnt = 0, ans = 0;
    for(; ed < n; ed++)
    {
        cnt += dat[ed] & 1;
        while(cnt > k && st < n)
            cnt -= dat[st++] & 1;
            
        ans = max(ans, ed - st - cnt + 1);
    }
    cout << ans << "\n";
}