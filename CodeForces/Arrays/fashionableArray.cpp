#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// https://codeforces.com/contest/2110/problem/A

// Optimized & clean Code - 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while(tc--){
        ll n;
        cin >> n;

        vector<ll> a(n);
        for(auto &x:a) cin >> x;
        sort(a.begin(), a.end());

        ll firs_fl = -1, las_fl = -1;
        for (int i = 0; i < n; i++)
        {
            if(firs_fl == -1 && (a[i]%2)!= (a[0]%2)){
                firs_fl = i;
            }
            if((a[i]%2) != (a[n-1]%2)) las_fl = i;
        }
        
        if((a[0]+a[n-1])%2){
            cout << min(firs_fl, n-las_fl-1) << "\n";
        }
        else{
            cout << 0 << "\n";
        }
    }

    return 0;

}

// self-solution
/*
int fashionableArray(vector<int>& arr){
    int mini = arr[0];
    int n = arr.size();
    int maxi = arr[n-1];

    if((mini+maxi)%2==0) return 0;

    int rem_mini = 0;
    int rem_maxi = 0;

    if(mini%2==0){
        int j=n-1;
        while(j>0){
            if(arr[j]%2==0) break;
            rem_mini++;
            j--;
        }
    }
    if(mini%2!=0){
        int j=n-1;
        while(j>0){
            if(arr[j]%2!=0) break;
            rem_mini++;
            j--;
        }
    }
    if(maxi%2!=0){
        int j=0;
        while(j<n-1){
            if(arr[j]%2!=0) break;
            rem_maxi++;
            j++;
        }
    }
    if(maxi%2==0){
        int j=0;
        while(j<n-1){
            if(arr[j]%2==0) break;
            rem_maxi++;
            j++;
        }
    }

    return min(rem_maxi,rem_mini);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        cout << fashionableArray(a) << '\n';
    }
    return 0;
}
*/
