**Note: 
1. It is used to get inorder & preorder in O(n) time & O(1) Space.
2. It uses Threaded Binary Tree concept.


#CODE for Inorder Traversal:

vector<int> getInorder(TreeNode *root) {
  vector<int> inorder;
  TreeNode *curr = root;
  while(curr != NULL) {
    if(curr->left == NULL) {
      inorder.push_back(curr->val);
      curr = curr->right;
    } else {
      // go to left & mark right most node next to curr
      TreeNode *prev = curr->left;
      while(prev->right && prev->right != curr) {
        prev = prev->right;
      }
      if(prev->right == NULL) {
        // Create the thread
        prev->right = curr;
        curr = curr->left;
      } else {
        // Cut the thread
        prev->right = NULL;
        inorder.push_back(curr->val);
        curr = curr->right;
      }
    }
  }
  return inorder;
}
=> Time Complexity = O(n) => Amortized Time Complexity
=> Space Complexity = O(1)

#CODE for Preorder Traversal:

vector<int> getInorder(TreeNode *root) {
  vector<int> inorder;
  TreeNode *curr = root;
  while(curr != NULL) {
    if(curr->left == NULL) {
      inorder.push_back(curr->val);
      curr = curr>right;
    } else {
      // go to left & mark right most nodes next to curr
      TreeNode *prev = cur->left;
      while(prev->right && prev->right != curr) {
        prev = prev->right;
      }
      if(prev->right == NULL) {
        // Create the thread
        prev->right = curr;
        inorder.push_back(curr->val);
        curr = curr->left;
      } else {
        // Cut the thread
        prev->right = NULL;
        curr = curr->right;
      }
    }
  }
  return inorder;
}