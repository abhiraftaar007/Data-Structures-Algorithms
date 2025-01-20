#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/determine-if-two-strings-are-close/?envType=study-plan-v2&envId=leetcode-75

bool closeStrings(string word1, string word2)
{
    // If lengths are different, the words can't be close
    if (word1.length() != word2.length())
        return false;

    // Frequency maps for both strings
    map<char, int> mp1, mp2;

    // Count frequencies of characters in both words
    for (char c : word1)
    {
        mp1[c]++;
    }
    for (char c : word2)
    {
        mp2[c]++;
    }

    // Check if both maps have the same set of characters
    if (mp1.size() != mp2.size())
        return false;
    for (auto &entry : mp1)
    {
        if (mp2.find(entry.first) == mp2.end())
            return false;
    }

    // Compare the frequency distributions of characters
    vector<int> freqs1, freqs2;
    for (auto &entry : mp1)
    {
        freqs1.push_back(entry.second);
    }
    for (auto &entry : mp2)
    {
        freqs2.push_back(entry.second);
    }

    // Sort the frequency distributions
    sort(freqs1.begin(), freqs1.end());
    sort(freqs2.begin(), freqs2.end());

    // If the sorted frequency distributions are equal, the strings are close
    return freqs1 == freqs2;
}

int main()
{
    string word1 = "cabbba";
    string word2 = "abbccc";

    cout << closeStrings(word1,word2);
    
    return 0;
}