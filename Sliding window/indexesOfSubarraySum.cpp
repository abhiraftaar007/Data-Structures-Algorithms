#include<bits/stdc++.h>
using namespace std;

vector<int> subarraySum(vector<int> &arr, int target)
{
    // code here
    // self-solution
    int i = 0, j = 0, sum = 0;
    int n = arr.size();
    vector<int> ans;

    while (j < n)
    {
        sum += arr[j];
        while (sum > target && i <= j)
        {
            sum -= arr[i];
            i++;
        }

        if (sum == target)
        {
            ans.push_back(i + 1);
            ans.push_back(j + 1);
            return ans;
        }
        j++;
    }

    ans.push_back(-1);
    return ans;
}

// Another way to write sliding window for this ques
// vector<int> subarraySum(vector<int> &arr, int target)
// {
//     // code here
//     int sum = 0;
//     int j = 0;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         sum += arr[i];
//         if (sum > target)
//             while (sum > target && sum > 0)
//             {
//                 sum -= arr[j];
//                 j++;
//             }
//         if (sum == target)
//         {
//             vector<int> ans = {j + 1, i + 1};
//             return ans;
//         }
//     }
//     return {-1};
// }

int main()
{
    vector<int> arr = {1,2,3,7,5};
    int target = 12;
    vector<int> ans = subarraySum(arr,target);
    for(auto &i:ans){
        cout << i << " ";
    }
    return 0;
}