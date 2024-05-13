#include<iostream>
#include<set>

using namespace std;

set<int> ns;
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int t; cin >> t;
        ns.insert(t);
    }

    for(int i = 1; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            int t; cin >> t;
            ns.insert(t);
            ns.erase(ns.begin());
        }

    cout << *ns.begin() << "\n";
}