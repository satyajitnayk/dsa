Dijkstra is a Single Source Shortest Path (Greedy Algorithm)
V :#nodes E: #Edges
O(V+E) space

Time:
-> Initialiazation take O(V)
->Each push to heap take O(log E)
there are E push => => O(E*logE)
Time  = O(ElogE + V)

function Dijkstra(Graph, source):
  create minHeap of pairs <distance, node>sorted by distance
  for each node v in Graph: // Initialization
    dist[v] = INFINITY
    prev[v] = UNDEFINED
    visited[v] = false
  dist[source] = 0
  minHeap.push({0, source})

  while minHeap is not empty:
    [curDist, curNode] =  minHeap.pop() // Greeddy step! Pop node with min distance
    // If we want to get shortest distance till some specific node target
    // then write => if curNode is traget: break
    if visited[curNode] continue
    visited[curNode] = true
    for each neighbor nextNode of curNode:
      nextDist = curDist + w(curNode, nextNode)
      if not visited[nextNode] and nextDist < dist[nextNode]: // Better path found
        dist[nextNode] = nextDist
        prev[nextNode] = curNode
        minHeap.push({nextDist, nextNode})

  return dist, prev



class Graph {
  vector<vetcor<pair<int,int>>> adj;
  int nNodes;
  void generateGraph(vector<vector<int>> &inputs, int n) {
    nNodes = n;
    adj.resize(nNodes+1);
    for(int i=0 ; i <inputs.size(); ++i){
      adj[input[i][0]].push_back({inputs[i][1], inputs[i][2]});
    }
  }

  void clear() {
    adj.clear();
  }
}

// CODE 
pair<vector<int>, vector<int>> Dijkstra(Graph g, int source) {
  // create minHeap of pairs <distance, node>sorted by distance
  priority_queue<pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int>>> minHeap;

  vector<int> dist(g.Nodes+1,INT_MAX);
  vector<int> prev(g.Nodes+1,-1);
  vector<bool> visited(g.Nodes+1,false);

  dist[source] = 0
  minHeap.push({0, source})

  while(!minHeap.empty()) {
    auto [curDist, curNode] = minHeap.top();
    minHeap.pop();

    if(visited[curNode]) continue;
    visited[curNode] = true;
    for(auto &[nextNode, nextWeight] : g.adj[curNode]) {
      int nextDist = curDist + nextWeight;
      if(not visited[nextNode] && nextDist < dist[nextNode]) {
        dist[nextNode] = nextDist;
        prev[nextDist] = curNode;
        minHeap.push({nextDist, nextNode});
      }
    }
  }

  return {dist, prev};

}
