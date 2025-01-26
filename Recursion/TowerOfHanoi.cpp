#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1

void solve(int s, int d, int h, int n, int &count)
{
    count++;

    if (n == 1)
    {
        cout << "move disk " << n << " from rod " << s << " to " << "rod " << d << '\n';
        return;
    }

    solve(s, h, d, n - 1, count);

    cout << "move disk " << n << " from rod " << s << " to " << "rod " << d << '\n';
    
    solve(h, d, s, n - 1, count);

    return;
}

int towerOfHanoi(int n, int s, int d, int h)
{
    // Your code here
    int count = 0;

    if (n == 0)
        return count;

    solve(s, d, h, n, count);

    cout << "Total Steps : ";
    
    return count;
}

int main()
{
    int n = 3;
    int s = 1;
    int h = 2;
    int d = 3;
    
    cout << towerOfHanoi(n,s,d,h);

    return 0;
}