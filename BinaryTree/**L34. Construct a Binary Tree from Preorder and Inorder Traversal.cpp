Approach 1: Recursion

#CODE:
TreeNode* f(int preStart,int preEnd,int inStart,int inEnd,
            vector<int>& preorder, vector<int>& inorder,
            unordered_map<int,int> &indexes) {
    // as long as i have element create tree
    if(inStart > inEnd || preStart > preEnd) return NULL;
    
    TreeNode *root = new TreeNode(preorder[preStart]);
    
    int idx = indexes[root->val];
    int numsLeft = idx-inStart;
    
    root->left = f(preStart+1,preStart+numsLeft,inStart,idx-1,preorder,inorder,indexes);
    root->right = f(preStart+numsLeft+1,preEnd,idx+1,preEnd,preorder,inorder,indexes);
    
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int,int> indexes;
    int n = preorder.size();
    for(int i=0;i<n;++i) {
        indexes[inorder[i]] = i;
    }
    TreeNode *root = f(0,n-1,0,n-1,preorder,inorder,indexes);
    return root;
}
=> Time Complexity = O(n*log n)
=> Space Complexity = O(n) + O(n)