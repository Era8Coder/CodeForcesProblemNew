#include<bits/stdc++.h>
using namespace std;
// Recursive solution of Knapsack

int knapsack(vector<int> wt, vector<int> val, int w, int n){
    if(n == 0 || w == 1){               // Base case of the recursive function
        return 0;
    }

    if(wt[n-1] <= w){
        return max(val[n-1] + knapsack(wt,val,w-wt[n-1],n-1), knapsack(wt,val,w,n-1));          // maximum of the cases when we had included the last vaue and when we had not included the last value ans proceeded with the left array 
    }else{
        return knapsack(wt,val,w,n-1);          // case when wt[n-1] > w
    }

}

int main(){
    int n;  cin>>n;                 // Size of the array's
    vector<int> wt(n);
    vector<int> val(n);
    for(int i=0; i<n; i++){
        cin >> wt[i];
    }
    for(int i=0; i<n; i++){
        cin >> val[i];
    }
    int w;
    cin >> w;               // weight of knapsack 
    cout << knapsack(wt,val,w,n) << endl;
    return 0;
}