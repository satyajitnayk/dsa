Q: You are given a network of n nodes, labeled from 1 to n. You are also given times, 
a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, 
vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes 
to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // create a adj list out of given input
    vector<vector<pair<int,int>>> adj;
    adj.resize(n+1);
    for(int i=0; i<times.size(); ++i) {
        adj[times[i][0]].push_back({times[i][1], times[i][2]});
    }

    // create minHeap
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

    vector<int> dist(n+1, INT_MAX);   
    vector<int> prev(n+1, -1);
    vector<bool> visited(n+1, false);

    dist[k] = 0;
    minHeap.push({0,k});

    while(!minHeap.empty()) {
        auto [curDist, curNode] = minHeap.top();
        minHeap.pop();

        if(!visited[curNode]) {
            visited[curNode] = true;
            // iterate over all neighbor of curNode & try to reduce their
            // distance from parent node
            for(auto &[nextNode, nextWeight] : adj[curNode]) {
                int nextDist = curDist + nextWeight;
                if(not visited[nextNode] && nextDist < dist[nextNode]) {
                    dist[nextNode] = nextDist;
                    prev[nextNode] = curNode;
                    minHeap.push({nextDist, nextNode});
                }
            }
        }
    }
    // Now iterate over dist & get max distance & return
    int minTime = -1;
    for(int i=1; i<dist.size(); ++i) {
        if(dist[i] == INT_MAX){
            return -1;
        }
        minTime = max(minTime, dist[i]); 
    }
    return minTime;
}