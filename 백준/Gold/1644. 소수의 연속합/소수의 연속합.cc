#include<iostream>
#include<vector>

using namespace std;

vector<int> prime;
bool is_com[4000001];
int n;

void sieve(int num)
{
    for(int i = 2; i * i <= num; i++)
        if(!is_com[i])
            for(int j = i + i; j <= num; j += i)
                is_com[j] = true;

    for(int i = 2; i <= num; i++)
        if(!is_com[i])
            prime.push_back(i);
}

int main()
{
    cin >> n;
    if(n == 1) {cout << 0 << "\n"; exit(0);}
    sieve(n);

    int st = 0, ed = 0;
    int lim = (int)prime.size();
    int psum = prime[0], ans = 0;
    while(st <= ed && ed < lim)
    {
        if(psum > n)
        {
            psum -= prime[st];
            st++;
        }
        else
        {
            if(psum == n) ans++;
            ed++;
            psum += prime[ed];
        }
    }
    cout << ans << "\n";
}