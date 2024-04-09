#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

int main()
{
    deque<int> dq;
    int n, m, sum = 0;

    cin >> n;
    for(int i = 1; i <= n; i++)
        dq.push_back(i);
    
    cin >> m;
    while(m--)
    {
        int t; cin >> t;
        int idx = find(dq.begin(), dq.end(), t) - dq.begin();

        if(idx < dq.size() - idx)
            while(dq.front() != t)
            {
                dq.push_back(dq.front());
                dq.pop_front();
                sum++;
            }
        else
            while(dq.front() != t)
            {
                dq.push_front(dq.back());
                dq.pop_back();
                sum++;
            }
        dq.pop_front();
    }

    cout << sum;
}