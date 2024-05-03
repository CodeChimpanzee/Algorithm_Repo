#include<iostream>
#include<algorithm>

using namespace std;

int a[100001];
int n, m;

int arr_find(int from, int to, int num)
{
    if(from + 1 == to)
    {
        if(a[from] == num)
            return from;
        else
            return -1;
    }

    int mid = (from + to) / 2;
    if(a[mid] > num)
        return arr_find(from, mid, num);
    else
        return arr_find(mid, to, num);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int t; cin >> t;
        cout << (arr_find(0, n, t) == -1 ? 0 : 1) << "\n";    
    }
}