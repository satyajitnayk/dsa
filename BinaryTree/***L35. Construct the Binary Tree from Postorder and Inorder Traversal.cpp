Approach:

#CODE:
TreeNode* constructTree(vector<int> &postorder, int postStart, int postEnd,
	  vector<int> &inorder, int inStart, int inEnd, map<int, int> &mp) {
      
    if (postStart > postEnd || inStart > inEnd) return NULL;
    TreeNode *root = new TreeNode(postorder[postEnd]);
    int idx = mp[root->val];
    int numsLeft = idx - inStart;
    root->left = constructTree(postorder, postStart, postStart + numsLeft - 1,
        inorder, inStart, idx - 1, mp);
    root->right = constructTree(postorder, postStart + numsLeft, postEnd-1, inorder,
        idx + 1, inEnd, mp);
    return root;
}
TreeNode* buildTree(vector<int> &postorder, vector<int> &inorder) {
    int postStart = 0, postEnd = postorder.size() - 1;
    int inStart = 0, inEnd = inorder.size() - 1;
    map<int, int> mp;
    for (int i = inStart; i <= inEnd; i++) {
        mp[inorder[i]] = i;
    }
    return constructTree(postorder, postStart, postEnd, inorder, inStart, inEnd, mp);
}