#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1

vector<int> countDistinct(vector<int> &arr, int k)
{
    // code here.
    // self-solution
    int n = arr.size();
    int j = 0, i = 0;

    vector<int> ar;
    map<int, int> mp;

    while (j < k)
    {
        mp[arr[j]]++;
        j++;
    }

    ar.push_back(mp.size());

    while (j < n)
    {
        mp[arr[i]]--;
        if (mp[arr[i]] == 0)
        {
            mp.erase(arr[i]);
        }
        mp[arr[j]]++;
        ar.push_back(mp.size());
        i++;
        j++;
    }

    return ar;
}

int main()
{
    vector<int> arr = {1,2,1,3,4,2,3};
    int k = 4;
    vector<int> ans = countDistinct(arr,k);
    for(auto &i:ans){
        cout << i << ' ';
    }
    return 0;
}