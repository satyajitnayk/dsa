class Solution {

    List<Integer> eventualSafeNodes(int V, List<List<Integer>> adj) {
        ArrayList<ArrayList<Integer>> revAdj = new ArrayList<>();
        for(int i=0;i<V;++i) {
            revAdj.add(new ArrayList<Integer>());
        }
        int indegree[] = new int[V];
        Arrays.fill(indegree, 0);
        for(int i=0;i<V;++i) {
            for(Integer it: adj.get(i)) {
                revAdj.get(it).add(i);
                indegree[i]++;
            }
        }
        Queue<Integer> q = new LinkedList<>();
        List<Integer> safeNodes = new ArrayList<Integer>();
        for(int i=0;i<V;++i) {
            if(indegree[i] == 0) {
                q.offer(i);
            }
        }
        while(!q.isEmpty()) {
            Integer node = q.poll();
            safeNodes.add(node);
            for(Integer it: revAdj.get(node)) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.offer(it);
                }
            }
        }
        Collections.sort(safeNodes);
        return safeNodes;
    }
}