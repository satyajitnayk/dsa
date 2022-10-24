Approach:

1. We can only have a topological sort only if the graph is DAG(Directed Acyclic).

#CODE:
class Solution
{   
    static void dfs(int node, ArrayList<ArrayList<Integer>> adj, int vis[], Stack<Integer> st) {
        vis[node] = 1;
        for(Integer it: adj.get(node)) {
            if(vis[it] == 0) {
                dfs(it, adj, vis, st);
            }
        }
        st.push(node);
    }
    static int[] topoSort(int V, ArrayList<ArrayList<Integer>> adj) 
    {
        int vis[] = new int[V];
        Arrays.fill(vis, 0);
        Stack<Integer> st = new Stack<Integer>();
        
        for(int i=0;i<V;++i) {
            if(vis[i] == 0) {
                dfs(i, adj, vis, st);
            }
        }
        
        int ans[] = new int[V];
        int idx = 0;
        while(!st.isEmpty()) {
            Integer node = st.pop();
            ans[idx++] = node;
        }
        return ans;
    }
}