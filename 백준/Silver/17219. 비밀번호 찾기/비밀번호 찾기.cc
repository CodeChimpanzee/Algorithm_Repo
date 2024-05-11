#include<iostream>
#include<unordered_map>

using namespace std;

unordered_map<string, string> ipair;
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string t1, t2; cin >> t1 >> t2;
        ipair[t1] = t2;
    }

    for(int i = 0; i < m; i++)
    {
        string q; cin >> q;
        cout << ipair[q] << "\n";
    }
}
