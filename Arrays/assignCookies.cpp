#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/assign-cookies/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //self-solution
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int cnt = 0, j = 0;

        int gn = g.size();
        int sn = s.size();

        for(int i=0;i<gn;i++){
            while(j<sn && s[j]<g[i]){
                j++;
            }
            if(j==sn) break;
            if(s[j]>=s[i]){
                cnt++;
                j++;
            }
        }

        return cnt;
    }
};

int main()
{
    vector<int> g = {1,2,3};
    vector<int> s = {1,1};

    Solution obj;
    cout << obj.findContentChildren(g,s);
    
    return 0;
}