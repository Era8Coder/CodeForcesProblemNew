#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef priority_queue <int, vector<int>, greater<int>> minheap;
typedef priority_queue <int> maxheap;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define rep(i,a,b) for(int i=a; i<b; i++)
const int N=1e9+7;
const int M=1e8+7;
 
int gcd(int a, int b){
    if(a > b){
        swap(a,b);
    }
    int dividend = b;
    int divisor = a;
    int remainder = b%a;
    while(remainder != 0){
        dividend = divisor;
        divisor = remainder;
        remainder = dividend%divisor;
    }
    return divisor;
}
 
void solve(){
    int n;  cin>>n;
    vi v(n);
    rep(i,0,n){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    int ai = v[0];
    int aj = v[1];
    for(int i=1; i<n; i++){
        if(v[i]%ai != 0){
            aj = v[i];
            break;
        }
    }
    bool flag = false;
    for(int i=0; i<n; i++){
        if(v[i]%ai!=0 && v[i]%aj != 0){
        //    cout << "No" << endl; 
            flag = true;
        }
    }
    if(flag){
        cout << "No" << endl;
    }else{
        cout << "Yes"<< endl;
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int t;  cin>>t;
        while(t--){
        solve();
        }
    return 0;  
}