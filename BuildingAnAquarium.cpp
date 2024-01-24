#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int t;  cin>>t;
    while(t--){
        int n;  cin>>n;
        int x;  cin>>x;
        vector<ll> v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }    
        ll low = 0;
        ll high=1e10;
        while(low < high){
            ll mid = (low + high + 1)/2;
            ll ans = 0;
            for(int i=0; i<n; i++){
                ans += max(mid - v[i], 0LL);    // here ans is my total weight of water which is empty space
            }
            if(ans - x <= 0){
                low = mid;
            }else{
                high= mid - 1;
            }
        }
        cout << low << "\n";
    }
    return 0;
}