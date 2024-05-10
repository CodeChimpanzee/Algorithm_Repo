#include<iostream>

using namespace std;

int dat[10001];
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> dat[i];

    int st = 0, ed = 0;
    int psum = dat[0], ans = 0;
    while(ed < n)
    {
        if(psum > m)
        {
            psum -= dat[st];
            st++;
        }   
        else
        {
            if(psum == m) ans++;
            ed++;
            psum += dat[ed];
        }
    }
    
    cout << ans << "\n";
}