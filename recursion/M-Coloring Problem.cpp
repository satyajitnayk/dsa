Given an undirected graph and an integer M. The task is to determine if the graph can 
be colored with at most M colors such that no two adjacent vertices of the graph are colored
with the same color. Here coloring of a graph means the assignment of colors to all vertices. 
Print 1 if it is possible to colour vertices and 0 otherwise.

##Approach:
1. iterate over all colors & try if we can color the current node with it or not.
2. if yes return true;
3. else return false after the loop.

f(node) {
  if(node == n) return true;
  for(int col=1 to m) {
    if(isSafe(node,col)) {
      // color node with color col 
      color[node] = col;
      if(f(node+1)) return true;
      // backtrack
      color[node] = 0;
    }
  }
  return false;
}


#CODE:

bool isSafe(int node, int col, int color[],int n, int m, bool graph[101][101]) {
   // check if any adjacent node have same color
   for(int k=0;k<n; ++k) {
       if(graph[node][k] == 1 && color[k] == col) return false;
   }
   return true;
}
bool solve(int node, int m, int n, int color[], bool graph[101][101]) {
    if(node == n) return true;
    
    for(int col=1; col<=m; ++col) {
        if(isSafe(node,col,color,n,m,graph)) {
            color[node] = col;
            if(solve(node+1,m,n,color,graph)) return true;
            color[node] = 0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n) {
    int color[n] = {0};
    return solve(0,m,n,color,graph);
}

// we are tryinig out M colors on N nodes
=> Time complexity O(N^M) 
// height of tree = No of nodes N
=> Space complexity O(N)