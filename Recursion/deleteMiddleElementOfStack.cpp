#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &st, int k)
{
    if (k == 1)
    {
        st.pop();
        return;
    }
    int temp = st.top();
    st.pop();

    solve(st, k - 1);

    st.push(temp);
}

stack<int> midDel(stack<int> st, int size)
{
    if (size == 0)
        return st;
    int k = size / 2 + 1;

    solve(st, k);
    return st;
}

int main()
{
    stack<int> st;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);

    stack<int> ans = midDel(st, st.size());

    while(!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }

    return 0;
}