Approach:
1. Anyone who is a part of cycle or have an incoming edge to the cycle 
  can not be safe node.

#CODE:

class Solution {
    private boolean dfsCheck(int node, List<List<Integer>> adj,
    int vis[], int pathvis[], int check[]) {
        vis[node] = 1;
        pathvis[node] = 1;
        check[node] = 0;
        for(int it: adj.get(node)) {
            if(vis[it] == 0) {
                if(dfsCheck(it,adj,vis,pathvis,check)) return true;
            } else if(pathvis[it] == 1) return true;
        }
        check[node] = 1;
        pathvis[node] = 0;
        return false;
    }
    List<Integer> eventualSafeNodes(int V, List<List<Integer>> adj) {
        int vis[] = new int[V];
        int pathvis[] = new int[V];
        int check[] = new int[V];    
        
        for(int i=0;i<V;++i) {
            if(vis[i] == 0) {
                dfsCheck(i,adj,vis,pathvis,check);
            }
        }
        List<Integer> ans = new ArrayList<>();
        for(int i=0;i<V;++i) {
            if(check[i] == 1) {
                ans.add(i);
            }
        }
        return ans;
    }
}

=> Time Complexity = O(V + E)
=> Space Complexity = O(V)