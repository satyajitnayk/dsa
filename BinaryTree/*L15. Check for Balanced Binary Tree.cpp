Balanced BT: For every node Height(left) - Height(ritgh) <= 1

Approach 1: Naive Recursion

#CODE:
int height(TreeNode *node) {
    if(node == NULL) return 0;
    int lH = 0, rH = 0;
    if(node->left) lH = height(node->left);
    if(node->right) rH = height(node->right);
    return 1 + max(lH, rH);
}
bool check(TreeNode *node) {
    if(node == NULL) return true;
    int lH = height(node->left);
    int rH = height(node->right);
    if(abs(lH-rH) > 1) return false;
    bool leftCheck = check(node->left);
    bool rightCheck = check(node->right);
    if(!leftCheck || !rightCheck) return false;
    return true;
}
bool isBalanced(TreeNode* root) {
    return check(root);
}
=> Time Complexity = O(n^2) # O(n) for Traversal & O(n) to find height at each node 
=> Space Complexity = O(n)

Approach 2: Optimized Approach

-> If Tree is Balanced then return height of the tree, else return -1.

#CODE:
int height(TreeNode *node) {
    if(node == NULL) return 0;
    int lH = 0, rH = 0;
    if(node->left) lH = height(node->left);
    if(lH == -1)
    if(node->right) rH = height(node->right);
    if(rH == -1) return -1;
    if(abs(lH-rH) > 1) return -1;
    return 1 + max(lH, rH);
}
bool isBalanced(TreeNode* root) {
    return height(root) != -1;
}
=> Time Complexity = O(n)
=> Space Complexity = O(n)