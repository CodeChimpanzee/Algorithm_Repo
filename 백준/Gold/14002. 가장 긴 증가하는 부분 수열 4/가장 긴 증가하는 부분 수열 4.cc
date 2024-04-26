#include<iostream>
#include<vector>

using namespace std;

int dat[1001];
int dp[1001];
int trace[1001];

vector<int> ans;
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> dat[i];
        dp[i] = 1;
        trace[i] = i;
    }

    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j < i; j++)
        {
            if(dat[j] < dat[i] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                trace[i] = j;
            }
        }
    }

    int argmax = 1, max_len = 0;
    for(int i = 1; i <= n; i++)
        if(max_len < dp[i])
        {
            max_len = dp[i];
            argmax = i;
        }

    cout << max_len << "\n";
    int t = argmax;
    while(trace[t] != t)
    {
        ans.push_back(dat[t]);
        t = trace[t];
    }
    ans.push_back(dat[t]);

    for(int i = 0; i < ans.size(); i++)
        cout << ans[ans.size() - i - 1] << " ";
}