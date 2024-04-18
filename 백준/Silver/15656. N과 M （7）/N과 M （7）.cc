#include<iostream>
#include<algorithm>

using namespace std;

int numbers[8];
int choose[8];
int n, m;

void find_sequence(int depth)
{
    if(depth == m)
    {
        for(int i = 0; i < m; i++)
            cout << choose[i] << " ";
        cout << "\n";
        return;
    }

    for(int i = 0; i < n; i++)
    {
        choose[depth] = numbers[i];
        find_sequence(depth + 1);
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> numbers[i];
    sort(numbers, numbers + n);
    find_sequence(0);
}