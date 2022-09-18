Approach: Iterative Approach
1 for preorder
2 for inorder
3 for postorder

#CODE:

void printAllOrders(TreeNode *root) {
    vector<int> preorder, inorder, postorder;
    if(root == NULL) return preorder;
    stack<pair<TreeNode*,int>> s;
    s.push({root,1}); 
    while(!s.empty()) {
      auto it = s.top();
      s.pop();
      if(it.second == 1) {
        preorder.push_back(it.first->val);
        it.second++;
        s.push(it);
        if(it.first->left) {
          s.push({it.first->left,1});
        }
      } else if(it.second == 2) {
        inorder.push_back(it.first->val);
        it.second++;
          s.push(it);
        if(it.first->right) {
          s.push({it.first->right,1});
        }
      } else if(it.second == 3) {
        postorder.push_back(it.first->val);
      }
    }
}
