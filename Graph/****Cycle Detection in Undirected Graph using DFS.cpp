Approach:

1. If any node is not previous/parent node & already visited that means it contains cycle.

#CODE:

bool checkCycle(int node, int parent,vector<int> &vis,vector<int> adj[]) {
    vis[node] = 1;
    for(auto it: adj[node]) {
        if(!vis[it]) {
            if(checkCycle(it,node,vis,adj)) return true;
        } else if(it != parent) return true;
    }
    return false;
}
bool isCycle(int N, vector<int> adj[]) {
    vector<int> vis(N+1,0);
    for(int i=0;i<N;++i) {
        if(!vis[i]) {
            if(checkCycle(i,-1,vis,adj)) return true;
        }
    }
    return false;
}
=> Time Complexity = O(N + E)
=> Space Complexity = O(N + E)