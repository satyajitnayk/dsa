Approach 1: Using Correct Inorder

1. store correct inorder & correct the node value in next inorder traversal of the BST.

#CODE:
void f(TreeNode *root, vector<int> &A) {
    if(root == NULL) return;
    f(root->left,A);
    A.push_back(root->val);
    f(root->right,A);
}
void recover(TreeNode *root, int &i, vector<int> &A) {
    if(root == NULL) return;
    recover(root->left,i,A);
    root->val = A[i];
    i++;
    recover(root->right,i,A);
}
void recoverTree(TreeNode* root) {
    vector<int> A;
    f(root, A);
    sort(A.begin(), A.end());
    int i=0;
    recover(root,i,A);
}
=> Time Compexity = O(N * log N) // for sorting
=> Space Compexity = O(N)

Approach 2: Using Inorder, just storing violating nodes.

Two cases arises:
  1. violating nodes are adjacent in inorder. => swap them.
  2. violating nodes are not adjacent in inorder. => swap first with third violating node.