Approach 1: Use root to node path for both nodes.

1. store root to node path for both nodes.
2. Traverse from start for both paths, the last matched node is Lowest Common Ancestor.

#CODE:
bool rootToNodePath(TreeNode *root, TreeNode *node, vector<TreeNode*> &ans) {
    if(!root) return false;
    ans.push_back(root);
    if(root->val == node->val) return true;
    if(rootToNodePath(root->left,node,ans) || rootToNodePath(root->right,node,ans)) {
        return true;
    }
    ans.pop_back();
    return false;   
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode *cur = root;
    vector<TreeNode*> path1;
    vector<TreeNode*> path2;
    rootToNodePath(root,p,path1);
    rootToNodePath(root,q,path2);
    int n = path1.size();
    int m = path2.size();
    int i;
    for(i=0;i<min(n,m);++i) {
        if(path1[i] != path2[i]) {
            break;
        }
    }
    return path1[i-1];
}
=> Time Complexity = O(3*n)
=> Space Complexity = O(2*n)

Approach 2: Please refer to Screenshot attached

#CODE:
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL || root == p || root == q) return root;
    TreeNode *left = lowestCommonAncestor(root->left,p,q);
    TreeNode *right = lowestCommonAncestor(root->right,p,q);
    if(left == NULL) return right;
    else if(right == NULL) return left;
    else {
        // both not null => we found LCA node
        return root;
    }
}
=> Time Complexity = O(n)
=> Space Complexity = O(n)