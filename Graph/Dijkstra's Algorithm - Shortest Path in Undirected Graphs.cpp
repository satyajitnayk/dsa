vector <int> dijkstra(int n, vector<pair<int,int>>> adj[], int src) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
    vector<int> distTo(n,INT_MAX);
    minHeap.push({0,src});
    distTo[src] = 0;
    while(!minHeap.empty()) {
        auto p = minHeap.top();
        minHeap.pop();
        int prev = p.second;
        int dist = p.first;
        for(auto it: adj[prev]) {
            int nextNode = it.first;
            int nextDist = it.second;
            if(distTo[nextNode] > distTo[prev] + nextDist) {
                distTo[nextNode] = distTo[prev] + nextDist;
                minHeap.push({distTo[nextNode], nextNode});
            }
            
        }
    }
    return distTo;
}
=> Time Complexity = O((N+E)*Log N) => log N for priority queue operations on (N+E) time.
=> Space Complexity = O(N)