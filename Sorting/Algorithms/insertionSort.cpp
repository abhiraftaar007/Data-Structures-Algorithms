#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/insertion-sort/0?category%5B%5D=Algorithms&page=1&query=category%5B%5DAlgorithmspage1&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=insertion-sort

class Solution
{
public:
    void insert(int arr[], int i)
    {
        // code here
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            /* code */
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;

            j--;
        }
    }

public:
    // Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        // code here
        for (int i = 0; i < n; i++)
        {
            insert(arr, i);
        }
    }
};

int main()
{
    int arr[5] = {4,1,3,9,7};
    Solution obj;

    obj.insertionSort(arr,5);

    for(auto&i:arr){
        cout << i << " ";
    }
    
    return 0;
}