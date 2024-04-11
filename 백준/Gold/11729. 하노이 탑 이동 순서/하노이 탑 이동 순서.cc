#include<iostream>

using namespace std;

//int hanoi_count(int k);
void hanoi(int a, int b, int k);

int main()
{
    int k; cin >> k;
    cout << ((1 << k) - 1) << "\n";
    hanoi(1, 3, k);
}

void hanoi(int a, int b, int k)
{
    if(k == 1)
    {
        cout << a << " " << b << "\n";
        return;
    }

    hanoi(a, 6-a-b, k-1);
    hanoi(a, b, 1);
    hanoi(6-a-b, b, k-1);
    return;
}

/*
int hanoi_count(int k) // Equivalent to 2^k - 1
{
    if(k == 1) return 1;
    int t = hanoi_count(k-1);
    return 2 * t + 1;
}
*/