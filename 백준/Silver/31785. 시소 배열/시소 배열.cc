#include<iostream>
#include<deque>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    deque<int> fdq, bdq;
    int fsum = 0, bsum = 0;
    int q; cin >> q;
    while(q--)
    {
        int op; cin >> op;
        if(op == 1)
        {
            int num; cin >> num;
            if(bdq.size() > 0 && bdq.size() > fdq.size())
            {
                fdq.push_back(bdq.front());
                fsum += bdq.front();
                bsum -= bdq.front();
                bdq.pop_front();
            }
            bdq.push_back(num);
            bsum += num;
        }
        else
        {
            cout << (fsum <= bsum ? fsum : bsum) << "\n";
            if(fsum <= bsum)
            {
                fdq.clear(); fsum = 0;
                int lim = bdq.size() / 2;
                for(int i = 0; i < lim ; i++)
                {
                    fdq.push_back(bdq.front());
                    fsum += bdq.front();
                    bsum -= bdq.front();
                    bdq.pop_front();
                }
            }
            else
            {
                bdq.clear(); bsum = 0;
                int lim = fdq.size() / 2;
                if(fdq.size() & 1) lim++;
                for(int i = 0; i < lim ; i++)
                {
                    bdq.push_front(fdq.back());
                    fsum -= fdq.back();
                    bsum += fdq.back();
                    fdq.pop_back();
                }
            }
        }
    }

    for(int i = 0; i < fdq.size(); i++)
        cout << fdq[i] << " ";
    for(int i = 0; i < bdq.size(); i++)
        cout << bdq[i] << " ";
}