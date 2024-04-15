#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

int board[21][21];
int t_board[21][21];
bool mergable[21][21];
int n;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

bool OOB(int x, int y)
{
    return (x < 0 || x >= n || y < 0 || y >= n);
}

void move_block(int x, int y, int dir)
{
    bool mb = mergable[x][y];
    int cx = x, cy = y;
    while(true)
    {
        int nx = cx + dx[dir], ny = cy + dy[dir];
        if(OOB(nx, ny)) break;
        if(t_board[nx][ny] == 0)
            swap(t_board[nx][ny], t_board[cx][cy]);
        else if(t_board[nx][ny] == t_board[cx][cy] && mergable[nx][ny] && mb)
        {
            t_board[nx][ny] += t_board[cx][cy];
            t_board[cx][cy] = 0;
            mergable[nx][ny] = false;
            break;
        }
        else
            break;

        cx = nx; cy = ny;
    }
}

void move_board(int dir)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            mergable[i][j] = true;

    switch(dir)
    {
        case 0 : // 오른쪽
        for(int i = 0; i < n; i++)
            for(int j = n - 1; j >= 0; j--)
                if(t_board[i][j] != 0)
                    move_block(i, j, dir);
        break;
        case 1 : // 위쪽
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(t_board[i][j] != 0)
                    move_block(i, j, dir);
        break;
        case 2 : // 왼쪽
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(t_board[i][j] != 0)
                    move_block(i, j, dir);
        break;
        case 3 : // 아래쪽
        for(int i = n - 1; i >= 0; i--)
            for(int j = 0; j < n; j++)
                if(t_board[i][j] != 0)
                    move_block(i, j, dir);
        break;
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];

    int ans = 0;
    int cmax = pow(4, 5); // 4진수 5자리
    for(int c = 0; c < cmax; c++)
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                t_board[i][j] = board[i][j];

        int cnow = c;
        for(int r = 0; r < 5; r++)
        {
            int cur = cnow % 4;
            move_board(cur);
            cnow /= 4;
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                ans = max(t_board[i][j], ans);
    }

    cout << ans;
}