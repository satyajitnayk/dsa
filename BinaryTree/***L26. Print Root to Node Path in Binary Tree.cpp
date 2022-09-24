Approach:

1. Search the path from root to node in all direction.
2. Keep track of nodes u travel while doing inorder traversal.

#CODE:
bool getPath(TreeNode *cur, int x, vector<int> &ans) {
    if(!cur) return false;
    ans.push_back(cur->val);
    if(cur->val == x) return true;
    
    if(getPath(cur->left,x,ans) || getPath(cur->right,x,ans)) return true;
    ans.pop_back();
    return false;
}
vector<int> solve(TreeNode* root, int x) {
    vector<int> ans;
    if(!root) return ans;
    getPath(root, x, ans);
    return ans;
}
=> Time & Space Complexity = O(n)