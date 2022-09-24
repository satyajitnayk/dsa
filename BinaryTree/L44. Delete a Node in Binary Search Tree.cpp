Approach:

1. Find the node.
2. Delete it by following the below steps:
  a. Attach node->left to node->left->left
  b. Attach right of node i.e. node->right to right most child of left subtree of node.

#CODE:
TreeNode *helper(TreeNode *root) {
    if(root->left == NULL) return root->right;
    else if(root->right == NULL) return root->left;
    else {
        // take rightChild node of root & attach it to 
        // the right of left most node of root
        TreeNode *rightChild = root->right;
        TreeNode *lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        // return roots left node
        return root->left;
    }
}
TreeNode *findLastRight(TreeNode *root) {
    while(root->right) {
        root = root->right;
    }
    return root;
}
TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root) return NULL;
    if(root->val == key) return helper(root) ;
    TreeNode *dummy = root;
    while(root) {
        if(root->val > key) {
            if(root->left && root->left->val == key) {
                root->left = helper(root->left);
                break;
            } else {
                root = root->left;
            }
        } else {
            if(root->right && root->right->val == key) {
                root->right = helper(root->right);
                break;
            } else {
                root = root->right;
            }
        }
    }
    return dummy;
}
=> Time Complexity = O(H)
=> Space Complexity = O(1)