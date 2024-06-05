/*
In a region consisting of N towns, there are M
bidirectional roads connecting these towns. Each 
road is of equal length. In this region, there are 
two types of armies stationed: the Red Army and the 
Blue Army. The Red Army is stationed in R distinct towns, 
and the Blue Army is stationed in B
distinct towns, with no town hosting both a Red and a 
Blue army unit simultaneously.

Find the minimum amount of time required for any two armies 
of different colors to clash. It is known that an army can 
travel from one town to another across any road in exactly one day. 
Consider all possible paths and scenarios in which the two armies 
might travel and clash. Armies can move independently and simultaneously.

If two armies can never clash, then print "-1".

Input
The first line contains two integers N and M, the number of towns and 
the number of bidirectional roads respectively.
The second line contains N integers, where each integer is either 0 
(no army), 1 (Blue army), or 2 (Red army), representing the presence of an army in each town.
The next M lines each contain two integers u and v, representing a bidirectional road between towns u and v
*/

#include<bits/stdc++.h>
using namespace std;

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

int main(){
    int n,m;    
    cin >> n >> m;
    vector<vector<int>> graph(n+2);
    vector<int> dist(n+2,-1);
    int src = 0;
    int tgt = n+1;
    int x;     
    for(int i=1; i<n+1; i++)
    {       
        cin >> x;
        if(x == 1){             
            graph[i].push_back(0);
            graph[0].push_back(i);
        }else if(x == 2){       
            graph[n+1].push_back(i);
            graph[i].push_back(n+1);
        }
    }
    int u,v;    
    for(int i=0; i<m; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    int k = bfs(graph, src, tgt, dist);
    if(k == -1){
        cout << -1 << endl;
    }else{
        cout << (k - 2)/2.0 << endl;
    }
    return 0;
}

