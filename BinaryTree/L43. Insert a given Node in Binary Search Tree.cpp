Approach 1: Find the place of the val & insert it there in the BST:

        5
     2     7
  1    3   


  Insert 6 into BST
          4
       2     7
    1    3  6  

  Insert 4

        5 
     2      7
  1    3
          4


#CODE:

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(!root) return new TreeNode(val);
    TreeNode *prevNode = root, *currNode = root;
    while(currNode) {
        prevNode = currNode;
        if(currNode->val > val) {
            currNode = currNode->left;
        } else {
            currNode = currNode->right;
        }
    }
    if(val < prevNode->val) prevNode->left = new TreeNode(val);
    else prevNode->right = new TreeNode(val);
    return root;
}
=> Time Complexity = O(log N)
=> Space Complexity = O(1)