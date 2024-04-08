#include<iostream>
#include<stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, t;
    stack<int> s;

    cin >> k;
    for(int i = 0; i < k; i++)
    {
        cin >> t;
        if(t != 0)
            s.push(t);
        else
            s.pop();
    }

    int sum = 0, lim = s.size();
    for(int i = 0; i < lim; i++)
    {
        sum += s.top();
        s.pop();
    }

    cout << sum;
}