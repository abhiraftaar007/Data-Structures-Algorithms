#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &s, int temp)
{
    if (s.size() == 0 || s.top() <= temp)
    {
        s.push(temp);
        return;
    }

    int val = s.top();
    s.pop();
    insert(s, temp);
    s.push(val);
    // return;
}

void sortStack(stack<int> &s)
{
    if (s.size() == 1)
        return;
    int temp = s.top();
    s.pop();
    sortStack(s);

    insert(s, temp);
}

int main()
{
    stack<int> s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    sortStack(s);

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}