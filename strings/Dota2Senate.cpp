#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/dota2-senate/description/?envType=study-plan-v2&envId=leetcode-75

bool removeSenator(string &senate, char ch, int idx)
{
    bool checkRemovalLeftSide = false;

    while (true)
    {
        if (idx == 0)
        {
            checkRemovalLeftSide = true;
        }
        if (senate[idx] == ch)
        {
            senate.erase(begin(senate) + idx); // shift
            break;
        }

        idx = (idx + 1) % (senate.length());
    }

    return checkRemovalLeftSide;
}

// Solution 1 - 
string predictPartyVictory(string senate)
{
    // Brute Force
    int R_count = count(begin(senate), end(senate), 'R');
    int D_count = senate.length() - R_count;

    int idx = 0;

    while (R_count > 0 && D_count > 0)
    {
        if (senate[idx] == 'R')
        {
            bool checkRemovalLeftSide = removeSenator(senate, 'D', (idx + 1) % (senate.length()));
            D_count--;
            if (checkRemovalLeftSide)
            {
                idx--;
            }
        }
        else
        {
            bool checkRemovalLeftSide = removeSenator(senate, 'R', (idx + 1) % (senate.length()));
            R_count--;
            if (checkRemovalLeftSide)
            {
                idx--;
            }
        }

        idx = (idx + 1) % (senate.length()); // round ghumne k liye
    }

    return R_count == 0 ? "Dire" : "Radiant";
}

int n;
void removeSenator2(string &senate, vector<bool> &removed, char ch, int idx)
{

    while (true)
    {
        if (senate[idx] == ch && removed[idx] == false)
        {
            removed[idx] = true;
            break;
        }

        idx = (idx + 1) % (n);
    }
}

// Solution 2 - 
string predictPartyVictory2(string senate)
{
    // Optimal
    n = senate.length();
    int R_count = count(begin(senate), end(senate), 'R');
    int D_count = senate.length() - R_count;

    int idx = 0;
    vector<bool> removed(n, false); // no one is removed yet

    while (R_count > 0 && D_count > 0)
    {

        if (removed[idx] == false)
        {
            if (senate[idx] == 'R')
            {
                removeSenator2(senate, removed, 'D', (idx + 1) % (n));
                D_count--;
            }
            else
            {
                removeSenator2(senate, removed, 'R', (idx + 1) % (n));
                R_count--;
            }
        }
        idx = (idx + 1) % (n); // round ghumne k liye
    }

    return R_count == 0 ? "Dire" : "Radiant";
}

int main()
{
    string senate = "RD";
    cout << predictPartyVictory2(senate);
    
    return 0;
}