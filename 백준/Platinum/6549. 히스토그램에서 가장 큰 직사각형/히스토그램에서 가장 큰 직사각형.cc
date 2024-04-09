#include<iostream>
#include<stack>
#include<vector>

#define HMIN -1
#define X first
#define Y second

using namespace std;

int main()
{
    stack<pair<int, int>> monoleft, monoright;
    vector<int> data, margin;
    int op;

    while(true)
    {
        cin >> op;
        if(!op) break;

        data = vector<int> (op);
        margin = vector<int> (op);
        for(int i = 0; i < op; i++)
            cin >> data[i];

        monoleft.push({-1, HMIN});
        for(int i = 0; i < op; i++)
        {
            while(monoleft.top().Y >= data[i])
                monoleft.pop();

            margin[i] = i - monoleft.top().X - 1;
            monoleft.push({i, data[i]});
        }

        monoright.push({op, HMIN});
        for(int i = op-1; i >= 0; i--)
        {
            while(monoright.top().Y >= data[i])
                monoright.pop();

            margin[i] += monoright.top().X - i;
            monoright.push({i, data[i]});
        }

        long long smax = -1;
        for(int i = 0; i < op; i++)
        {
            long long scur = (long long)margin[i] * (long long)data[i];
            if (smax < scur)
                smax = scur;           
        }

        cout << smax << "\n";
    }
}