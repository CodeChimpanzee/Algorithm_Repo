#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    
    vector<int> alpha(26);
    for(char c : a)
        alpha[c - 'a']++;
    for(char c : b)
        alpha[c - 'a']--;
    
    int sum = 0;
    for(int n : alpha)
        sum += abs(n);

    cout << sum;
}