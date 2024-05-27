#include<iostream>

using namespace std;

int pow_seg(int a, int b)
{
    if(b == 1) return a % 10;
    int mp = (b & 1 ? a : 1);
    return (pow_seg(a, b/2) * pow_seg(a, b/2) * mp) % 10; 
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int a, b; cin >> a >> b;
        int ans = pow_seg(a, b);
        cout << (ans == 0 ? 10 : ans) << "\n";
    }
}