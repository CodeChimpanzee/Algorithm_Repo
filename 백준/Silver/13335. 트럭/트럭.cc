#include<iostream>
#include<queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<int> bridge, entry;
    int n, w, l; cin >> n >> w >> l;

    for(int i = 0; i < n; i++)
    {
        int t; cin >> t;
        entry.push(t);
    }

    for(int i = 0; i < w; i++)
        bridge.push(0);

    int lsum = 0, cnt = 0;
    while(true)
    {
        cnt++;
        lsum -= bridge.front();
        bridge.pop();
        if(!entry.empty() && lsum + entry.front() <= l)
        {
            lsum += entry.front();
            bridge.push(entry.front());
            entry.pop();
        }
        else
            bridge.push(0);

        if(lsum == 0 && entry.empty()) break;
    }
    cout << cnt;
}