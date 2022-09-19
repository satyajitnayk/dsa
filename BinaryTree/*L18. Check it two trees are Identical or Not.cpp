Approach 1: (Any DFS traversal will be same for both tree if they are identical)
1. For each node int both trees check if the node values are same or not
2. If not then return false
3. check for left & right subtree of both trees.

#CODE:
bool check(TreeNode* p, TreeNode* q) {
    if(p == NULL && q == NULL) return true;
    if(p == NULL || q == NULL) return false; 
    return (p->val != q->val) & check(p->left,q->left) & check(p->right,q->right);
}
bool isSameTree(TreeNode* p, TreeNode* q) {
    return check(p,q);
}
=> Time Complexity = O(n)
=> Space Complexity = O(n)