#include<iostream>
#include<stack>
#include<vector>
#include<string>

using namespace std;

int main()
{
    stack<int> s;
    string output = "";
    int n, k, cnt = 0, target = 1;

    cin >> n;
    s.push(target++);
    output += "+\n";

    while(cnt < n)
    {
        cnt++;
        cin >> k;
        if(target <= k)
        {
            for(int i = target; i <= k; i++)
            {
                s.push(i);
                output += "+\n";
            }
            s.pop();
            output += "-\n";
            target = k+1;
        }
        else
        {
            if(s.top() == k)
            {
                s.pop();
                output += "-\n";
            }
            else
            {
                output = "NO";
                break;
            }
        }
    }

    cout << output;
}