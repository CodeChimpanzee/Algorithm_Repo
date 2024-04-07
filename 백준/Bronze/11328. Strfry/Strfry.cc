#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool strfry_cst(string a, string b);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string sa, sb;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> sa >> sb;
        cout << (strfry_cst(sa, sb) ? "Possible\n" : "Impossible\n");
    }
}

bool strfry_cst(string a, string b)
{
    if(a.length() != b.length())
        return false;
    
    vector<int> alpha_a(26), alpha_b(26);

    for(char c : a)
        alpha_a[c - 'a']++;
        
    for(char c : b)
        alpha_b[c - 'a']++;

    for(int i = 0; i < 26; i++)
        if(alpha_a[i] != alpha_b[i])
            return false;

    return true;
}