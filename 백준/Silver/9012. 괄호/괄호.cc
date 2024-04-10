#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    while(n--)
    {
        string s; cin >> s;
        stack<char> k;

        for(int i = 0; i < s.length(); i++)
        {
            if(!k.empty() && (k.top() == '(') && (s[i] == ')')) k.pop();
            else k.push(s[i]);
        }

        cout << (k.empty() ? "YES\n" : "NO\n");
    }
}