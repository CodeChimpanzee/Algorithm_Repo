#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

unordered_map<string, int> sdic;
vector<string> idic;
int n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string t; cin >> t;
        sdic[t] = i + 1;
        idic.push_back(t);
    }

    for(int i = 0; i < m; i++)
    {
        string q; cin >> q;
        if(isdigit(q[0]))
            cout << idic[stoi(q) - 1] << "\n";
        else
            cout << sdic[q] << "\n";
    }
}