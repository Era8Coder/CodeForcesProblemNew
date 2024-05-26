// Detecting cycle in a grpah using BFS Traversal => Undirected Grpah Here
#include<bits/stdc++.h>
using namespace std;

// Step - 1) Adding Edge in the graph 
/*
    Passing by reference => On the original we are making the changes
    Passing by Value => After making it's copy we are making changes
*/
void addEdge(vector<vector<int>> &graph, int u, int v){             // Pass grpah by reference not by value since we modifying the original grpah not it's copy
    graph[u].push_back(v);
    graph[v].push_back(u);
}

// Step - 3) Doing BFS Traversal and cheking whether cycle exists or not
bool BFS(vector<vector<int>> &graph, int S, int V, vector<bool> &visited){          // To update the visited array and having start node from where BFS is starting and number of vertices
    queue<int> q;           // Create a queue
    q.push(S);              // Pushing the current node

    while(!q.empty()){                  // Till the queue becomes empty 
        // Dequeue a vertex from queue and printing it
        int curr = q.front();
        q.pop();

        if(visited[curr]){
            return true;            // => This implies that cycle is detected 
        }

        visited[curr] = true;       // If the current node is not visited then mark it as visited

        // Visit the adjacent nodes or neighbors => Work of BFS :)
        for(auto it : graph[curr]){
            if(!visited[it]){                       // If we had not visited the curr nodes till now then push them in the queue
                q.push(it);
            }
        }           
    }   
    return false;
}

// Step - 2) Function to check whether cycle exists or not
bool cycle(vector<vector<int>> &graph, int V){           // Function to detect cycle
    // Marking all the vertices as not visited
    vector<bool> visited(V, false);         // To make the visited array 
    for(int i=0; i<V; i++){     // traversing all teh nodes what is they are not connected 
        if(!visited[i] && BFS(graph, i, V, visited)){           // Doing the BFS traversal if the current node is not visited and checking that whther cycle exissts using BFS traversal  
            return true;        // If both are true simultaneously then we can say that => Cycle exists in the Graph
        }
    }
    return false;
}

int main(){
    int V = 4;      // Number of Vertices in the Graph
    vector<vector<int>> graph(V);       // Graph with Vertices V and now we are goind to add edge in the Graph
    addEdge(graph,0,1);
    addEdge(graph,1,2);
    addEdge(graph,2,0);
    addEdge(graph,2,3);         // Here we had made the Undirected Graph :)
    if(cycle(graph,V)){
        cout << "Cycle Exists" << endl;
    }else{
        cout << "No Cycle" << endl;
    }
    return 0;
}