// TiMe DoEsN't HeAl AnYtHiNg; It JuSt TeAcHeS HoW tO lIvE wItH pAiN -> World Asks me why I love Her ?
/*  
It's a dark valley, and you must reach the other side. There are N street lamps that light a circular area. The ith
lamp has a radius 'Ri'. The valley is filled with criminals, so you only want to travel in light to remain safe.

Given M and N as the valley's length and number of lamps, respectively.
As you only have to travel from (0,a)
→
(M,b) for any random numbers a and b, you can consider the width of the valley to be ∞. You can choose any a and b
of your choice.

For each lamp, you will be given X, Y, denoting the coordinate of the lamp, and R, denoting the radius of the lamp.
Find if it's possible to reach the other side safely.

// OUTPUT -> "YES" OR "NO"
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef priority_queue <int, vector<int>, greater<int>> minheap;
typedef priority_queue <int> maxheap;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define rep(i,a,b) for(int i=a; i<b; i++)
const int N=1e9+7;
const int M=1e8+7;
 
int gcd(int a, int b){
    if(a > b){
        swap(a,b);
    }
    int dividend = b;
    int divisor = a;
    int remainder = b%a;
    while(remainder != 0){
        dividend = divisor;
        divisor = remainder;
        remainder = dividend%divisor;
    }
    return divisor;
}

int bfs(vector<vector<int>> &adj, int src, int tgt, vector<int> &dist){
    queue<int> q;
    q.push(src);
    dist[src] = 0;              

    while(!q.empty())
    {
        int u = q.front();          
        q.pop();
        
        if(u == tgt){               
            return dist[u];
        }

        for(int v : adj[u]){                
            if(dist[v] == -1){            
                dist[v] = dist[u] + 1;
                q.push(v);               
            }
        }
    }
    return -1; // Target node is unreachable
}

double calc(int x1, int y1, int x2, int y2){
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
}

void solve(){
    int m,n;    cin >> m >> n;
    vector<tuple<int,int,int>> v;
    int x,y,r;  
    tuple<int,int,int> t;
    for(int i=0; i<n; i++){
        cin >> x >> y >> r;
        t = make_tuple(x,y,r);          // First two are Coordinates and later is Radius    
        v.push_back(t);
    }

    vector<vector<int>> graph(n+2);         // N+2 node wala Graph
    for(int i=0; i<n; i++)
    {
    for(int j=i+1; j<n; j++)                // Total n*(n+1)/2 __ :)
    {
        int x1 = get<0>(v[i]);
        int y1 = get<1>(v[i]);
        int x2 = get<0>(v[j]);
        int y2 = get<1>(v[j]);
        int r1 = get<2>(v[i]);
        int r2 = get<2>(v[j]);
        double k = calc(x1,y1,x2,y2);
        // cout << k << ":" << r1 + r2 << endl;
        if(k <= r1 + r2){
            graph[i+1].push_back(j+1);
            graph[j+1].push_back(i+1);              // Pushing both the values in Graph => That's the 
        }
    }
    }

    for(int i=0; i<n; i++)
    {
        int x = get<0>(v[i]);
        int r = get<2>(v[i]);
        if(r >= x){
            graph[0].push_back(i+1);
            graph[i+1].push_back(0);
        }
        if(r >= m - x){
            graph[n+1].push_back(i+1);
            graph[i+1].push_back(n+1);
        }
    }
    vector<int> dist(n+2,-1);
    if(bfs(graph,0,n+1,dist) != -1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;  cin>>t;
    while(t--){
        solve();
    }
    return 0;  
}