#include <string>
#include <vector>

using namespace std;
using ll = long long;

int solution(vector<int> queue1, vector<int> queue2) {
    ll q1s = 0, q2s = 0;
    for(int q : queue1)
        q1s += q;
    for(int q : queue2)
        q2s += q;
    
    int q1i = 0, q2i = 0;
    int lim = ((int)queue1.size() + (int)queue2.size()) * 2;
    while(lim--)
    {
        if(q1s < q2s)
        {
            q1s += queue2[q2i];
            q2s -= queue2[q2i];
            queue1.push_back(queue2[q2i++]);
        }
        else if(q1s > q2s)
        {
            q2s += queue1[q1i];
            q1s -= queue1[q1i];
            queue2.push_back(queue1[q1i++]);
        }
        else
            return q1i + q2i;
    }
    
    return -1;
}