//  O(sqrt(n)) time complexity method for the prime factorization calculation
#include<bits/stdc++.h>
using namespace std;

long long Exponentiation(long long n, long long b, int MOD){      
    // Here we have to calculate the exponential answer with modulo respect to MOD :)
    // -->> (a^n)%MOD
    int ans = 1;
    while(b >= 1){  
        if(b%2 == 0){
            n = (n*n)%MOD;
            b/=2;
        }else{
            ans = (ans*n)%MOD;
            b--;
        }
    }
    return ans;
}

int main(){
    long long n;  cin >> n;
    long long b;  cin >> b;
    long long mod;    cin >> mod;
    cout << Exponentiation(n,b,mod) << endl;
    
    return 0;
}   