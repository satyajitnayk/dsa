void dfs(int i,vector<int> adj[],vector<bool> &visited) {
  cout << i << "\n";
	visited[i] = true;
	for(auto x: adj[i]) {
		if(!visited[x]) {
			dfs(x,adj,visited);
		}
	}
}
int main() {
	for(int i=1;i<=n;++i) {
		if(!visited[i]) {
			dfs(i)
		}
	}
}
=> Time & Space Complexity = O(N + E)