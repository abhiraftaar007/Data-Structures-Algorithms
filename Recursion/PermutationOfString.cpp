#include<bits/stdc++.h>
using namespace std;

// Recursive function to generate
// all permutations of string s
void recurPermute(int index, string &s,
                  vector<string> &ans)
{

    // Base Case
    if (index == s.size())
    {
        ans.push_back(s);
        return;
    }

    // Swap the current index with all
    // possible indices and recur
    for (int i = index; i < s.size(); i++)
    {
        swap(s[index], s[i]);
        recurPermute(index + 1, s, ans);
        swap(s[index], s[i]);
    }
}

// Function to find all unique permutations
vector<string> findPermutation(string &s)
{

    // Stores the final answer
    vector<string> ans;

    recurPermute(0, s, ans);

    // sort the resultant vector
    sort(ans.begin(), ans.end());

    return ans;
}

int main()
{
    string s = "ABC";
    vector<string> res = findPermutation(s);
    set<string> result;

    cout << "All permutations of a string: ";
    for(auto& x:res){
        cout << x << " ";
    }

    cout << endl;

    cout << "All unique permutations of a string: ";
    for (auto x : res)
    {
        // cout << x << " ";
        result.insert(x);
    }

    for (auto &str : result)
    {
        cout << str << ' ';
    }
    return 0;
}