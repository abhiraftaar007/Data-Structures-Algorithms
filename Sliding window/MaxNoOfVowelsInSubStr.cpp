#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/?envType=study-plan-v2&envId=leetcode-75

// Solution 1 - self solution
bool isVowel(char c)
{
    if (c == 'a')
        return true;
    if (c == 'e')
        return true;
    if (c == 'i')
        return true;
    if (c == 'o')
        return true;
    if (c == 'u')
        return true;

    return false;
}

int maxVowels(string s, int k)
{
    int n = s.length();
    int i = 0, j = 0, cnt = 0, ans = 0;
    while (j < k)
    {
        if (isVowel(s[j]))
        {
            cnt++;
        }
        j++;
    }

    j--;

    while (j < n)
    {
        ans = max(ans, cnt);
        if (isVowel(s[i]))
            cnt--;
        i++;
        j++;
        if (isVowel(s[j]))
            cnt++;
    }

    return ans;
}

// ChatGPT Solution - Improved Code Quality
bool isVowel2(char c)
{
    // Define vowels in a set for quick lookup
    static const unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    return vowels.count(c) > 0;
}

int maxVowels2(const string &s, int k)
{
    int n = s.length();
    if (n < k)
        return 0; // If string length is less than k, return 0 since no window can be formed.

    // Sliding window initialization
    int i = 0, cnt = 0, maxVowelsCount = 0;

    // Count vowels in the first window of size 'k'
    for (int j = 0; j < k; ++j)
    {
        if (isVowel2(s[j]))
        {
            cnt++;
        }
    }

    maxVowelsCount = cnt; // Store the initial count of vowels

    // Slide the window through the string
    for (int j = k; j < n; ++j)
    {
        // If the character leaving the window is a vowel, decrease the count
        if (isVowel2(s[i]))
        {
            cnt--;
        }

        // If the character entering the window is a vowel, increase the count
        if (isVowel2(s[j]))
        {
            cnt++;
        }

        // Update the maximum vowels count
        maxVowelsCount = max(maxVowelsCount, cnt);

        // Move the left pointer of the window
        i++;
    }

    return maxVowelsCount;
}

int main()
{
    string s = "abciiidef";
    int k = 3;

    cout << maxVowels2(s, k);

    return 0;
}