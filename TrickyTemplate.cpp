// Tricky template in O(n) time complexity
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
 
void solve(){
    int n;  cin >> n;
    string s1,s2,s3;
    cin >> s1 >>s2 >> s3;
    bool flag = false;
    rep(i,0,n){
        if(s3[i]!=s1[i] && s3[i]!=s2[i]){               // then this is the case of existence of the template string
            flag = true;
            break;
        }   
        /*
            There is condition if(s3[i] == s2[i] || s3[i] == s1[i]) -> for every i 
            then template string willn't exist since for every i it will go or satisy properties with one
            of the strings s1 or s2
        */
    }
    if(flag == true)
    {
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
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