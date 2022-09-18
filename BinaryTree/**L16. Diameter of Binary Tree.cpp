1. The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
2. The length of a path between two nodes is represented by the number of edges between them.

Approach 1: Naive Approach
1. For each node find path pass through that node => lh + rh

#CODE:
int height(TreeNode *node) {
    if(node == NULL) return 0;
    int lH = 0, rH = 0;
    if(node->left) lH = height(node->left);
    if(node->right) rH = height(node->right);
    return 1 + max(lH, rH);
}
void check(TreeNode *node, int &h) {
    if(node == NULL) return;
    int lh = height(node->left);
    int rh = height(node->right);
    h = max(h, lh+rh);
    check(node->left,h);
    check(node->right,h);
}
int diameterOfBinaryTree(TreeNode* root) {
    int dia = 0;
    check(root, dia);
    return dia;
}
=> Time Complexity = O(n^2) => n for traversal & n for finding height at each node
=> Space Complexity = O(n)

Approach 2: Optimal
1. Use a variable to keep track of max path length while finding height.

#CODE:
int height(TreeNode *node, int &maxi) {
    if(node == NULL) return 0;
    int lh = 0, rh = 0;
    if(node->left) lh = height(node->left,maxi);
    if(node->right) rh = height(node->right,maxi);
    maxi = max(maxi, lh+rh);
    return 1 + max(lh, rh);
}
int diameterOfBinaryTree(TreeNode* root) {
    int dia = 0;
    height(root, dia);
    return dia;
}
=> Time Complexity = O(n)
=> Space Complexity = O(n)