#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main (void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    vector<int> alpha(26);
    cin >> s;

    for(int i = 0; i < s.length(); i++)
    {
        alpha[s[i] - 'a']++;
    }

    for(int i : alpha)
    {
        cout << i << " ";
    }
}