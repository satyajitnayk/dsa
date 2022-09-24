Approach 1: Using simple recursion

1. Initialize prev with NULL
2. Move to right first then to left
3. Mark node right to prev/top of stack
4. Mark prev left to NULL

#CODE:

TreeNode *prev=NULL;
void flatten(TreeNode* root) {
  if(root == NULL) return;
  flatten(root->right);
  flatten(root->left);
  root->right = prev;
  root->left = NULL;
  prev = root;
}
=> Time & Space Complexity = O(n)

Approach 2: Iterative Approach Using Stack
1. Initialize prev with NULL
2. Move to right first then to left
3. Mark node right to top of stack if stack not empty
4. Mark prev left to NULL

#CODE:
void flatten(TreeNode* root) {
    if(root == NULL) return;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()) {
        TreeNode *curNode = s.top();
        s.pop();
        if(curNode->right) s.push(curNode->right);
        if(curNode->left) s.push(curNode->left);
        if(!s.empty()) curNode->right = s.top();
        curNode->left = NULL;
    }
}
=> Time & Space Complexity = O(n)

Approach 3: Using Moris Traversal => constant space 

1. Refer to screenshot "flatten BT to LL Approach 3.png"

#CODE:
void flatten(TreeNode* root) {
    if(root == NULL) return;
    TreeNode *curNode = root;
    while(curNode) {
        if(curNode->left) {
            TreeNode *prevNode = curNode->left;
            while(prevNode->right) {
                prevNode = prevNode->right;
            }
            prevNode->right = curNode->right;
            curNode->right = curNode->left;
            curNode->left = NULL;
        }
        curNode = curNode->right;
    }
}
=> Time Complexity = O(n)
=> Space Complexity = O(1)