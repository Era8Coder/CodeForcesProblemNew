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
 
int median(int a, int b, int c){
    vi v = {a,b,c};
    sort(v.begin(),v.end());
    return v[1];
}

void solve(){
    int n;  cin>>n;
    vi v(n);
    vi ans;
    rep(i,0,n){
        cin >> v[i];
    }
    if(n == 2){
        cout << *min_element(v.begin(),v.end()) << endl;
    }else if(n == 3){
        int val = median(v[0],v[1],v[2]);
        cout << val << endl;
    }else{
        int x;
        rep(i,0,n-2){
            x = median(v[i],v[i+1],v[i+2]);
            ans.push_back(x);
        }
        cout << *max_element(ans.begin(),ans.end()) << endl;
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