-> Keep adding smallest edge wt of all nodes & avoid cycle.

Approach: Brute Force

1. Keep on adding minimum edges, till we cover N-1 edges.

#CODE:

void spanningTree(int N, vector<vector<int>> adj[]) {
    vector<int> parent(N,-1), key(N,INT_MAX);
    vector<bool> mstSet(N,false);
    key[0] = 0;
    parent[0] = -1;
    for(int count=0;count<N-1;++count) {
        int mini = INT_MAX, u;
        for(int v=0;v<N;++v) {
            if(mstSet[v] == false && key[v] < mini) {
                mini = key[v], u=v;
            }
        }
        // mark node u as added to mst
        mstSet[u] = true;
        for(auto it: adj[u]) {
            int v = it[0];
            int weight = it[1];
            if(mstSet[it] == false & weight < key[v]) {
                parent[v] = u, key[v] = weight;
            }
        }
    }
    for(auto it: parent) cout << it << " ";
}