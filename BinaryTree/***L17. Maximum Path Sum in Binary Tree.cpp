Approach 1: BF

1. Try out all possible node pair & find sum b/w them.
2. Time O(n^3) & Space O(n)

Approach 2: Optimal

1. maxVal(node) => max value
2. Use a variable to keep track of max value so far.
2. For each node = node->val + maxVal(node->left) + maxVal(node->right)
3. Important: Do not consider Negative Path Sum.

#CODE:
int maxVal(TreeNode *node, int &maxi) {
    if(node == NULL) return 0;
    // Ignore negative path sum
    int lv = max(0, maxVal(node->left,maxi));
    int rv =  max(0, maxVal(node->right,maxi));
    maxi = max(maxi, lv+rv+node->val);
    return node->val + max(lv, rv);
}
int maxPathSum(TreeNode* root) { 
    int maxi = INT_MIN;
    maxVal(root, maxi);
    return maxi;
}
=> Time Complexity = O(n)
=> Space Complexity = O(n)