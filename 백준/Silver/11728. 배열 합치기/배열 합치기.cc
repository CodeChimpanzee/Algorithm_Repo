#include<iostream>
#include<vector>

using namespace std;

vector<int> a, b, c;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int t; cin >> t;
        a.push_back(t);
    }  
    for(int i = 0; i < m; i++)
    {
        int t; cin >> t;
        b.push_back(t);
    }    

    vector<int>::iterator ap = a.begin();
    vector<int>::iterator bp = b.begin();
    for(int i = 0; i < n + m; i++)
    {
        if(ap == a.end()) {c.push_back(*(bp++));}
        else if(bp == b.end()) {c.push_back(*(ap++));}
        else if(*ap < *bp) {c.push_back(*(ap++));}
        else {c.push_back(*(bp++));}
    }
    for(int i = 0; i < n + m; i++)
        cout << c[i] << " ";
}