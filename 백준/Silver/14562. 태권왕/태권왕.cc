#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int c;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> c;
    while(c--)
    {
        int s, t; cin >> s >> t;
        int ans;

        queue<tuple<int, int, int>> bfs;

        bfs.push({s, t, 0});
        while(!bfs.empty())
        {
            auto cur = bfs.front(); bfs.pop();

            if(get<0>(cur) > get<1>(cur)) continue;
            if(get<0>(cur) == get<1>(cur))
            {
                ans = get<2>(cur);
                break;
            }

            bfs.push({get<0>(cur) * 2, get<1>(cur) + 3, get<2>(cur) + 1});
            bfs.push({get<0>(cur) + 1, get<1>(cur), get<2>(cur) + 1});
        }

        cout << ans << "\n";
    }
}