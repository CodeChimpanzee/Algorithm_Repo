#include<iostream>
#include<set>

using namespace std;

multiset<int> lms, rms;
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    
    lms.insert(-10001);
    rms.insert(10001);

    for(int i = 1; i <= n; i++)
    {
        int t; cin >> t;
        if(i & 1)
        {
            if(t < *rms.begin())
            {
                lms.insert(t);
                cout << *prev(lms.end()) << "\n";
            }
            else
            {
                rms.insert(t);
                cout << *rms.begin() << "\n";
            }
        }
        else
        {
            if(lms.size() < rms.size())
            {
                rms.insert(t);
                lms.insert(*rms.begin());
                rms.erase(rms.begin());
            }
            else
            {
                lms.insert(t);
                rms.insert(*prev(lms.end()));
                lms.erase(prev(lms.end()));
            }

            cout << min(*prev(lms.end()), *rms.begin()) << "\n";
        }
    }
}