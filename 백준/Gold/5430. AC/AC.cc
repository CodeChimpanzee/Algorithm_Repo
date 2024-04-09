#include<iostream>
#include<string>
#include<deque>

using namespace std;

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);

    int t; cin >> t;

    while(t--)
    {
        deque<int> dq;
        string op, arr, temp, ans = "";
        bool clk = true;

        cin >> op;
        int n; cin >> n;
        cin >> arr;

        if(n)
        {
            for (int i = 0; i < arr.size(); i++) 
            {
                if (isdigit(arr[i]))
                    temp += arr[i];
                else
                    if (!temp.empty())
                    {
                        dq.push_back(stoi(temp));
                        temp.clear();
                    }
            }
        }

        for(int i = 0; i < op.size(); i++)
        {
            if(op[i] == 'R')
                clk = !clk;
            else if (dq.empty())
            {
                ans = "error\n";
                break;
            }
            else if(clk)
                dq.pop_front();
            else
                dq.pop_back();
        }

        if(ans.compare("error\n") == 0)
        {
            cout << ans;
            continue;
        }
        else if(clk)
        {
            ans = "[";
            for(int i = 0; i < (int)dq.size() - 1; i++)
                ans += to_string(dq[i]) + ",";
            if(!dq.empty())
                ans += to_string(dq[dq.size() - 1]);
            ans += "]\n";
        }
        else
        {
            ans = "[";
            for(int i = (int)dq.size() - 1; i >= 1 ; i--)
                ans += to_string(dq[i]) + ",";
            if(!dq.empty())
                ans += to_string(dq[0]);
            ans += "]\n";
        }
        cout << ans;
    }
}