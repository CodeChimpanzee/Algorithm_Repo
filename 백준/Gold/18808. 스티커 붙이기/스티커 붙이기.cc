#include<iostream>
#include<algorithm>

using namespace std;

int n, m, k;
int r[100], c[100];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int board[40][40];
int sticker[100][10][10];

int ocpd_cnt = 0;

void rot90(int stick_no)
{
    int temp[10][10];
    for(int i = 0; i < r[stick_no]; i++)
        for(int j = 0; j < c[stick_no]; j++)
            temp[j][r[stick_no] - i - 1] = sticker[stick_no][i][j];

    swap(r[stick_no], c[stick_no]);

    for(int i = 0; i < r[stick_no]; i++)
        for(int j = 0; j < c[stick_no]; j++)
            sticker[stick_no][i][j] = temp[i][j];
}

bool stick_checker(int stick_no, int x, int y)
{
    for(int i = x; i < x + r[stick_no]; i++)
        for(int j = y; j < y + c[stick_no]; j++)
            if(sticker[stick_no][i - x][j - y] == 1 && board[i][j] == 1)
                return false;
    return true;
}

void stick_paster(int stick_no, int x, int y)
{
    for(int i = x; i < x + r[stick_no]; i++)
        for(int j = y; j < y + c[stick_no]; j++)
            if(sticker[stick_no][i - x][j - y] == 1 && board[i][j] == 0)
                board[i][j] = 1;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            board[i][j] = 0;

    for(int i = 0; i < k; i++)
    {
        cin >> r[i] >> c[i];
        for(int ii = 0; ii < r[i]; ii++)
            for(int jj = 0; jj < c[i]; jj++)
                cin >> sticker[i][ii][jj];
    }

    for(int i = 0; i < k; i++)
    {   // i번째 스티커
        bool is_pasted = false;
        for(int rot = 0; rot < 4; rot++)
        {  
            for(int ii = 0; ii <= n - r[i]; ii++)
            {
                for(int jj = 0; jj <= m - c[i]; jj++)
                    if(stick_checker(i, ii, jj))
                    {
                        stick_paster(i, ii, jj);
                        is_pasted = true;
                        break;
                    }    
                if(is_pasted) break;
            }
            if(is_pasted) break;
            rot90(i);
        }
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(board[i][j] == 1)
                ocpd_cnt++;

    cout << ocpd_cnt;
}