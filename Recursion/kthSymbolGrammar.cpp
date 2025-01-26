#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/k-th-symbol-in-grammar/description/

int kthGrammar(int n, int k)
{
    // Recursion
    // this is given in the question
    if (n == 1 && k == 1)
        return 0;

    // pow(2,n-1) gives the length and '/2' helps to find mid
    int mid = pow(2, n - 1) / 2;

    // answer as previous row
    if (k <= mid)
        return kthGrammar(n - 1, k);

    // answer obtain by mapping previous row and take complement of it
    else
        return !kthGrammar(n - 1, k - mid);
}

int main()
{
    int n = 4, k = 3;
    cout << kthGrammar(n,k);

    return 0;
}