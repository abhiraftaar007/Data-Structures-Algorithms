#include<bits/stdc++.h>
using namespace std;

// Brute force - Simply sort the array using sort function - T.C - O(nlogn), S.C - O(1)

// Better approach
void sortArray(vector<int> &arr, int n)
{
    // T.C - O(n)+O(n), S.C - O(1)
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            cnt0++;
        else if (arr[i] == 1)
            cnt1++;
        else
            cnt2++;
    }

    // Replace the places in the original array:
    for (int i = 0; i < cnt0; i++)
        arr[i] = 0; // replacing 0's

    for (int i = cnt0; i < cnt0 + cnt1; i++)
        arr[i] = 1; // replacing 1's

    for (int i = cnt0 + cnt1; i < n; i++)
        arr[i] = 2; // replacing 2's
}

// Optimal approach -
void sortArray2(vector<int> &arr, int n)
{
    // T.C - O(n), S.C - O(1)
    int low = 0, mid = 0, high = n - 1; // 3 pointers

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 6;
    vector<int> arr = {0, 2, 1, 2, 0, 1};

    // sortArray(arr, n);
    sortArray2(arr, n);

    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}