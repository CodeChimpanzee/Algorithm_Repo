#include<iostream>

using namespace std;

int chk[200001];
int dat[200001];
int N, k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> k;
    for(int i = 0; i < N; i++)
        cin >> dat[i];

    int st = 0, ed = 0;
    int ans = 0;
    for(; ed < N; ed++)
    {
        chk[dat[ed]]++;
        while(chk[dat[ed]] > k)
            chk[dat[st++]]--;

        ans = max(ans, ed - st + 1);
    }

    cout << ans << "\n";
}