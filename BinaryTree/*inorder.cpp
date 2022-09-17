Approach 1: Recursive 

preOrder(node) {
  if(node == null) return;
  preOrder(node->left)
  print(node->data)
  preOrder(node->right)
}

Approach 2: Iterative

#CODE:
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(root == NULL) return ans;
    stack<TreeNode*> s;
    TreeNode *node = root;
    while(true) {
        if(node) {
            s.push(node);
            node = node->left;
        } else {
            if(s.empty()) break;
            node = s.top();
            s.pop();
            ans.push_back(node->val);
            node = node->right;
        }
    }
    return ans;
}
=> Time Complexity = O(n)
=> Space Complexity = O(H) => height of BT.