#include<iostream>
#include<string>

using namespace std;

int n, m;
long long avail[11];
int max_cnt = 0, ans = 11;

void find_max(int depth, int choose, long long bits)
{

    int cnt = 0;
    long long tbits = bits;
    for(int i = 0; i < m; i++)
    {
        if(tbits % 2 == 1) cnt++;
        tbits >>= 1;
    }
    
    if(max_cnt < cnt)
    {
        max_cnt = cnt;
        ans = choose;
    }
    else if(max_cnt == cnt)
        ans = min(ans, choose);

    if(depth == n)
        return;
    
    find_max(depth + 1, choose + 1, bits | avail[depth]);
    find_max(depth + 1, choose, bits);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        string a, b; cin >> a >> b;
        long long bits = (b[0] == 'Y') ? 1 : 0;
        for(int j = 1; j < m; j++)
        {
            bits <<= 1;
            bits += (b[j] == 'Y') ? 1 : 0;
        }
        avail[i] = bits;
    }

    find_max(0, 0, 0);
    if(max_cnt == 0) ans = -1;
    cout << ans << "\n";
}
