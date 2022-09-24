Approach 1: Using inorder

1. store inorder 
2. if inorder sorted then its BSt else not.

#CODE:
void f(TreeNode *root, vector<int> &inorder) {
    if(root == NULL) return;
    f(root->left,inorder);
    inorder.push_back(root->val);
    f(root->right,inorder);
}
bool isValidBST(TreeNode* root) {
    vector<int> inorder;
    f(root, inorder);
    for(int i=0;i<inorder.size()-1;++i) {
        if(inorder[i] >= inorder[i+1]) return false;
    }
    return true;
}
=> Time Complexity = O(N)
=> Space Complexity = O(2*N) => N for recursion & N for storinf inorder.

Approach 2: Using allowed range for each node while traversing.

#CODE:
bool f(TreeNode *root, long long minVal, long long maxVal) {
    if(root == NULL) return true;
    long long rootVal = root->val;
    if(rootVal >= maxVal || rootVal <= minVal) return false;
    return f(root->left,minVal,rootVal) && f(root->right,rootVal,maxVal);
}
bool isValidBST(TreeNode* root) {
    if(!root->left && !root->right) return true;
    return f(root,LLONG_MIN, LLONG_MAX);
}
**NOTE: USE LLONG_MAX & LLONG_MIN (long long max and min dur to constrained in question).
=> Time Complexity = O(N)
=> Space Complexity = O(1)
