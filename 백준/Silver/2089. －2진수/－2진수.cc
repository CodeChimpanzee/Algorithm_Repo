#include<iostream>
#include<string>

using namespace std;

int main()
{
    int n; cin >> n;
    string ans ="";
    
    if(n == 0) cout << "0";

    while(n != 0)
    {
        int div = n / -2;
        int rem = n - div * -2;

        if(rem == -1)
        {
            div++;
            rem = n - div * -2;
        }

        if(rem == 1)
            ans = "1" + ans;
        else if (rem == 0)
            ans = "0" + ans;
        
        n = div;
    }
    cout << ans;
}