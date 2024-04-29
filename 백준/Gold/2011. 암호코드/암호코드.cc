#include<iostream>
#include<string>
#define DIV 1000000

using namespace std;

int dp[5001];
string code;

int main()
{
    cin >> code;
    code = '0' + code;

    dp[0] = 1;
    for(int i = 1; i <= code.length(); i++)
    {
        if(code[i] != '0')
           dp[i] += dp[i - 1];
        int t = stoi(code.substr(i - 1, 2));
        if(t >= 10 && t <= 26)
            dp[i] += dp[i - 2];
        dp[i] %= DIV;
    }

    cout << dp[code.length()] << "\n";
}