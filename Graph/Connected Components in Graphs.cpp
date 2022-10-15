Approach 1: Using DFS/BFS Traversal.

#CODE:
void dfs(int i,vector<int> adj[],vector<bool> &visited) {
	visited[i] = true;
	for(auto x: adj[i]) {
		if(!visited[x]) {
			dfs(x,adj,visited);
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> adj[n+1];
	for(int i=1;i<=m;++i) {
		int u,v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<bool> visited(n+1,false);
	int ans = 0;
	for(int i=1;i<=n;++i) {
		if(!visited[i]) {
			ans++;
			dfs(i,adj,visited);
		}
	}
	cout << ans << "\n";
}
=> Time Complexity = O(N + E)
=> Space Complexity = O(N + E)
