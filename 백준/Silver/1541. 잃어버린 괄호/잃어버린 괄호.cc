#include<iostream>
#include<string>

using namespace std;

string ipt;
int ans;
int tsum[50];

int main()
{
    cin >> ipt;

    ipt = ipt + '+';
    int tmp = 0, idx = 0;
    for(int i = 0; i < ipt.length(); i++)
    {
        if(ipt[i] >= '0' && ipt[i] <= '9')
        {
            tmp *= 10;
            tmp += ipt[i] - '0';
        }
        if(ipt[i] == '+')
        {
            tsum[idx] += tmp;
            tmp = 0;
        }
        if(ipt[i] == '-')
        {
            tsum[idx] += tmp;
            tmp = 0;
            idx++;
        }
    }

    ans = tsum[0];
    for(int i = 1; i <= idx; i++)
        ans -= tsum[i];
    cout << ans << "\n";
}