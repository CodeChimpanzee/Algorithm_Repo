#include<iostream>
#include<cmath>

using namespace std;

int t, x, y;

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> x >> y;
        int diff = (y - x);
        double diff_root = sqrt((double)diff);
        int dri = (int)(diff_root);

        if(dri * dri == diff)
            cout << (dri + dri - 1) << "\n";
        else if(dri * dri + dri >= diff)
            cout << (dri + dri) << "\n";
        else
            cout << (dri + dri + 1) << "\n";
    }
}