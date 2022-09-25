Approach: Using Iterative Inorder Traversal

#CODE:
stack<TreeNode*> s;
BSTIterator(TreeNode* root) {
    pushAllInLeft(root);
}

int next() {
    TreeNode *tmpNode = s.top();
    s.pop();
    pushAllInLeft(tmpNode->right);
    return tmpNode->val;
}

bool hasNext() {
    return !s.empty();
}
void pushAllInLeft(TreeNode *node) {
    for(; node != NULL; s.push(node), node=node->left);
}

=> Time Complexity = O(H)
=> Space Complexity = O(1)