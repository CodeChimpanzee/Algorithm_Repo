#include<iostream>
#include<unordered_map>

using namespace std;

int t, n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while(t--)
    {
        unordered_map<string, int> um;
        cin >> n;
        for(int i = 0; i < n; i ++)
        {
            string t1, t2; cin >> t1 >> t2;
            um[t2]++;
        }

        long long ans = 1;
        for(auto p : um)
            ans *= (p.second + 1);
        cout << ans - 1 << "\n"; 
    }
}