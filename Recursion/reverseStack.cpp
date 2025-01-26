#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &st, int ele)
{
    if (st.size() == 0)
    {
        st.push(ele);
        return;
    }

    int temp = st.top();
    st.pop();

    insert(st, ele);

    st.push(temp);
}

void reverseStack(stack<int> &st)
{
    if (st.size() == 1)
        return;

    int temp = st.top();
    st.pop();
    reverseStack(st);

    insert(st, temp);
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    stack<int> copy = st;

    while (!copy.empty())
    {
        cout << copy.top() << " ";
        copy.pop();
    }

    cout << endl;

    reverseStack(st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}