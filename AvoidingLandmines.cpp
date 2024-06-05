// Avoiding LandMines Problem :-
/*
There are N cities with M
bi-directional roads between them. You want to travel 
from a given source city to target city. But there are
some cities that have landmines in them and you will die 
if you visit these cities.

Find the smallest number of roads that you can take to complete your travel 
without dying. If it is not possible to do so output −1.

Input : 
The first line contains two integers N and M denoting the number 
of cities and the number of roads respectively.

The second line contains two integers: source and target.

The third line contains N integers which are either 0 or 1
denoting whether each city has landmines or not. (1
means that the city has landmines.)

Finally, there are M
lines containing 2
integers each u
and v
denoting that there is a road between city u
and city v.
*/

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;

void bfs(vector<vector<int>> &adj, int src, int tgt, vector<int> &dist, vector<bool> &landmines){
    queue<int> q;
    q.push(src);
    dist[src] = 0;              // Distance of source has been made Zero by them 

    while(!q.empty())
    {
        int u = q.front();          // Take out the First Element from the Queue
        q.pop();

        if(u == tgt){               // If u are at target node then return the minimum distance
            cout << dist[u] <<  endl;
            return;
        }

        for(int v : adj[u]){                // To all the nodes/vertices which are neighbors of u
            if(!landmines[v] && dist[v] == -1){            // That there is no Landmine in that City and You had not visited that city yet
                dist[v] = dist[u] + 1;
                q.push(v);              // push the neighboring node in to the Queue as per BFS Algorithm
            }
        }
    }

    cout << -1 << endl;
}

int main(){
    int N,M,src,tgt;
    cin >> N >> M >> src >> tgt;
    vector<vector<int>> adj(MAXN);
    vector<bool> landmines(MAXN);
    vector<int> dist(MAXN);
    bool x;
    for(int i=0; i<N; i++){         // Which all cities have LandMines
        cin >> x;
        landmines[i] = x;
        dist[i] = -1;
    }

    // Making an undirected Graph
    for(int i=0; i<M; i++){
        int u,v;    cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(adj,src,tgt,dist,landmines);                // Doing BFS Traversal From Source To Target
    return 0;
}