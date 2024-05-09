#include<iostream>

using namespace std;

int dat[100001];
int n, s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s;
    for(int i = 0; i < n; i++)
        cin >> dat[i];

    int st = 0, ed = 0;
    int psum = dat[0], ans = 100001;
    while(st <= ed && ed < n)
    {
        if(psum >= s)
        {
            psum -= dat[st];
            ans = min(ans, ed - st + 1);
            st++;
        }
        else
        {
            ed++;
            psum += dat[ed];
        }
    }
    cout << (ans == 100001 ? 0 : ans) << "\n";
}
