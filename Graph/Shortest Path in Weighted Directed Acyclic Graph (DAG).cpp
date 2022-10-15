Approach 1:

1. Do topological sort & store in a stack.
2. Fill distance vector with infinity.
2. Go through stack & fill the distance vector in order of node getting out from stack.

=> Time Complexity = O(N + E)
=> Space Complexity = O(N)
=> Auxiliary space = O(N)

#CODE:

void shortestPath(int src, int n, vector<pair<int,int>> adj[]) {
  vector<int> vis(n,0);
  stack<int> st;
  for(int i=0;i<n;++i) {
    if(!vis[i]) {
      findTopoSort(i,vis,st,adj);
    }
  }
  vector<int> dist(n,INT_MAX);
  dist[src] = 0;
  while(!st.empty()) {
    int node = st.top();
    st.pop();
    if(dist[node] != INT_MAX) {
      for(auto it: adj[node]) {
        if(dist[node] + it.second < dist[it.first]) {
          dist[it.first] = dist[node] + it.second;
        }
      }
    }
  }
  for(auto x: dist) cout  << x << " ";
}
int main() {
  int n, m; cin >> n >> m;
  vector<pair<int,int>> adj[n];
  for(int i=0;i<m;++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v,w});
  }
  shortestPath(0,n,adj);
}