#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int n;
vector<string> sereal_no;

bool cmp(string &a, string &b)
{
    if(a.size() != b.size()) return a.size() < b.size();
    
    int asum = 0, bsum = 0;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] >= '0' && a[i] <= '9') asum += (a[i] - '0');
        if(b[i] >= '0' && b[i] <= '9') bsum += (b[i] - '0');
    }
    if(asum != bsum) return asum < bsum;

    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] != b[i]) return a[i] < b[i];
    }
    return false; // 완벽히 같은 경우
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string t; cin >> t;
        sereal_no.push_back(t);
    }

    sort(sereal_no.begin(), sereal_no.end(), cmp);
    for(int i = 0; i < n; i++)
        cout << sereal_no[i] << "\n";
}