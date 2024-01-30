#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;  cin>>t;
    while(t--){
        int n;   cin>>n;
        vector<pair<int,int>> ans(n);
        for(int i=0; i<n; i++){
            cin >> ans[i].first;
        }
        for(int i=0 ;i<n; i++){
            cin >> ans[i].second;
        }
        sort(ans.begin(),ans.end());
        for(int i=0; i<n; i++){
            cout << ans[i].first << " ";
        }
        cout << endl;
        for(int i=0 ;i<n ;i++){
            cout << ans[i].second << " ";
        }
        cout << endl;
    }
    return 0;
}