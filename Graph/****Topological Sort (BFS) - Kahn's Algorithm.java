Approach:

1. We will use indegree concept & queue.
2. Push those nodes whose indegree is 0 initially.
3. Then do BFS traversal.
4. Each node coming out of queue is topological sort.
5. Reduce indegree of each node which are adjacent of parent node in BFS.
6. When ever degree of any node become 0, put it into queue.

class Solution
{
    //Function to return list containing vertices in Topological order. 
    static int[] topoSort(int V, ArrayList<ArrayList<Integer>> adj) 
    {
        int indegree[] = new int[V];
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
        
        int ans[] = new int[V];
        int cnt = 0;
        int idx = 0;
        while(!q.isEmpty()) {
            Integer node = q.poll();
            ans[idx++] = node;
            cnt++;
            
            for(Integer it: adj.get(node)) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.offer(it);
                }
            }
        }
        return ans;
    }
}