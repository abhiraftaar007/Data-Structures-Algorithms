#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/?envType=study-plan-v2&envId=leetcode-75

int minFlips(int a, int b, int c)
{
    // Solution 1
    int flips = 0;

    while (a != 0 || b != 0 || c != 0)
    {
        if ((c & 1) == 1)
        {
            if ((a & 1) == 0 && (b & 1) == 0)
            {
                flips++;
            }
        }
        else
        { // Right Most Bit (MSB) == 0
            if ((a & 1) == 1)
                flips++;
            if ((b & 1) == 1)
                flips++;

            // flips += (a&1) + (b&1);
        }

        // Right shift
        a >>= 1;
        b >>= 1;
        c >>= 1;
    }

    return flips;
}


int minFlips2(int a, int b, int c)
{
    // Solution 2 - Complex
    int result = ((a | b) ^ c); // flips

    // If both bits are 1 in a and b
    // a&b

    int result1 = (a & b);

    int result2 = (result1 & result);

    return __builtin_popcount(result) + __builtin_popcount(result2);
}

int main()
{
    int a = 2, b = 6, c = 5;

    cout << minFlips2(a,b,c);

    return 0;
}