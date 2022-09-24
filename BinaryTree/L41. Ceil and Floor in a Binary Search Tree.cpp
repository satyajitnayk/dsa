##Find Ceil 
Approach:

1. If root val match keep in a variable & break out of loop
2. Else if root val > val => store root in the same variable
3. return the variable

#CODE:
int findCeil(Node* root, int data) {
    if (root == NULL) return -1;
    int ceil = -1;
    while(root) {
        if(root->data == data) {
            ceil = root->data;
            root = root->right;
            break;
        }
        else if(root->data > data) {
            ceil = root->data;
            root = root->left;
        }
        else root = root->right;
    }
    return ceil;
}

##Find Floor

int floorInBST(TreeNode<int> * root, int val) {
    if(!root) return -1;
    int floor = -1;
    while(root) {
        if(root->val == val) {
            floor = root->val;
            break;
        } else if(root->val < val) {
            floor = root->val;
            root = root->right;
        } else root = root->left;
    }
    return floor;
}