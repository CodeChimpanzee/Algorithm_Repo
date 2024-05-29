#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> dat(n);
    vector<int> track(n);
    for(int i = 0; i < n; i++)
        cin >> dat[i];

    sort(dat.begin(), dat.end());

    int ans = 0;
    do
    {
        int tsum = 0;
        for(int i = 0; i < n - 1; i++)
            tsum += abs(dat[i] - dat[i + 1]);
        ans = max(ans, tsum);
    } while (next_permutation(dat.begin(), dat.end()));
    cout << ans << "\n";
}