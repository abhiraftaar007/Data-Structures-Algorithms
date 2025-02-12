#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/selection-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=selection-sort

class Solution
{
public:
    int select(int arr[], int i, int n)
    {
        // code here such that selectionSort() sorts arr[]
        int mini = i;
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[mini])
            {
                mini = j;
            }
        }

        return mini;
    }

    void selectionSort(int arr[], int n)
    {
        // code here
        for (int i = 0; i <= n - 2; i++)
        {
            int smallest = select(arr, i, n);

            int temp = arr[smallest];
            arr[smallest] = arr[i];
            arr[i] = temp;
        }
    }
};

int main()
{
    int arr[5] = {4,1,3,9,7};
    
    Solution obj;
    obj.selectionSort(arr,5);

    for(auto& i:arr){
        cout << i << " ";
    }

    return 0;
}