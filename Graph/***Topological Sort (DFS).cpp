Approach:

1. We can only have a topological sort only if the graph is DAG(Directed Acyclic).

#CODE:

void dfs(int node, vector<int> adj[],vector<int> &vis, stack<int> &st) {
    vis[node] = 1;
    for(auto it: adj[node]) {
        if(!vis[it]) {
            dfs(it,adj,vis,st);
        }
    }
    st.push(node);
}
vector<int> topoSort(int n, vector<int> adj[]) {
    vector<int> vis(n,0);
    stack<int> st;
    for(int i=0;i<n;++i) {
        if(!vis[i]) {
            dfs(i,adj,vis,st);
        }
    }
    vector<int> ans;
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
=> Time Complexity = O(N + E)
=> Space Complexity = O(N)