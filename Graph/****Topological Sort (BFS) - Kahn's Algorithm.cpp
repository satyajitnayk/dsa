Approach:

1. We will use indegree concept & queue.
2. Push those nodes whose indegree is 0 initially.
3. Then do BFS traversal.
4. Each node coming out of queue is topological sort.
5. Reduce indegree of each node which are adjacent of parent node in BFS.
6. When ever degree of any node become 0, put it into queue.

#CODE:

vector<int> topoSort(int n, vector<int> adj[]) {
    queue<int> q;
    vector<int> indegree(n,0);
    for(int i=0;i<n;++i) {
        for(auto it: adj[i]) {
            indegree[it]++;
        }
    }
    for(int i=0;i<n;++i) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it: adj[node]) {
            indegree[it]--;
            if(indegree[it] == 0) {
                q.push(it);
            }
        }
    }
    return ans;
}
=> Time Complexity = O(N + E)
=> Space Complexity = O(N) + O(N)