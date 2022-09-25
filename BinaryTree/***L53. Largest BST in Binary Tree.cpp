Approach 1: Brute Force

1. For each node check if its a valid BST.
=> Time Complexity = O(N^2)

Approach 2: Efficient Approach

1. Refer to screenshot "Largest BST in Binary Tree.png"
2. Since we need to calulate for left node & right node & finally root 
   => We can use POST ORDER Traversal.

#CODE:

class NodeValue {
public:
  int maxNode, minNode, maxSize;

  NodeValue(int minNode, int maxNode, int maxSize) {
    this->maxNode = maxNode;
    this->minNode = minNode;
    this->maxSize = maxSize;
  }
};
NodeValue f(TreeNode<int>* root) {
    // An empty tree is a BST of size 0
    if(root == NULL)  {
        return NodeValue(INT_MAX, INT_MIN, 0);
    }
    // Get values from left & right subtree of current tree
    auto left = f(root->left);
    auto right = f(root->right);
    
    // if minNode < curNode < maxNode then its a valid BST
    if(left.maxNode < root->data && root->data < right.minNode) {
        return NodeValue(min(root->data, left.minNode), max(root->data,right.maxNode), 1+left.maxSize+right.maxSize);
    }
    // Otherwise return [-INF, INF] so that parent can't be valid BST
    return NodeValue(INT_MIN, INT_MAX,max(left.maxSize,right.maxSize));
}
int largestBST(TreeNode<int>* root) {
    return f(root).maxSize;
}

=> Time Complexity = O(N)
=> Space Complexity =O(1)
