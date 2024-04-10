#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main()
{
    string s; cin >> s;
    stack<char> k;
    int depth = 0, a[20] = {0};

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '(' || s[i] == '[')
        {
            k.push(s[i]);
            a[++depth] = 0;
        }
        else if(!k.empty()) // ')' or ']'
        {
            if(k.top() == '(' && s[i] == ')')
            {
                if(s[i-1] == '(')
                {
                    a[depth - 1] += 2;
                }
                else
                {
                    a[depth - 1] += a[depth] * 2 ;
                }
            }
            else if(k.top() == '[' && s[i] == ']')
            {
                if(s[i-1] == '[')
                {
                    a[depth - 1] += 3;
                }
                else
                {
                    a[depth - 1] += a[depth] * 3 ;
                }
            }
            else
            {
                a[0] = 0;
                break;
            }
            k.pop();
            depth--;
        }
        else
        {
            a[0] = 0;
            break;
        }
    }

    if(!k.empty()) a[0] = 0;
    cout << a[0];
}