There are n cities connected by some number of flights. You are given an array 
flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight
 from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst
 with at most k stops. If there is no such route, return -1.

 ###Notes:
 -> Plain Dijkstra will not work because of greedyness of the algo
 i.e Once visited we do not visit a node again
 -> Need to get options to revisit the node with maybe more distance but 
   small number of stops
  ->Only revisiting node, if one of the following applies
  1.we just found a path with shorter distance
  2.we just found a path with fewer stops.


  CODE: Modified Dijkstra Algorithm

  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      vector<vector<pair<int,int>>> adj;
      adj.resize(n+1);
      for(int i=0; i<flights.size(); ++i) {
          adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
      }
      
      vector<int> dist(n+1,INT_MAX);
      vector<int> stops(n+1,INT_MAX);
      // minHeap
      priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> minHeap;
      dist[src] = 0;
      stops[src] = 0;
      minHeap.push({0,src,0});
      
      while(!minHeap.empty()) {
          auto [curDist,curNode,curStops] = minHeap.top();
          minHeap.pop();
          
          cout << "curNode :" << curNode << " dist :" << curDist << " curStops :"<<curStops<<"\n";
          if(curNode == dst) return curDist;
          if(curStops == k+1) continue;
          for(auto &[nextNode, nextWeight] : adj[curNode]) {
              int nextDist = curDist + nextWeight;
              int nextStops = curStops + 1;
              if(nextDist < dist[nextNode]) {
                  dist[nextNode] = nextDist;
                  stops[nextNode] = nextStops;
                  minHeap.push({nextDist, nextNode, nextStops});
              } else if(nextStops < stops[nextNode]) {
                  stops[nextNode] = nextStops;
                  minHeap.push({nextDist, nextNode, nextStops});
              }
          } 
      }
      return -1;
  }