Approach 1: Using inorder traversal
1. Store inorder (already inorder of BST sorted)& return kth number.

#CODE:
void f(TreeNode *root, vector<int> &inorder) {
    if(root == NULL) return;
    f(root->left,inorder);
    inorder.push_back(root->val);
    f(root->right,inorder);
}
int kthSmallest(TreeNode* root, int k) {
    vector<int> inorder;
    f(root, inorder);
    return inorder[k-1];
}
=> Time Complexity = O(N)
=> Space Complexity = O(N)

Approach 2: Using inorder, w.t.o. storing inorder 
1. While doing inorder traversal keep track of count var

#CODE:
void f(TreeNode *root, int &k, int &ans) {
    if(root == NULL) return;
    f(root->left,k,ans);
    k--; if(k==0) ans = root->val;
    f(root->right,k,ans);
}
int kthSmallest(TreeNode* root, int k) {
    int ans = 0;
    f(root,k,ans);
    return ans;
}
=> Time Complexity = O(N)
=> Space Complexity = O(min(K,N))