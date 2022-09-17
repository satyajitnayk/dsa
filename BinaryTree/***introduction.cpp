#Types Of BT?
  1. Full BT: Every node has 0 or 2 children.
  2. Complete BT: 
    a. All level except las are filled.
    b. The last level has all nodes in left.
  3. Perfect BT: All leaf nodes at same level.
  4. Balanced BT: Height of tree at max log N. (N = #of nodes)
  5. Degenerate BT: Left Or Right Skewed
      a 
        \
         b
          \
           c

#Representation Of BT in C++:

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
  Node(int val) {
    data = val;
    left = right = NULL;
  }
}

main() {
  struct Node *root = new Node(4);
  root->left = new Node(3);
  root->right = new Node(5);
}

# BT Traversal Technique(BFS/LEVEL Order Traversal & DFS): 
 - Types of DFS Traversal:
    a. Inorder (Left + Root + Right)
    b. Preorder (Root + Left + Right)
    a. Postorder (Left + Right + Root )


