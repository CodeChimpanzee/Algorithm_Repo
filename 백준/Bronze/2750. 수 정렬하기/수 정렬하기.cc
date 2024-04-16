#include<iostream>

using namespace std;

int a[1001], merge_space[1001];
int n;

void merge(int start, int end)
{
    int mid = (start + end) / 2;
    // Array 1 = start ~ mid - 1, Array 2 = mid ~ end - 1
    int left_idx = start;
    int right_idx = mid;
    for(int i = start; i < end; i++)
    {
        if(left_idx == mid) merge_space[i] = a[right_idx++]; 
        else if(right_idx == end) merge_space[i] = a[left_idx++];
        else if(a[left_idx] <= a[right_idx]) merge_space[i] = a[left_idx++];
        else merge_space[i] = a[right_idx++];
    }
    for(int i = start; i < end; i++)
        a[i] = merge_space[i];
    return;
}

void merge_sort(int start, int end)
{
    if(end - start == 1) return;
    int mid = (start + end) / 2;

    merge_sort(start, mid);
    merge_sort(mid, end);
    merge(start, end);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    merge_sort(0, n);
    for(int i = 0; i < n; i++)
        cout << a[i] << "\n";
}