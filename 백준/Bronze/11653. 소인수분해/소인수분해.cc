#include<iostream>
#include<vector>

using namespace std;

int n;
bool is_c[4000];
vector<int> prime;

int main()
{
    cin >> n;
    for(int i = 2; i < 4000; i++)
    {
        if(!is_c[i])
        {
            prime.push_back(i);
            for(int j = i * i; j < 4000; j += i)
                is_c[j] = true;
        }
    }

    int idx = 0;
    while(n > 1)
    {
        if(n % prime[idx] == 0)
        {
            n /= prime[idx];
            cout << prime[idx] << "\n";
        }
        else
        {
            idx++;
            if(idx >= prime.size())
            {
                cout << n << "\n";
                break;
            }
        }
    }
}