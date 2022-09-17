Approach 1: Recursive

#CODE:
void f(TreeNode *node, vector<int> &ans) {
    if(node == NULL) return;
    if(node->left) f(node->left, ans);
    if(node->right) f(node->right,ans);
    ans.push_back(node->val);
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(root == NULL) return ans;
    f(root, ans);
    return ans;
}
=> Time = O(n)
=> Space = O(H)

Approach 2: Iterative Approach using 2 stacks

#CODE:
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(root == NULL) return ans;
    stack<TreeNode*> s1, s2;
    s1.push(root);
    while(!s1.empty()) {
        TreeNode *node = s1.top();
        s1.pop();
        s2.push(node);
        if(node->left) s1.push(node->left); 
        if(node->right) s1.push(node->right);
    }
    while(!s2.empty()) {
        TreeNode *node = s2.top();
        s2.pop();
        ans.push_back(node->val);
    }
    return ans;
}
=> Time = O(n)
=> Space = O(2*N)

Approach 3: Iterative Approach using 1 stack

#CODE:
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(root == NULL) return ans;
    stack<TreeNode*> s;
    TreeNode *cur = root, *tmp=NULL;
    while(cur != NULL || !s.empty()) {
        if(cur) {
            s.push(cur);
            cur = cur->left;
        } else {
            tmp = s.top()->right;
            if(tmp == NULL) {
                tmp = s.top();
                s.pop();
                ans.push_back(tmp->val);
                while(!s.empty() && tmp == s.top()->right) {
                    tmp = s.top();
                    s.pop();
                    ans.push_back(tmp->val);
                }
            } else {
                cur = tmp;
            }
        }
    }
    return ans;
}
=> Time Complexity = O(2*n) => Reason we push all elements once & then poped all so 2*n
=> Space Complexity = O(n)