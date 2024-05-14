#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int t, k;
    int nmax = 501;
    cin >> t;
    while(t--)
    {
    	cin >> k;
        vector<int> dat(k + 1);
        for(int i = 0; i < k; i++)
            cin >> dat[i];
        dat[k] = nmax;
        
        int idx = 0, ans = 0;
        vector<int> ansvec;
        
        for(int i = 0; i < k; i++)
        {
         	swap(dat[i], dat[k]);
            ans++; ansvec.push_back(i + 1);
            idx = find(dat.begin(), dat.end(), i + 1) - dat.begin();
            swap(dat[i], dat[idx]);
            ans++; ansvec.push_back(idx + 1);
            if(idx != k)
            {
                swap(dat[idx], dat[k]);
                ans++; ansvec.push_back(k + 1);
            }
        }
        
        cout << ans << "\n";
        for(int a : ansvec)
            cout << a << " ";
        cout << "\n";
    }
    
    return 0;
}