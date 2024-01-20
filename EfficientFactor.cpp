//  O(sqrt(n)) time complexity method for the prime factorization calculation
#include<bits/stdc++.h>
using namespace std;

void primefactorization(int n){
    vector<int> prm;           // it will contain all the prime numbers
    vector<int> exp;           // it will contain all th exponents        
    int d = 2;
    while(n>1 && d*d <= n)
    {    
        int k = 0;
        while(n%d == 0){
            n /= d;
            k++;
        }
        if(k>0){
            prm.push_back(d);
            exp.push_back(k);
        }
        d++;
    }
    for(int i=0; i<prm.size(); i++){
        cout << exp[i] << " Times: " << prm[i] << endl;
    }
    if(n>1){    // tha is we are left with the last prime number
        prm.push_back(n);   // since last left afterwards is prime number only
        exp.push_back(1);
    }
}

int main(){
    int n;  cin >> n;
    primefactorization(n);
    return 0;
}   