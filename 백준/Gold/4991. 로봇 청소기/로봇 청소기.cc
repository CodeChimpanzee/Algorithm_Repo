#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>

#define CLEAN '.'
#define DIRTY '*'
#define WALL 'x'
#define START 'o'

using namespace std;

char map_state[21][21];
int odist[11];
int dist[11][11];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int w, h;
pair<int, int> origin;

int bfs_distance(pair<int, int> &st, pair<int, int> &dst)
{
    int map_depth[21][21];
    bool map_visit[21][21];

    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
        {
            map_depth[i][j] = 0;
            map_visit[i][j] = false;
        }

    queue<pair<int, int>> bfs;
    bfs.push(st);
    
    while(!bfs.empty())
    {
        auto cur = bfs.front(); bfs.pop();
        int cur_depth = map_depth[cur.first][cur.second];

        if(dst.first == cur.first && dst.second == cur.second)
            return cur_depth;

        for(int i = 0; i < 4; i++)
        {
            int cx = cur.first + dx[i], cy = cur.second + dy[i];
            if(cx < 0 || cx >= h || cy < 0 || cy >= w) continue; // OOB
            if(map_state[cx][cy] == WALL) continue; // Furniture
            if(map_visit[cx][cy]) continue; // Visited

            map_depth[cx][cy] = cur_depth + 1;
            map_visit[cx][cy] = true;
            bfs.push({cx, cy});
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> w >> h;
    while(w != 0 && h != 0)
    {
        vector<pair<int, int>> pts;
        for(int i = 0; i < h; i++)
        {
            string s; cin >> s;
            for(int j = 0; j < w; j++)
            {
                if(s[j] == START)
                {
                    origin = {i, j};
                    map_state[i][j] = CLEAN;
                }
                else if(s[j] == DIRTY)
                {
                    pts.push_back({i, j});
                    map_state[i][j] = s[j];
                }
                else
                    map_state[i][j] = s[j];
            }
        }

        sort(pts.begin(), pts.end());
        int choose[11];
        bool flag_avail = true;

        for(int i = 0; i < pts.size(); i++)
        {
            choose[i] = i;
            odist[i] = bfs_distance(origin, pts[i]);
        }

        for(int i = 0; i < pts.size(); i++)
        {
            for(int j = 0; j < pts.size(); j++)
            {
                dist[i][j] = bfs_distance(pts[i], pts[j]);
                if(dist[i][j] == -1) flag_avail = false;
            }
        }

        int ans = 1e8;
        if(flag_avail)
        {
            do
            {
                int tsum = odist[choose[0]];
                for(int i = 1; i < pts.size(); i++)
                    tsum += dist[choose[i - 1]][choose[i]];

                ans = min(ans, tsum);
            } while (next_permutation(choose, choose + pts.size()));
        }
        else
            ans = -1;

        cout << ans << "\n";
        cin >> w >> h;
    }
}