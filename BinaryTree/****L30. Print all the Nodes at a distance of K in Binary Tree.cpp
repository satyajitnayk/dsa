Approach: 

1. Make use of parent pointer of each child.
2. Store parent nodes in a map using level order traversal.

#CODE:

void markParents(TreeNode* cur, unordered_map<TreeNode*, TreeNode*> &parents) {
    queue<TreeNode*> q;
    q.push(cur);
    while(!q.empty()) {
        int n = q.size();
        for(int i=0;i<n;++i) {
            TreeNode *node = q.front();
            q.pop();
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
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<int> ans;
    if(!root) return ans;
    // 1st BFS to keep track of parent nodes of each node
    unordered_map<TreeNode*, TreeNode*> parents;
    markParents(root,parents);
    
    // 2nd BFS traversal to get all nodes at a distance of k from target node
    unordered_map<TreeNode*, bool> visited;
    queue<TreeNode*> q;
    q.push(target);
    visited[target] = true;
    int level = 0;
    while(!q.empty()) {
        int n = q.size();
        if(level == k) break;
        level++;
        for(int i=0;i<n;++i) {
            TreeNode *cur = q.front();
            q.pop();
            if(cur->left && !visited[cur->left]) {
                q.push(cur->left);
                visited[cur->left] = true;
            }
            if(cur->right && !visited[cur->right]) {
                q.push(cur->right);
                visited[cur->right] = true;
            }
            if(parents[cur] && !visited[parents[cur]]) {
                q.push(parents[cur]);
                visited[parents[cur]] = true;
            }
        }
    }
    while(!q.empty()) {
        ans.push_back(q.front()->val);
        q.pop();
    }
    return ans;
}
=> Time Complexity = O(n* log n) => log n for hash map
=> Space Complexity = O(n)