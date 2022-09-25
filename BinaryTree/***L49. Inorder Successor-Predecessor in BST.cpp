Q. Inorder Successor:

Approach 1: Using Inorder

1. Store Inorder
2. return next greater node of the target node.

=> Time Complexity = O(N)
=> Space Complexity = O(N)

Approach 2:

1. Just search for next greate node in Inorder Traversal.
2. If not found return NULL or -1.


=> Time Complexity = O(N)
=> Space Complexity = O(1)

Approach 3:

1. Keep track of possible Inorder Successor.
2. If node value is >  target value, store that node value in ans.

#CODE:
int inorderSuccessor(BinaryTreeNode<int>* root, int key) {
    if(root == NULL) return -1;
    int ans = -1;
    while(root) {
        if(root->data > key) {
            ans = root->data;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return ans;
}
int inorderPredecessor(BinaryTreeNode<int>* root, int key) {
    if(root == NULL) return -1;
    int ans = -1;
    while(root) {
        if(root->data < key){
            ans = root->data;
            root = root->right;
        } else {
            root = root->left;
        } 
    }
    return ans;
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key) {
    int inorderS = inorderSuccessor(root,key);
    int inorderP = inorderPredecessor(root,key);
    pair<int,int> ans = {inorderP,inorderS};
    return ans;
}

=> Time Complexity = O(Height)
=> Space Complexity = O(1)