#include<iostream>

using namespace std;

int chk[3001];
int dat[30001];
int N, d, k, c;

int cidx(int idx, int n)
{
    return (idx + n) % n;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> d >> k >> c;
    for(int i = 0; i < N; i++)
        cin >> dat[i];

    int pnum = 1;
    chk[c]++;
    for(int i = 0; i < k; i++)
    {
        if(chk[dat[i]] == 0)
            pnum++;
        chk[dat[i]]++;
    }

    int ans = pnum;
    for(int i = 1; i < N; i++)
    {
        int st = dat[cidx(i - 1, N)];
        int ed = dat[cidx(i + k - 1, N)];
        chk[st]--;
        if(chk[st] == 0)
            pnum--;
        if(chk[ed] == 0)
            pnum++;
        chk[ed]++;

        ans = max(ans, pnum);
    }

    cout << ans << "\n";
}