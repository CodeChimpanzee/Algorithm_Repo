#include<iostream>
#include<queue>
#include<string>

using namespace std;

int main()
{
    int n; cin >> n;
    queue<int> q;
    string op;

    while(n--)
    {
        cin >> op;

        if(op.compare("push") == 0)
        {
            int t; cin >> t;
            q.push(t);
        }
        else if(op.compare("pop") == 0)
        {
            if(q.size() == 0)
                cout << "-1\n";
            else
            {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if(op.compare("size") == 0)
        {
            cout << q.size() << "\n";
        }
        else if(op.compare("empty") == 0)
        {
            cout << (q.size() == 0 ? 1 : 0) << "\n";
        }
        else if(op.compare("front") == 0)
        {
            if(q.size() == 0)
                cout << "-1\n";
            else
                cout << q.front() << "\n";
        }
        else if(op.compare("back") == 0)
        {
            if(q.size() == 0)
                cout << "-1\n";
            else
                cout << q.back() << "\n";
        }
    }
}