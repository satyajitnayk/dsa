Approach: 
1. Use level order traversal with map to keep track of val at each line
2. As going through level order traversal always replace value for each line number.

#CODE:
vector<int> bottomView(Node *root) {
    vector<int> ans;
    if(!root) return ans;
    queue<pair<Node*,int>> q;
    map<int, int> m;
    q.push({root, 0});
    while(!q.empty()) {
        int n = q.size();
        for(int i=0;i<n;++i) {
            auto p = q.front();
            q.pop();
            Node *cur = p.first;
            int line = p.second;
            m[line] = cur->data;
            if(cur->left) q.push({cur->left, line-1});
            if(cur->right) q.push({cur->right, line+1});
        } 
    }
    for(auto x: m) {
        ans.push_back(x.second);
    }
    return ans;
}
=> Time Complexity = O(n)
=> Space Complexity = O(n)

** Note: Can we use Recursion to solve this problem ?
Ans: 1. No, i.e. If we use Inorder then we will not get bottom node for each line.
     & it defeats what the question have asked.
     2. Else we have to induce some extra logic.