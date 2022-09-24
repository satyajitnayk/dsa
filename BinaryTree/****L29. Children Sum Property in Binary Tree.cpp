Approach :

1. While going down increase the nodes value as much as possible.
2. While coming back add left & right node value to parent node value.

#CODE:
void changeTree(BinaryTreeNode < int > * root) {
    if(!root) return;
    int child = 0;
    if(root->left) child += root->left->data;
    if(root->right) child += root->right->data;
    if(child >= root->data) root->data = child;
    else {
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    }
    // got to left & right of root
    changeTree(root->left);
    changeTree(root->right);
    
    // while coming back add children values to root value
    int tot = 0;
    if(root->left) tot += root->left->data;
    if(root->right) tot += root->right->data;
    // to avoid updating leaf node
    if(root->left || root->right) root->data = tot;
} 
=> Time Comlpexity = O(n)
=> Space Comlpexity = O(Height) = O(n) -> For Skewed Tree