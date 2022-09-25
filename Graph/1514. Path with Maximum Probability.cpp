1514. Path with Maximum Probability
You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge 
list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a 
probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go 
from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs 
from the correct answer by at most 1e-5.

Example:
   0.5      0.8     0.3
0------1---------2------3

Let take probability of getting from 0 to o is 1
cost[0] = 1
cost[1] = 1*0.5 = 0.5
cost[2] = 0.5 * 0.8 = 0.04
....which is decreasing => Dijkastra algo only applicable 
in case where cost of next node always >= current node
==> TWEAK: Take initial probability as -1

==>
cost[0] = -1
cost[1] = -1*0.5 = -0.5
cost[2] = -0.5 * 0.8 = -0.04

=> Now it can be solved by Dijkastra algo


CODE:



double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    // create adj list of graph
    vector<vector<pair<int, double>>> adj;
    adj.resize(n+1);
    for(int i=0;i < edges.size();++i) {
        adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
        adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
    }
    
    // minHeap
    priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> minHeap;
    vector<double> prob(n+1,0);
    vector<bool> visited(n+1,false);
    
    prob[start] = -1;
    minHeap.push({-1,start});
    
    while(!minHeap.empty()) {
        auto [curProb,curNode] = minHeap.top();
        minHeap.pop();
        if(curNode == end) break;
        if(not visited[curNode]) {
            visited[curNode] = true;
            for(auto &[nextNode, nextProb] : adj[curNode]) {
                double newProb = curProb * nextProb;
                if(not visited[nextNode] && newProb < prob[nextNode]) {
                    prob[nextNode] = newProb;
                    minHeap.push({newProb, nextNode});
                }
            }
        }
    }
    // -1 is multiplied to give acttual value
    return -prob[end];   
}


