#include<iostream>
#include<cmath>

using namespace std;

int grid[101][101];
pair<int, int> curve[2000];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int n;
int x, y, d, g; 

void dragon_curve(int depth)
{
    if(depth > g)
    {
        int pre_cnt = pow(2, depth - 1) + 1;
        for(int i = 0; i < pre_cnt; i++)
        {
            auto cur = curve[i];
            grid[x + cur.first][y + cur.second]++;
        }
        return;
    }
    if(depth == 0)
    {
        curve[0] = {0, 0};
        curve[1] = {dx[d], dy[d]};
        dragon_curve(depth + 1);
    }
    else
    {
        int pre_cnt = pow(2, depth - 1) + 1;
        int cur_idx = pre_cnt;
        auto cur_point = curve[pre_cnt - 1];
        for(int i = pre_cnt - 1; i > 0; i--)
        {
            int cx = curve[i - 1].first - curve[i].first;
            int cy = curve[i - 1].second - curve[i].second;

            swap(cx, cy);
            cx = -cx;
            cur_point.first += cx; cur_point.second += cy;
            curve[cur_idx++] = cur_point;
        }
        dragon_curve(depth + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    while(n--)
    {
        cin >> x >> y >> d >> g;
        dragon_curve(0);
    }

    int ans = 0;
    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 100; j++)
            if(grid[i][j] > 0 && grid[i + 1][j] > 0 && grid[i][j + 1] > 0 && grid[i + 1][j + 1] > 0)
                ans++;

    cout << ans << "\n";
}