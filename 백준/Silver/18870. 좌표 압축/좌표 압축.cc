#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> dvec, uvec;
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int t; cin >> t;
        dvec.push_back(t);
    }

    uvec = vector<int> (dvec);
    sort(uvec.begin(), uvec.end());
    uvec.erase(unique(uvec.begin(), uvec.end()), uvec.end());

    for(int i = 0; i < n; i++)
        cout << lower_bound(uvec.begin(), uvec.end(), dvec[i]) - uvec.begin() << " ";
}