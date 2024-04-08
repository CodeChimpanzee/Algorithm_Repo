#include<iostream>
#include<stack>

#define HMAX 1000000001

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<int> building;
    stack<pair<int, int>> checker;
    int n;
    long long cnt, sum = 0;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int temp; cin >> temp;
        building.push(temp);
    }

    checker.push({0, HMAX});
    for(int i = 0; i < n; i++)
    {
        int h = building.top(); building.pop();
        cnt = 0;
        while(checker.top().second < h)
        {
            cnt += (checker.top().first + 1);
            checker.pop();
        }

        checker.push({cnt, h});
        sum += cnt;
    }

    cout << sum;
}
