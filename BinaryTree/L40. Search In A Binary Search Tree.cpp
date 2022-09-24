Approach 1: Recursive

#CODE:
TreeNode* searchBST(TreeNode* root, int val) {
    if(!root) return NULL;
    if(root->val == val) return root;
    else if(root->val > val) {
        return searchBST(root->left,val);
    } else {
        return searchBST(root->right,val);
    }
}
=> Time Complexity = O(log N)
=> Space Complexity = O(log N)

Approach 2:Iterative Approach

#CODE:
TreeNode* searchBST(TreeNode* root, int val) {
    if(!root) return NULL;
    while(root && root->val != val) {
        root = root->val > val ? root->left : root->right;
    }
    return root;
}