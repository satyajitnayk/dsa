Approach: 
1. If we found any visited node in the same path of dfs traversal then it contains cycle.
2. vis[] -> keep track of node visit & pathvis[] -> keep track of nodes in the same path.

#CODE:

class Solution {
    private boolean checkCycle(int node, ArrayList<ArrayList<Integer>> adj, 
    int vis[], int pathvis[]) {
        vis[node] = 1;
        pathvis[node] = 1;
        for(Integer it: adj.get(node)) {
            if(vis[it] == 0) {
                if(checkCycle(it, adj, vis, pathvis)) return true;
            } else if(pathvis[it] == 1) return true;
        }
        pathvis[node] = 0;
        return false;
    }
    public boolean isCyclic(int V, ArrayList<ArrayList<Integer>> adj) {
        int vis[] = new int[V];
        int pathvis[] = new int[V];
        for(int i=0;i<V;++i) {
            if(vis[i] == 0) {
                if(checkCycle(i,adj,vis,pathvis)) return true;
            }
        }
        return false;
    }
}