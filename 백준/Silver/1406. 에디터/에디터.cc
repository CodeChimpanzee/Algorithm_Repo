#include<iostream>
#include<string>
#include<list>

using namespace std;

int main(void)
{
    int M;
    string s;
    list<char> l;

    cin >> s;
    for(char c : s)
        l.push_back(c);

    cin >> M;
    list<char>::iterator lp = l.end();
    for(int i = 0; i < M; i++)
    {
        char command;
        cin >> command;
        
        switch (command)
        {
        case 'L':
        if(lp != l.begin())
            lp--;
        break;

        case 'D':
        if(lp != l.end())
            lp++;
        break;

        case 'B':
        if(lp != l.begin())
            lp = l.erase(--lp);
        break;

        case 'P':
        char t;
        cin >> t;
        l.insert(lp, t);
        break;

        default:
            // UNEXPECTED INPUT
            break;
        }
    }
    
    for(char c : l)
        cout << c;
}