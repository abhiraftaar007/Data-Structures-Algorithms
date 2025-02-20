#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/rotate-array/description/

// Brute Force Approach -
void leftRotateByOne(vector<int>& arr, int n)
{
    // T.C - O(n), S.C - O(n)
    int temp[n]; // O(n)
    for (int i = 1; i < n; i++) //O(n)
    {
        temp[i - 1] = arr[i];
    }

    temp[n - 1] = arr[0];

    for (int i = 0; i < n; i++) // O(n)
    {
        cout << temp[i] << " ";
    }
    cout << endl;
}

// Optimal - without space
void leftRotateByOne2(vector<int>& arr, int n){
    // T.C - O(n), S.C - O(1)
    int temp = arr[0]; // storing the first element of array in a variable
    for (int i = 0; i < n - 1; i++) // O(n)
    {
        arr[i] = arr[i + 1];
    }

    arr[n - 1] = temp; // assigned the value of variable at the last index

    for (int i = 0; i < n; i++) // O(n)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> arr = {1,2,3,4,5};

    leftRotateByOne(arr, arr.size());

    cout << '\n';

    leftRotateByOne2(arr, arr.size());


    return 0;
}