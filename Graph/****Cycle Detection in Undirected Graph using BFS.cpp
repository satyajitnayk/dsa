Approach:

1. If any node is not previous/parent node & already visited that means it contains cycle.

#CODE:
bool checkCycle(int node,vector<int> &vis,vector<int> adj[]) {
    queue<pair<int,int>> q;
    q.push({node,-1});
    while(!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        vis[node] = 1;
        for(auto it:adj[node]) {
            if(!vis[it]) {
                vis[it] = 1;
                q.push({it,node});
            } else if (it != parent) return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<int> adj[]) {
    vector<int> vis(V+1,0);
    for(int i=0;i<V;++i) {
        if(!vis[i]) {
            if(checkCycle(i,vis,adj)) return true;
        }
    }
    return false;
}