#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<char> alpha;
int l, c;

bool is_vowel(char a)
{
    return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> l >> c;
    for(int i = 0; i < c; i++)
    {
        char t; cin >> t;
        alpha.push_back(t);
    }

    sort(alpha.begin(), alpha.end());
    
    int choose[16];
    fill(choose, choose + l, 1);
    fill(choose + l, choose + c, 0);

    do
    {
        int vcount = 0, ccount = 0;
        for(int i = 0; i < c; i++)
        {
            if(choose[i] == 1)
            {
                if(is_vowel(alpha[i]))
                    vcount++;
                else
                    ccount++;
            }
        }

        if(vcount < 1 || ccount < 2) continue;
        for(int i = 0; i < c; i++)
            if(choose[i] == 1)
                cout << alpha[i];
        cout << "\n";
    } while (prev_permutation(choose, choose + c));
}