Approach: Using queue.

#CODE:
void bfs() {
	for(int i=1;i<=n;++i) {
		if(!visited[i]) {
			queue<int> q;
			q.push(i);
			while(!q.empty()) {
				int n = q.size();
				int node = q.front();
				q.pop();
				cout << node << " ";
				visited[node] = true;
				for(auto x: adj[node]) {
					if(!visited[x]) {
						visited[x] = true;
						q.push(x);
					}
				}
			}
		}
	}
}
=> Time Complexity = O(N + E) => N for visiting N nodes, E for travelling through adjacent nodes.
=> Space Complexity = O(N + E)