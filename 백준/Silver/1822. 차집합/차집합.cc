#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int datA[500001], datB[500001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> datA[i];
    for(int i = 0; i < m; i++)
        cin >> datB[i];
    sort(datB, datB + m);

    vector<int> diff;
    for(int i = 0; i < n; i++)
        if(!binary_search(datB, datB + m, datA[i]))
            diff.push_back(datA[i]);
    sort(diff.begin(), diff.end());

    cout << diff.size() << "\n";
    for(int i = 0; i < diff.size(); i++)
        cout << diff[i] << " ";
}