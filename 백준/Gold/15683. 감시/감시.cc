#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int n, m;
int dat[9][9];
int dat_c[9][9];
int emp_area = 0;
int temp_area;
vector<pair<int, int>> cc;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool OOB(int x, int y)
{
    return (x < 0 || x >= n || y < 0 || y >= m);
}

void traverse(int x, int y, int dir)
{
    while(true)
    {
        x += dx[dir]; y += dy[dir];
        if(OOB(x, y)) break;
        if(dat_c[x][y] == 0)
        {
            dat_c[x][y] = -1;
            temp_area--;
        }
        if(dat_c[x][y] == 6) break;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            cin >> dat[i][j];
            if(dat[i][j] >= 1 && dat[i][j] <= 5)
                cc.push_back({i, j});
            if(dat[i][j] == 0)
                emp_area++;
        }

    int imax = pow(4, cc.size());
    int ans = emp_area;
    for(int i = 0; i < imax; i++)
    {
        for(int ii = 0; ii < n; ii++)
            for(int jj = 0; jj < m; jj++)
                dat_c[ii][jj] = dat[ii][jj];

        int codes = i;
        temp_area = emp_area;

        for(int c = 0; c < cc.size(); c++)
        {
            int cx = cc[c].first, cy = cc[c].second;
            int cur_type = dat_c[cx][cy];
            int rot = codes % 4;

            switch(cur_type)
            {
                case 1 :
                traverse(cx, cy, rot);
                break;
                case 2 :
                traverse(cx, cy, rot);
                traverse(cx, cy, (rot + 2) % 4);
                break;
                case 3 :
                traverse(cx, cy, rot);
                traverse(cx, cy, (rot + 1) % 4);
                break;
                case 4 :
                traverse(cx, cy, rot);
                traverse(cx, cy, (rot + 1) % 4);
                traverse(cx, cy, (rot + 2) % 4);
                break;
                case 5 :
                traverse(cx, cy, 0);
                traverse(cx, cy, 1);
                traverse(cx, cy, 2);
                traverse(cx, cy, 3);
                break;
            }
            
            codes /= 4;
        }

        ans = min(ans, temp_area);
    }
    cout << ans;
}