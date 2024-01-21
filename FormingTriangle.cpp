#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
/*
    In this problem we have to think upon the case;
    since Sides are 2^(ai) therefore there can't be case that one of the side is strictly greater than both of the sides;
    since in that case triangle will always be generate(Imaginary of Zero area -- >> From Heron's Formula)
    Therefore the two cases left 
    1) Equilateral Triangle
    2) Isoceles Triangle
*/
int main(){
    int t;  cin>>t;
    while(t--)
    {
        ll n;  cin>>n;
        vector<ll> v(n);
        vector<ll> cnt(n+1,0);           // one more than the size since; we have to count the frequency
        for(int i=0; i<n; i++)
        {
            cin >> v[i];                // if i'th element belongs from "0" to "n"; then try to use frequency array from the hint
            cnt[v[i]]++;
            // 0 <= v[i] <= n           // is input is like this think always of frequency array first
        }
        long long ans = 0;
        long long sum = 0;              // to keep track of previous possible values of sides
        if(n == 1 || n==2){
            cout << 0 << endl;
        }else{
            for(int i=0; i<n+1; i++)
            {
                if(cnt[i] >= 3){
                    ans += (cnt[i])*(cnt[i] - 1)*(cnt[i]-2)/6;              // basically nCr for equilateral traingle case
                }
                
                if(i>=1 && cnt[i] >= 2){
                    ans += ((cnt[i])*(cnt[i]-1)/2) * (sum);                   // basically for isoceles we have to consider this case
                    // we have to some up those which have side length less than it
                }
                sum += cnt[i];
            }
            cout << ans << endl;
        }
    }
    return 0;
}