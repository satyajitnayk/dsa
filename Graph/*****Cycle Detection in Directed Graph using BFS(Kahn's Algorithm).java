Approach: 
1. If we can get a topological sort of the graph then graph is DAG(Directed Acyclic Garph)

#CODE:

class Solution {
    public boolean isCyclic(int V, ArrayList<ArrayList<Integer>> adj) {
        int indegree[] = new int[V];
         int ans[] = new int[V];
         Arrays.fill(indegree, 0);
         for(int i=0;i<V;++i) {
             for(Integer it: adj.get(i)) {
                 indegree[it]++;
             }
         }
         
         Queue<Integer> q = new LinkedList<>();
         for(int i=0;i<V;++i) {
             if(indegree[i] == 0) {
                 q.offer(i);
             }
         }
         
         int cnt = 0;
         int idx = 0;
         while(!q.isEmpty()) {
             int node = q.poll();
             ans[idx++] = node;
             cnt++;
             for(Integer it: adj.get(node)) {
                 indegree[it]--;
                 if(indegree[it] == 0) {
                     q.offer(it);
                 }
             }
         }
         return cnt == V ? false : true;
    }
}