Approach:

1. If we can get topologic sort then we can say graph is DAG, else graph is cyclic.

#CODE:
bool isCyclic(int n, vector<int> adj[]) {
    vector<int> indegree(n,0);
    for(int i=0;i<n;++i) {
        for(auto it: adj[i]) {
            indegree[it]++;
        }
    }
    queue<int> q;
    int count = 0;
    for(int i=0;i<n;++i) {
        if(indegree[i] == 0) {
            q.push(i);  
        }
    }
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        count++;
        for(auto it: adj[node]) {
            indegree[it]--;
            if(indegree[it] == 0) {
                q.push(it);
            }
        }
    }
    return count != n;
}
=> Time Complexity = O(N + E)
=> Space Complexity = O(N)