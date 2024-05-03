#include<iostream>

using namespace std;

int n, m, a;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> a;
    int k = m / 2 + 1;
    int pos = a;
    int cur; cin >> cur;
    while(cur != k)
    {
        pos = (pos - 1 + cur - k + n) % n + 1;
        cout << pos << "\n";
        cin >> cur;
    }
    cout << 0 << "\n";
}