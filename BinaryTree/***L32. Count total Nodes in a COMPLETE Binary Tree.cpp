Approach 1: Use some DFS traversal, we will use inorder

#CODE:
void inorder(root) {
  if(!root) return;
  cnt++;
  inorder(rppt->left)
  inorder(rppt->right)
}
=> Time Complexity = O(n)
=> Space Complexity = O(H) => Height of the Binary tree = O(log N)

Approach 2: Use complete BT property

1. Refer to screenshot "**count nodes in complete BT.png"
2. #of nodes in complete BT = 2^h - 1
3. For each node check left height & right height, if they are same means complete BT. 
   Use formula to get #on nodes. 
4. #of nodes in that subtree = 1 + (2^lh-1) + (2^rh-1)

#CODE:
int leftHeight(TreeNode *node) {
    if(!node) return 0;
    int h = 0;
    while(node) {
        h++;
        node = node->left;
    }
    return h;
}
int rightHeight(TreeNode *node) {
    if(!node) return 0;
    int h = 0;
    while(node) {
        h++;
        node = node->right;
    }
    return h;
}
int countNodes(TreeNode* root) {
    if(!root) return 0;
    int lh = leftHeight(root);
    int rh = rightHeight(root);
    if(lh == rh) return (1<<lh)-1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
=> Time Complexity = O(log N* log N) => height is log N
=> Space Complexity = O(H) = O(log N)