Approach 1: Using property of BST.
1. Iterate over all preorder element & create new node & attch it no its proper position.

=> Time Complexity = O(n^2) => for each node in skew tree need to travers n nodes to attch it.
=> Space Complexity = O(1)

Approach 2: Using inorder & preorder traversal
1. inorder of BST always in sorted order.
2. Use inorder & preorder to built the BST.

=> Time Complexity = O(n)
=> Space Complexity = O(n) => for storing the inorder.

Approach 3: using range technique for each node.

1. Refer to screenshot "BST from preorder.png" for understanding better.
2. When move left take root value as Upper Bound
3. When move right take same Upper Bound.

#CODE:
TreeNode *build(int &i, vector<int> &A, int upperBound) {
    if(i == A.size() || A[i] > upperBound) return NULL;
    TreeNode *root = new TreeNode(A[i]);
    // increase i
    i++;
    root->left = build(i,A,root->val);
    root->right = build(i,A,upperBound);
    return root;
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i = 0;
    return build(i,preorder,INT_MAX);
}

=> Time Complexity = O(3*N)
=> Space Complexity = O(N)