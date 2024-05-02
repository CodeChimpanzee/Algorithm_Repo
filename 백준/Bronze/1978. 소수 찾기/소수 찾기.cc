#include<iostream>
#include<cmath>

using namespace std;

int n;
int dat[101];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> dat[i];
    
    int ans = 0;
    for(int i = 0; i < n ;i++)
    {
        bool is_p = (dat[i] > 1) ? true : false;
        for(int j = 2; j <= (int)sqrt(dat[i]); j++)
            if(dat[i] % j == 0)
                is_p = false;
        if(is_p)
            ans++;
    }

    cout << ans << "\n";
}