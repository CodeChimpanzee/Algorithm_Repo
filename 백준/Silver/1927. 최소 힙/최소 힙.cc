#include<iostream>
#include<set>

using namespace std;

multiset<int> ms;
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    while(n--)
    {
        int op; cin >> op;
        if(op == 0)
        {
            if(ms.empty())
                cout << 0 << "\n";
            else
            {
                cout << *ms.begin() << "\n";
                ms.erase(ms.begin());
            }
        }
        else
            ms.insert(op);
    }
}