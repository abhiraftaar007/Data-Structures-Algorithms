#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/unique-email-addresses/description/

string modify(string s)
{
    string local = "";
    string domain = "";

    int i = 0;
    int j = s.length() - 1;

    while (s[j] != '@')
    {
        domain += s[j];
        j--;
    }

    domain += '@';
    reverse(domain.begin(), domain.end());

    while (s[i] != '+' && s[i] != '@')
    {
        if (s[i] == '.')
        {
            i++;
            continue;
        }
        local += s[i];
        i++;
    }

    string ans = local + domain;

    return ans;
}

// self - solution
int numUniqueEmails(vector<string> &emails)
{
    set<string> st;
    int n = emails.size();

    for (int i = 0; i < n; i++)
    {
        string index = emails[i];
        string modified = modify(index);
        st.insert(modified);
    }

    return st.size();
}

int main()
{
    vector<string> emails = {"test.email+alex@leetcode.com", 
    "test.e.mail+bob.cathy@leetcode.com", 
    "testemail+david@lee.tcode.com"
    };

    cout << numUniqueEmails(emails);

    return 0;
}