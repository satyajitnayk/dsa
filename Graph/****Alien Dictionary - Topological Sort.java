# Approach:

1. B/w every pair of word find out which character is differentiating factor(coming before )
   i.e. b/w "abcd" , "abca" => 'd' is coming before 'a' => dictionary order 'd', 'a'
2. We can use topological sort to solve this.

#CODE:

class Solution {
    private int[] topoSort(int V, ArrayList<ArrayList<Integer>> adj) {
        int indegree[] = new int[V];
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
        int topo[] = new int[V];
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
        return topo;
    }
    public String findOrder(String [] dict, int N, int K) {
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for(int i=0;i<K;++i) {
            adj.add(new ArrayList<Integer>());
        }
        for(int i=0;i<N-1;++i) {
            String s1 = dict[i];
            String s2 = dict[i+1];
            int len = Math.min(s1.length(), s2.length());
            for(int ptr=0;ptr<len;++ptr) {
                char c1 = s1.charAt(ptr);
                char c2 = s2.charAt(ptr);
                if(c1 != c2) {
                    adj.get(c1 - 'a').add(c2 - 'a');
                    break;
                }
            }
        }
        int topo[] = topoSort(K, adj);
        String ans = "";
        for(int i=0;i<topo.length;++i) {
            ans += (char)(topo[i] + 'a');
        }
        return ans;
    }
}

=> Time Complexity = O(N*S + K) => S => max len of string 
=> Space Complexity = O(K)