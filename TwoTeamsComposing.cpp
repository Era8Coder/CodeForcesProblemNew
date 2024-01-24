#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;  cin>>t;
    while(t--)
    {
        int n;  cin>>n;
        vector<int> v(n);
        int i;
        for(i=0; i<n; i++){
            cin >> v[i];
        }    
        vector<int> freq(n+1,0);            // freq. array
        for(i=0; i<n; i++){
            freq[v[i]]++;
        }
        int diff = 0;
        int maxcnt = INT_MIN;
        for(i=1; i<n+1; i++){
            if(freq[i]!=0){
                diff++;             // that it how many different elements are there in our frequency vector
                maxcnt = max(maxcnt,freq[i]);   // that is what is the maximum frequency in the array
            }
        }

        cout << max(min(maxcnt-1,diff),min(maxcnt,diff-1)) << endl;
        /*
            min(maxcnt-1,diff) :- Case when we had given one to the difference then one less in maxcnt
            min(maxcnt,diff-1) :- Case when we had given one to the maxcnt then one less in difference
        */
    }
    return 0;
}