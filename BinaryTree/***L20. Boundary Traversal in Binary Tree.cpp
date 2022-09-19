For this question Anti clock wise Boundaty Traversal.
1. Left boundary excluding the leaves.
2. Leaf nodes. => Inorder 
3. Right boundary in reverse order excluding the leaves.

=> Time Complexity = O(H) for left Boundary+ O(H) for Right Boundary + O(N) for normal traversal = O(N)
=> Space Complexity = O(N)

#CODE:
bool isLeaf(Node *node) {
    if((!node->left) && (!node->right)) return true;
    else return false;
}
void addLeftBoundary(Node *root, vector<int> &ans) {
    Node *cur = root->left;
    while(cur) {
        if(!isLeaf(cur)) ans.push_back(cur->data);
        if(cur->left) cur = cur->left;
        else cur = cur->right;
    }
}
void addLeaves(Node *root, vector<int> &ans) {
    if(isLeaf(root)) {
        ans.push_back(root->data);
        return;
    }
    if(root->left) addLeaves(root->left, ans);
    if(root->right) addLeaves(root->right, ans); 
}
void addRightBoundary(Node *root, vector<int> &ans) {
    Node *cur = root->right;
    vector<int> tmp;
    while(cur) {
        if(!isLeaf(cur)) tmp.push_back(cur->data);
        if(cur->right) cur = cur->right;
        else cur = cur->left;
    } 
    for(int i=tmp.size()-1;i>=0;--i) {
        ans.push_back(tmp[i]);
    }
}
vector <int> boundary(Node *root)
{
    vector<int> ans;
    if(!root) return ans;
    if(!isLeaf(root)) ans.push_back(root->data);
    addLeftBoundary(root, ans);
    addLeaves(root, ans);
    addRightBoundary(root, ans);
    return ans;
}