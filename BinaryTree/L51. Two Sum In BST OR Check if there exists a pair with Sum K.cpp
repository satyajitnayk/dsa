Approach 1: Using inorder

1. store inorder & use 2 sum of array method.

#CODE:
void f(TreeNode* root, vector<int> &ans) {
    if(root == NULL) return;
    f(root->left,ans);
    ans.push_back(root->val);
    f(root->right,ans);
}
bool findTarget(TreeNode* root, int k) {
    vector<int> A;
    f(root,A);
    unordered_map<int,bool> m;
    for(int i=0;i<A.size();++i) {
        int target = k-A[i];
        if(m.find(target) != m.end()) {
            return true;
        }
        m[A[i]] = true;
     }
    return false;
}
=> Time Complexity = O(N * log N)
=> Space Complexity = O(2 * N)

Approach 2: Using Inorder & left right pointer

#CODE:
void f(TreeNode* root, vector<int> &ans) {
    if(root == NULL) return;
    f(root->left,ans);
    ans.push_back(root->val);
    f(root->right,ans);
}
bool findTarget(TreeNode* root, int k) {
    vector<int> A;
    f(root,A);
    int l=0,r=A.size()-1;
    while(l<r) {
        int sum = A[l]+A[r];
        if(sum > k) r--;
        else if(sum < k) l++;
        else return true;
    }
    return false;
}
=> Time Complexity = O(N)
=> Space Complexity = O(N)

Approach 3: Using Iterator before & after

#CODE:
class BSTIterator {
    stack<TreeNode*> st;
    bool reverse = true;
public:
    void pushAll(TreeNode *node) {
        for(;node != NULL;) {
            st.push(node);
            if(reverse) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
    }
    BSTIterator(TreeNode *root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    int next() {
        TreeNode *tmpNode = st.top();
        st.pop();
        if(reverse) pushAll(tmpNode->left);
        else pushAll(tmpNode->right);
        return tmpNode->val;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;
        // for next
        BSTIterator l(root, false);
        // for before
        BSTIterator r(root, true);
        int i=l.next();
        int j=r.next();
        while(i < j) {
            int sum = i+j;
            if(sum == k) return true;
            else if(sum > k) j = r.next();
            else i = l.next();
        }
        return false;
    }
};

=> Time Complexity = O(N)
=> Space Complexity = O(2*H)