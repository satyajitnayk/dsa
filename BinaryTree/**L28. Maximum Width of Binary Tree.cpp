Approach : 
1. Refere to screen shots Max Width BT_1 & BT_2 For understanding the underlying concept.
2. We can either use o based or 1 based numbering.
#CODE:
int widthOfBinaryTree(TreeNode* root) {
    if(!root) return 0;
    queue<pair<TreeNode*,int>> q;
    q.push({root,1});
    int ans = 0;
    while(!q.empty()) {
        int n = q.size();
        int mmin = q.front().second;
        int x1=0,x2=0;
        for(int i=0;i<n;++i) {
            auto p = q.front();
            q.pop();
            TreeNode *cur = p.first;
            int x = p.second-mmin+1;
            cout << x << " ";
            if(i==0) x1=x;
            if(i == n-1) x2=x;
            if(cur->left) q.push({cur->left,(long long)2*x});
            if(cur->right) q.push({cur->right,(long long)2*x+1});
        }
        ans = max(ans, x2-x1+1);
    }
    return ans;
}
=> Time Complexity = O(n)
=> Space Complexity = O(n)