#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/group-anagrams/description/

// Solution 1
vector<vector<string>> groupAnagrams1(vector<string> &strs)
{
    int n = strs.size();

    vector<vector<string>> result;

    unordered_map<string, vector<string>> mp;
    // n
    for (int i = 0; i < n; i++)
    {
        string temp = strs[i];

        sort(begin(temp), end(temp)); // maximum size of string size k -> O(klogk)

        mp[temp].push_back(strs[i]);
    }

    // T.C = O(n*(klogk))

    for (auto it : mp)
    {
        result.push_back(it.second);
    }

    return result;
}

string generate(string &word)
{
    int arr[26] = {0};

    for (char &ch : word)
    {
        arr[ch - 'a']++;
    }

    string new_word = "";

    for (int i = 0; i < 26; i++)
    {
        int freq = arr[i];

        if (freq > 0)
        {
            new_word += string(freq, i + 'a');
        }
    }

    return new_word;
}

// Solution 2 - more optimal - T.C - N*(K+26) - NK , where k is biggest string size
vector<vector<string>> groupAnagrams2(vector<string> &strs)
{
    // Taking advantage of all lowerCase characters
    int n = strs.size();

    unordered_map<string, vector<string>> mp;

    vector<vector<string>> result;

    for (int i = 0; i < n; i++)
    {
        string word = strs[i];

        string new_word = generate(word);

        mp[new_word].push_back(word);
    }

    for (auto &it : mp)
    {
        result.push_back(it.second);
    }

    return result;
}

int main()
{
    vector<string> s = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> result = groupAnagrams2(s);

    for (int i = 0; i < result.size(); i++)
    {
       for (int j = 0; j < result[i].size(); j++)
       {
            cout << result[i][j] << " ";
       }
       
       cout << endl;
       
    }
    
    return 0;
}