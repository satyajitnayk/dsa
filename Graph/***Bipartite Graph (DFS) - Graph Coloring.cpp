Approach:
1. Try to color the graph using 2 colors, if possible then Bipartite, else not.

#CODE:

bool bipartiteDfs(int src, vector<vector<int>> &graph,vector<int> &color) {
    if(color[src] == -1) color[src] = 1;
    for(auto it: graph[src]) {
        if(color[it] == -1) {
            color[it] = 1 - color[src];
            if(!bipartiteDfs(it,graph,color)) return false;
        } else if(color[it] == color[src]) {
            return false;
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n,-1);
    for(int i=0;i<n;++i) {
        if(color[i] == -1) {
            if(!bipartiteDfs(i,graph, color)) return false;
        }
    }
    return true;
}
=> Time Complexity = O(N + E)
=> Space Complexity = O(N + E)