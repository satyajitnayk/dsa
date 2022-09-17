Approach 1: Recursion
void f(TreeNode *node,vector<int> &ans) {
    if(node == NULL) return;
    ans.push_back(node->val);
    if(node->left) f(node->left, ans);
    if(node->right) f(node->right, ans);
}
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    f(root, ans);
    return ans;
}

Approach 2: Iterative using stack.

#CODE:
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(root == NULL) return ans;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()) {
        TreeNode *node = s.top();
        s.pop();
        ans.push_back(node->val);
        // push right first as in stack left will be pop first
        if(node->right) s.push(node->right);
        if(node->left) s.push(node->left);
    }
    return ans;
}