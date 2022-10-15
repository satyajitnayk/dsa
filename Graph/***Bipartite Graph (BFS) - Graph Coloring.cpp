Approach 1:
=> Bipartite => Graph can be 2 colored. (can be colored using only 2 colors)
1. If a graph has odd length cycle then its not Bipartite.
2. Else graph is Bipartite.
3. We can use BFs traversal & at each level reverse the color an try to color neighbour.

#CODE:

bool bipartiteBfs(int src, vector<vector<int>> &graph,vector<int> &color) {
    queue<int> q;
    q.push(src);
    color[src] = 1;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto it: graph[node]) {
            if(color[it] == -1) {
                color[it] = 1 - color[node];
                q.push(it);
            } else if(color[it] == color[node]) {
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n,-1);
    for(int i=0;i<n;++i) {
        if(color[i] == -1) {
            if(!bipartiteBfs(i,graph, color)) return false;
        }
    }
    return true;
}

=> Time Complexity = O(N + E)
=> Space Complexity = O(N + E)