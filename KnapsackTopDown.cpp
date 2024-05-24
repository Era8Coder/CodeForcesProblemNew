#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,w;    cin >> n >> w;
    vector<int> val(n);
    vector<int> wgt(n);
    for(int i=0; i<n; i++){ 
        cin >> wgt[i];                  // Weight 
    }
    for(int i=0; i<n; i++){
        cin >> val[i];                  //  Value of that weight
    }
    vector<vector<int>> dp(n+1, vector<int>(w+1,-1));               // Initialisation of a 2D vector 
    for(int i=0; i<n+1; i++){
        dp[i][0] = 0;               // Making first column = 0
    }
    for(int j=0; j<w+1; j++){
        dp[0][j] = 0;
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<w+1; j++){
            if(wgt[i-1] <= j){                  // if weight is less than the bag size then pnly we can consider the case of extra weight
                dp[i][j] = max(val[i-1] + dp[i-1][j-wgt[i-1]],dp[i-1][j]);              // to get the maximum profit => 1) we had accounted the val[i-1] and when we had not
            }else{
                dp[i][j] = dp[i-1][j];          // Case when wgt[i-1] >= j => Then it will work 
            }
        }
    }
    cout << dp[n][w] << endl;
    return 0;
}