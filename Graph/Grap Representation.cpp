1. Adjacency Matrix: Can be done only for small number of nodes.
  - check 0 or 1 based indexing.
  - matrix[N][N]
  - Space Complexity = O(N*N)

2. Adjacency List:
  - vector<int> adj[N+1]
  - Space Complexity = O(N + 2*E)
  - For wtd graph: vector<pair<int,int>> adj[N+1]