#include<iostream>
#include<set>

using namespace std;

int t, k, n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while(t--)
    {
        multiset<int> dpq;
        cin >> k;
        while(k--)
        {
            char op; cin >> op;
            cin >> n;
            if(op == 'I')
                dpq.insert(n);
            if(op == 'D' && !dpq.empty())
                dpq.erase((n == 1) ? prev(dpq.end()) : dpq.begin());
        }
        
        if(dpq.empty())
            cout << "EMPTY\n";
        else
            cout << *prev(dpq.end()) << " " << *dpq.begin() << "\n";
    }
}