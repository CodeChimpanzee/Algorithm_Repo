#include<iostream>

using namespace std;

int main()
{
 	int t; cin >> t;
    for(int q = 1; q <= t; q++)
    {
     	long long a, b; cin >> a >> b;
        long long diff = b - a;
        
        cout << "#" << q << " ";
        if(diff < 0 || diff == 1) cout << "-1\n";
        else if(diff == 0) cout << "0\n";
        else cout << diff / 2 << "\n";
    }
}