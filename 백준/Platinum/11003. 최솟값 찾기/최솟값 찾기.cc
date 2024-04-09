#include<iostream>
#include<deque>

#define TMIN -1000000001

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n; // Sequence length
    int l; cin >> l;
    deque<pair<int, int>> dq;

    for(int i = 1; i <= n; i++)
    {
        int t; cin >> t;
        while(!dq.empty() && (dq.back().second > t))
            dq.pop_back();
        while(!dq.empty() && (dq.front().first < (i - l + 1)))
            dq.pop_front();

        dq.push_back({i, t});
        cout << dq.front().second << " ";
    }
}