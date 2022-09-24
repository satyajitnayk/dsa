Approach:

1. We can use all nodes at distance k technique.

#CODE:
Node* markParents(Node *cur,unordered_map<Node*, Node*> &parents,int target) {
    queue<Node*> q;
    q.push(cur);
    Node *targetNode;
    while(!q.empty()) {
        int n = q.size();
        for(int i=0;i<n;++i) {
            Node *node = q.front();
            q.pop();
            if(node->data == target) {
                targetNode = node;
            }
            if(node->left) {
                parents[node->left] = node;
                q.push(node->left);
            }
            if(node->right) {
                parents[node->right] = node;
                q.push(node->right);
            }
        }
    }
    return targetNode;
}
int minTime(Node* root, int target) {
    if(!root) return 0;
    // mark parents of each node &  search the target node
    unordered_map<Node*, Node*> parents;
    Node *targetNode = markParents(root, parents,target);
    queue<Node*> q;
    unordered_map<Node*,bool> visited;
    q.push(targetNode);
    visited[targetNode] = true;
    int time = 0;
    while(!q.empty()) {
        int n = q.size();
        // Flag to keep track if I burn anything then only increase the time
        int flag=0;
        for(int i=0;i<n;++i) {
            Node *node = q.front();
            q.pop();
            if(node->left && !visited[node->left]) {
                flag = 1;
                visited[node->left] = true;
                q.push(node->left);
            }
            if(node->right && !visited[node->right]) {
                flag = 1;
                visited[node->right] = true;
                q.push(node->right);
            }
            if(parents[node] && !visited[parents[node]]) {
                flag = 1;
                visited[parents[node]] = true;
                q.push(parents[node]);
            }
        }
        if(flag == 1) time++;
    }
    return time;
}
=> Time Complexity = O(n*log n)
=> Space Complexity = O(n)