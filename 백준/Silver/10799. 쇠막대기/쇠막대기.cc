#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main()
{
    string s; cin >> s;
    stack<char> k;
    int sum = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '(')
            k.push(s[i]);
        else if(s[i-1] == '(') // s[i] == ')', laser
        {
            k.pop();
            sum += k.size();
        }
        else // bar
        {
            k.pop();
            sum += 1;
        }
    }
    cout << sum;
}