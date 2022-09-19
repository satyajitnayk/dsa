Approach: Refer to screenshot
1. Use level order traversal & use coordinate system to keep track of vertical line from 
   left to right & level of the node.

#CODE:
vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    if(!root) return ans;
    map<int,map<int,multiset<int>>> nodes;
    queue<pair<TreeNode*,pair<int,int>>> q;
    q.push({root,{0,0}});
    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        TreeNode *node = p.first;
        int x = p.second.first;
        int y = p.second.second;
        nodes[x][y].insert(node->val);
        if(node->left) {
            q.push({node->left,{x-1,y+1}});
        }
        if(node->right) {
            q.push({node->right,{x+1,y+1}});
        }
    }
    for(auto p: nodes) {
        vector<int> cols;
        for(auto m: p.second) {
            cols.insert(cols.end(), m.second.begin(), m.second.end());
        }
        ans.push_back(cols);
    }
    return ans;
}
=> Time Complexity = O(N * log N) // we are using set
=> Space Complexity = O(N) + O(N)