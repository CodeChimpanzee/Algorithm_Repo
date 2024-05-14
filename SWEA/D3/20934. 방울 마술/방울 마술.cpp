#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
 	int t; cin >> t;
    for(int i = 1; i <= t; i++)
    {
        int prodiv[3] = {0, 0, 0};
     	string s; cin >> s;
        int ans = 0;
        for(int j = 0; j < 3; j++)
            if(s[j] == 'o')
                ans = j;
        
        int k; cin >> k;
        cout << "#" << i << " ";
        if(k == 0)
            cout << ans << "\n";
        else
            cout << ((k & 1) != (ans & 1)) << "\n";
    }
}