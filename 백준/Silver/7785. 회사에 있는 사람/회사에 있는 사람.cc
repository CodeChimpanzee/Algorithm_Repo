#include<iostream>
#include<string>
#include<map>

using namespace std;

map<string, bool, greater<string>> emp;
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string t1, t2; cin >> t1 >> t2;
        if(t2[0] == 'e')
            emp[t1] = true;
        else
            emp[t1] = false;
    }

    for(auto e : emp)
        if(e.second)
            cout << e.first << "\n";
}