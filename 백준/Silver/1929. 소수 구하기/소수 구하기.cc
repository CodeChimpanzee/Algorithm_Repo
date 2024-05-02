#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

vector<int> prime;
int m, n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;

    prime.push_back(2);
    for(int i = 3; i <= n; i++)
    {
        bool is_p = true;
        int lim = (int)sqrt(i);
        for(int p : prime)
        {
            if(i % p == 0)
            {
                is_p = false;
                break;
            }
            if(p > lim)
                break;
        }
        if(is_p)
            prime.push_back(i);
    }

    for(int p : prime)
    {
        if(p < m) continue;
        cout << p << "\n";
    }
}