#include<bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/2110/problem/B

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;

    while(tc--){
        string s;
        cin>>s;
        int n = s.size();
        int v = 0; // balance factor
        bool ans = false;
        for (int i = 0; i < n; i++)
        {
            if(s[i]=='(') v++;
            else v--;

            if(i < n-1 && v==0) ans = true;
        }

        if(ans) cout << "YES\n";
        else cout << "NO\n";
        
    }

    // T.C - O(N), S.C - O(1)

    return 0;
}