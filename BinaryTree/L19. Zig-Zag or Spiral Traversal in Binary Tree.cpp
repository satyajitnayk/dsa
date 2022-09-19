Approach 1:

1. Use levelOrder Traversal 
2. Use flag to keep track of order of Traversal, each time change 1 to 0 and back to 1 and so on..
3. flag=0 means L => R , flag=1 means R => levelOrder

#CODE:
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    queue<TreeNode*> q;
    q.push(root);
    int flag = 0;
    while(!q.empty()) {
        int n = q.size();
        vector<int> v;
        for(int i=0;i<n;++i) {
            TreeNode *node = q.front();
            q.pop();
            v.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        if(flag == 1) {
            reverse(v.begin(),v.end());
        }
        ans.push_back(v);
        flag = (flag +1)%2;
    }
    return ans;
}
=> Time Complexity = O(n^2)
=> Space Complexity = O(n)

Approach 2: Optimal
1. We can eliminate reverse operation by inserting at index according to flag value.
1. Fill node value according to flag value.

#CODE:
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    queue<TreeNode*> q;
    q.push(root);
    int flag = 0;
    while(!q.empty()) {
        int n = q.size();
        vector<int> v(n);
        for(int i=0;i<n;++i) {
            TreeNode *node = q.front();
            q.pop();
            int idx = flag ? n-i-1 : i;
            v[idx] = node->val;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        ans.push_back(v);
        flag = (flag +1)%2;
    }
    return ans;
}
=> Time Complexity = O(n)
=> Space Complexity = O(n)