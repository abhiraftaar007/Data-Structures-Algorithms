#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool prime(long long n)
    {
        if (n < 2)
            return false;
        if (n == 2)
            return true;
        if (n % 2 == 0)
            return false;
        for (long long i = 3; i * i <= n; i += 2)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    long long sumOfLargestPrimes(string s)
    {
        unordered_set<long long> primes;
        int n = s.size();

        // Generate all substrings
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                string sub = s.substr(i, j - i + 1);
                long long num = stoll(sub); // // Remove leading zeros automatically
                if (prime(num))
                {
                    primes.insert(num);
                }
            }
        }

        vector<long long> primesList(primes.begin(), primes.end());
        sort(primesList.rbegin(), primesList.rend()); // Sort in descending order

        long long sum = 0;
        for (int i = 0; i < min(3, (int)primesList.size()); i++)
        {
            sum += primesList[i];
        }

        return sum;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s = "12234";
    Solution obj;

    cout << obj.sumOfLargestPrimes(s);

    return 0;
}
