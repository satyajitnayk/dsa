Approach:
1. For first pass root->left, root->right 
2. Then check for node value of each node
3. For left pass (left, right) & for right pass(right, left) => Mirror Image checking

#CODE:
bool isSymmetricHelper(TreeNode *left, TreeNode *right) {
    if(!left || !right) return left == right;
    if(left->val != right->val) return false;
    return isSymmetricHelper(left->left,right->right)
           && isSymmetricHelper(left->right, right->left);
}
bool isSymmetric(TreeNode* root) {
    return !root || isSymmetricHelper(root->left, root->right);
}
=> Time Complexity = O(n)
=> Space Complexity = O(n)