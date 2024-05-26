// How to detect cycle in Directed Graphs using BFS Algorithm
#include<bits/stdc++.h>
using namespace std;

void addedge(vector<vector<int>> &graph,int u, int v){              // There is a ray pointing fromu to v
    graph[u].push_back(v);
}

pair<bool, vector<int>> cycle(vector<vector<int>>& graph, int V) {
    vector<int> indegree(V, 0);

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < graph[i].size(); ++j) {
            indegree[graph[i][j]]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    int cnt = 0; // Count of visited vertices
    vector<int> topo;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cnt++;
        topo.push_back(u);

        for (auto v : graph[u]) {
            if (--indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (cnt != V) {
        return { true, {} }; // Cycle exists
    } else {
        return { false, topo}; // No cycle
    }
}

int main(){
    int V = 6;
    vector<vector<int>> graph(V);                   // Making 2D graph here
    // cout << "Hey" << endl;
    addedge(graph,0,1);
    addedge(graph,1,2);
    addedge(graph,2,0);
    addedge(graph,3,4);
    addedge(graph,4,5);
    // cout << "Me" << endl;
    bool check = cycle(graph,V).first;
    vector<int> topo = cycle(graph,V).second;
    if(check){
        // cout << "Le" << endl;
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
        cout << "Topological Sort of the Given Array is : " << endl;
        for(int i=0; i<topo.size(); i++){
            cout << topo[i] << " ";
        }
    }   
    return 0;  
}
