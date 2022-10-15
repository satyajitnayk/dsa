#CODE:

void shortestPath(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> dist(n,INT_MAX);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    int ans = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(auto it: adj[node]) {
            if(dist[node] + 1 < dist[it]) {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }
}
=> Time Complexity = O(N + E)
=> Space Complexity = O(N)