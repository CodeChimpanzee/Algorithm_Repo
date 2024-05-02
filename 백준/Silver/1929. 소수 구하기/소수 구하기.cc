#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

vector<int> sieve(int n)
{
    vector<int> prime;
    vector<bool> is_p (n + 1, true);
 
    for(int i = 2; i * i <= n; i++)
        if(is_p[i])
            for(int j = i * i; j <= n; j += i)
                is_p[j] = false;

    for(int i = 2; i <= n; i++)
        if(is_p[i])
            prime.push_back(i);

    return prime;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> prime = sieve(n);
    for(int p : prime)
        if(p >= m)
            cout << p << "\n";
}