#include<bits/stdc++.h>
using namespace std;
// DP solution of Knapsack

int knapsack(vector<int> wt, vector<int> val, int w, int n, vector<vector<int>> &dp){
    if(n == 0 || w == 1){               // Base case of the recursive function
        return 0;
    }

    if(dp[n][w] != -1){
        return dp[n][w];
    }

    if(wt[n-1] <= w){
        return dp[n][w] = max(val[n-1] + knapsack(wt,val,w-wt[n-1],n-1,dp), knapsack(wt,val,w,n-1,dp));          // maximum of the cases when we had included the last vaue and when we had not included the last value ans proceeded with the left array 
    }else{
        return dp[n][w] = knapsack(wt,val,w,n-1,dp);          // case when wt[n-1] > w
    }
}

int main(){
    int n;  cin>>n;                 // Size of the array's
    vector<int> wt(n);
    vector<int> val(n);
    int w;
    cin >> w;               // weight of knapsack 
    
    vector<vector<int>> dp(n+1, vector<int>(w+1,-1));               // Initialising the array with -1 

    for(int i=0; i<n; i++){
        cin >> wt[i];
    }
    for(int i=0; i<n; i++){
        cin >> val[i];
    }
    cout << knapsack(wt,val,w,n,dp) << endl;
    return 0;
}