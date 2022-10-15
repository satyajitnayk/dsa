Approach 1:
 
1. Since it is a directed graph, technique to find cycle in undirected graph
   will not work here.
2. So we will keep track of traversal in 2 vectors.
3. One is visited for all visited nodes till now & dfsVisited to keep track of 
   all visisted nodes in current state. 

#CODE:
bool checkCycle(int node, vector<int> adj[],vector<int> &vis, vector<int> &dfsvis) {
    vis[node] = 1;
    dfsvis[node] = 1;
    for(auto it: adj[node]) {
        if(!vis[it]) {
            if(checkCycle(it,adj,vis,dfsvis)) return true;
        } else if(dfsvis[it] == 1) return true;
    }    
    dfsvis[node] = 0;
    return false;
}
bool isCyclic(int n, vector<int> adj[]) {
    vector<int> vis(n+1,0), dfsvis(n+1,0);
    for(int i=0;i<n;++i) {
        if(!vis[i]) {
            if(checkCycle(i,adj,vis,dfsvis)) {
                return 1;
            }
        }
    }  
    return 0;
}

=> Time Complexity = O(N + E)
=> Space Complexity = O(2*N)