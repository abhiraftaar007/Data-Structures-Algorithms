#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/bubble-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bubble-sort

class Solution
{
public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n)
    {
        // Your code here
        for (int i = n - 1; i > 0; i--)
        {
            bool didSwap = false;
            for (int j = 0; j < i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;

                    didSwap = true;
                }
            }

            if (didSwap == false)
            {
                return;
            }
        }
    }

    // Recursive Bubble Sort
    void bubble_sort(int arr[], int n)
    {
        // Base Case: range == 1.
        if (n == 1)
            return;

        for (int j = 0; j <= n - 2; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }

        // Range reduced after recursion:
        bubble_sort(arr, n - 1);
    }
};

int main()
{
    int arr[5] = {4, 1, 3, 9, 7};

    Solution obj;

    // obj.bubbleSort(arr,5);

    obj.bubble_sort(arr, 5);

    for (auto &i : arr)
    {
        cout << i << " ";
    }

    return 0;
}