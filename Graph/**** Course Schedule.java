Approach: We can use concept of topological sort here.

#CODE:
static int[] findOrder(int n, int m, ArrayList<ArrayList<Integer>> prerequisites) {
    ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
    for(int i=0;i<n;++i) {
        adj.add(new ArrayList<Integer>());
    }
    
    for(int i=0;i<m;++i) {
        int a = prerequisites.get(i).get(0);
        int b = prerequisites.get(i).get(1);
        adj.get(b).add(a);
    }
    
    int indegree[] = new int[n];
    for(int i=0;i<n;++i) {
        for(Integer it: adj.get(i)) {
            indegree[it]++;
        }
    }
    Queue<Integer> q = new LinkedList<>();
    for(int i=0;i<n;++i) {
        if(indegree[i] == 0) {
            q.offer(i);
        }
    }
    int topo[] = new int[n];
    int idx = 0;
    
    while(!q.isEmpty()) {
        int node = q.poll();
        topo[idx++] = node;
        for(Integer it: adj.get(node)) {
            indegree[it]--;
            if(indegree[it] == 0) {
                q.offer(it);
            }
        }
    }
    if(idx == n) return topo;
    else return new int[0];
}

=> Time Complexity = O(V + E)
=> Space Complexity = O(V + E)