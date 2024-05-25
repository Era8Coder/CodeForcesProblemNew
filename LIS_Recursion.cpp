#include<bits/stdc++.h>
using namespace std;

int longest(int idx, int prev_idx, vector<int>& v) {
    if (idx == v.size()) {              // Base case when it had reached the last index that is equal to size of the array
        return 0;
    }   

    int length = 0;             // initialising  the size of length of subarray
    
    // Taking the element
    if (prev_idx == -1 || v[idx] > v[prev_idx]) {               // taking the element if it's the first element or the case of increasing subsequence
        length = max(length, 1 + longest(idx + 1, idx, v));             // new length = maximum of current one or when we had added
    }

    // Not taking the element
    length = max(length, longest(idx + 1, prev_idx, v));       // Not taking the element

    return length;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    int idx = 0;
    int prev_idx = -1;
    int ans = longest(idx, prev_idx, v);
    cout << ans << endl;
    return 0;
}
