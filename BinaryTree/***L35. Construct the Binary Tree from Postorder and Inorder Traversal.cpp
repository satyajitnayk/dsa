Approach:

#CODE:

TreeNode *f(int is,int ie,int ps,int pe,vector<int>& inorder, vector<int>& postorder,map<int,int> &m) {
        if(is>ie || ps>pe) return NULL;
        TreeNode *root = new TreeNode(postorder[pe]);

        int idx = m[root->val];
        int leftNums = idx-is;
        root->left = f(is,idx-1,ps,ps+leftNums-1,inorder,postorder,m);
        root->right = f(idx+1,ie,ps+leftNums,pe-1,inorder,postorder,m);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        map<int,int> m;
        for(int i=0;i<n;++i) m[inorder[i]] = i;
        TreeNode *root = f(0,n-1,0,n-1,inorder,postorder,m);
        return root;
    }
