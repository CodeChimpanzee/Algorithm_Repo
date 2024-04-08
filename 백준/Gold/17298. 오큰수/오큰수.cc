#include<iostream>
#include<stack>
#include<string>

#define HMAX 1000001

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<int> dat, mono, ans;
    int n; cin >> n;

    for(int i = 0; i < n; i++)
    {
        int t; cin >> t;
        dat.push(t);
    }

    mono.push(HMAX);
    for(int i = 0; i < n; i++)
    {
        int k = dat.top(); dat.pop();

        while(mono.top() <= k)
        {
            mono.pop();
        }

        if(mono.top() == HMAX)
            ans.push(-1);
        else
            ans.push(mono.top());

        mono.push(k);
    }

    while(ans.size() > 0)
    {
        cout << ans.top() << " ";
        ans.pop();
    }
}