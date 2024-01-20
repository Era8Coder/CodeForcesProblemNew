#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;  cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
    {
        cin >> v[i];
    }
    int maxi = INT_MIN;
    int counter = 0;
    for(int i = 0; i < n; i++){
        if(v[i] > maxi)
        {   
            counter = 1;
            maxi = v[i];
        }else if(v[i] == maxi)
        {
            counter++;
        }
    }
    cout << "Max Element : " << maxi << " Frequency : " << counter << endl;
    return 0;
}