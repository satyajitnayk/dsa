Approach: Naive Approach

#CODE:
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL || root == p || root == q) return root;
    TreeNode *leftNode = lowestCommonAncestor(root->left,p,q);
    TreeNode *rightNode = lowestCommonAncestor(root->right,p,q);
    if(leftNode == NULL) return rightNode;
    if(rightNode == NULL) return leftNode;
    return root;
}
=> Time Comlexity = O(N)
=> Space Comlexity = O(H)

Approach 2: Using property of BST
1. Refer to screenshot "LCA in BST.png"

#CODE:
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL || root == p || root == q) return root;
    while(root) {
        if(p->val < root->val && q->val < root->val) {
            root = root->left;
        } else if(p->val > root->val && q->val > root->val) {
            root = root->right;
        } else {
            // point of divergence => this is the LCA
            return root;
        }
    }
    return NULL;
}
=> Time Comlexity = O(H)
=> Space Comlexity = O(1)