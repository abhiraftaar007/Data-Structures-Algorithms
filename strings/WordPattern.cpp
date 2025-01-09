#include <bits/stdc++.h>
using namespace std;

// problem link - https://leetcode.com/problems/word-pattern/description/

bool wordPattern(string pattern, string s)
{
    unordered_map<char, string> mp;
    unordered_map<string, bool> visited;
    vector<string> wordList;

    // string stream
    stringstream st(s);
    string word;
    int count = 0;

    while (st >> word)
    {
        count++;
        wordList.push_back(word);
    }

    if (pattern.size() != count)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < pattern.size(); i++)
        {
            char c = pattern[i];
            if (mp[c] == "" && visited[wordList[i]] == true)
            {
                return false;
            }
            else if (mp[c] == "")
            {
                mp[c] = wordList[i];
                visited[wordList[i]] = true;
            }
            else
            {
                if (mp[c] != wordList[i])
                    return false;
            }
        }
    }

    return true;
}

int main()
{
    string pattern = "abba";
    string s = "dog cat cat dog";
    cout << wordPattern(pattern, s);

    return 0;
}