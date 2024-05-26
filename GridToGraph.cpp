// Here we will learn how to convert Grid to Graph 
/*
    We will learn how to convert using Maximum number of islands Problems :)
*/
#include<bits/stdc++.h>
using namespace std;

// Step - 1) BaSiC => Always make a data structure point in the case of Grid 
struct Point{           // Defining the new data_type
    int x,y;    
    Point(int _x, int _y){              // Making _x and _y as new coordinates using point 
        x = _x;
        y = _y;             
    };
};

// Step - 2) Next Work is to check that points on which we are traversing and modifying are valid or not
bool isValidPoint(int x, int y, int rows, int cols){            // Checking validity of point
    return (x>=0 && x<rows && y>=0 && y<cols);          // if all these conditions are satisfied simultaneously then only we are on the valid point
}

// Step - 4) Writing the BFS function to calculate the Area of the island and from the node which I had not visited yet !!
int BFS(Point start, vector<vector<int>> &grid, vector<vector<bool>> &visited){ 
    int rows = grid.size();
    int cols = grid[0].size();
    queue<Point> q;
    q.push(start);
    visited[start.x][start.y] = true;       // That is we are starting from it and ready to make the traversal 
    int islandsize = 0;

    while(!q.empty()){              // Till We completely one connected component
        Point curr = q.front();         // that is the node on which I am currently 
        q.pop();
        islandsize++;               // which implies that we had convered "1" cells that is basically the first landmark 
        
        // To keep the track of neighbors
        vector<int> delta_x = {-1,0,0,1};   // change in x
        vector<int> delta_y = {0,1,-1,0};   // change in y

        for(int i=0; i<4; i++){
            int newX = curr.x + delta_x[i];
            int newY = curr.y + delta_y[i];
            if(isValidPoint(newX,newY,rows,cols) && grid[newX][newY]==1 && !visited[newX][newY]){
                /*
                    What we are checking in the "IF" condition ?? 
                    a) To check whether it's valid point or not
                    b) That whether that new cell is land or not 
                    c) Whether it is earlier visited or not
                */
               q.push(Point(newX,newY));            // pushing the new point into the queue
               visited[newX][newY] = true;
            }
        }
    }
    return islandsize;
}

// Step - 3) To start making the function which will calculate the maximum number of islands
int MaxIslands(vector<vector<int>> &grid){
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<bool>> visited(rows,vector<bool>(cols,false));        // Making the 2D array to check that which cell is visited or not
    int maxIslands = 0;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(grid[i][j] && !visited[i][j]){               // if grid[i][j] == 1{Land} and it's not visited then we can do the BFS traversal
                int islandsize = BFS(Point(i,j), grid, visited);                // Making the BFS function to get the island size from the which it's not visited and then calculating the area
                maxIslands = max(maxIslands, islandsize);       // old size and new which we had obtained afer doing the BFS traversal 
            }
        }
    }
    return maxIslands;              // that is the size of the Maximum Area Land/Island
}

int main(){
    // Example Grid :->
     vector<vector<int>> grid = {
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };
    cout << MaxIslands(grid) << endl;               // To get the maximum number of islands 
    /*
        Here we are considering the island as the land surrounded 4-directionally by Water
    */
    return 0;
}