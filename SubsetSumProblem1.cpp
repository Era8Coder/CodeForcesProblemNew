// We have to return the subset which has sum equal to the sum given in the problem 
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;  cin>>n;             // Array Size
    int w;  cin>>w;             // Target Sum 
    vector<int> wgt(n);         // wgt is the array which from which we have to choose the elements and to make the required sum
    for(int i=0; i<n; i++){
        cin >> wgt[i];
    }
    vector<vector<bool>> dp(n+1,vector<bool>(w+1,false));
    for(int i=0; i<n+1; i++){
        dp[i][0] = true;                        // since we can make SUM(j) = 0; don't matter that what is the size of array we can always choose an empty sub-set
    }
    for(int i=1; i<w+1; i++){
        dp[0][i] = false;
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<w+1; j++){
            if(wgt[i-1] <= j){                  // that is weight is less than the sum which we have to mak e
                dp[i][j] = dp[i-1][j-wgt[i-1]] || dp[i-1][j];         // updating the 2D array => OR Operator
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][w] << endl; 
    return 0;
}