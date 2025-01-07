## Bruteforce

1. **`reset` flag**: This flag is used to indicate whether the DFS traversal should start a fresh path from the current node. When `reset` is `true`, the traversal will try to find new paths that sum up to the target, and when `reset` is `false`, it means we're continuing from an existing path (i.e., we're in the middle of exploring the path).

2. **`resets` set**: This set is used to keep track of nodes where a path reset has occurred. The idea is to prevent revisiting the same node for resetting multiple times. If a node is visited again during a DFS traversal when `reset` is `true`, it is skipped because it has already been used as a starting point for a new path (this avoids re-counting the same path multiple times).

   - When `reset` is `true` and the current node is found in the `resets` set, it means we've already reset from that node, so we skip that node to avoid recomputing the same path.
   - If `reset` is `true`, the current node is added to the `resets` set to ensure we don't use it again for another reset during the current DFS traversal.

```c++
class Solution {
public:
    int dfs(TreeNode *node, int target, long sum, bool reset, unordered_set<TreeNode*> &resets) {
        if(!node) return 0;

        if(reset && resets.count(node)) return 0;
        if(reset) resets.insert(node);

        sum += node->val;

        int count = 0;

        if(sum == target) count += 1;
        count += dfs(node->left, target, sum, false, resets);
        count += dfs(node->right, target,  sum, false, resets);
        count += dfs(node->left, target, 0, true, resets);
        count += dfs(node->right, target, 0, true, resets);

        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_set<TreeNode*> resets;
        return dfs(root, targetSum, 0, true, resets);
    }
};
```

### Time complexity:

- For a node at depth d:
- It can be part of paths starting from any of its d ancestors
  Plus one path starting from itself (reset=true case)
  So total visits = d + 1

- Total complexity Calculation :
  Sum over all nodes: Σ(depth of node + 1)
  For a binary tree with n nodes:

- Average depth is O(log n)
- Worst case depth is O(n) for skewed tree

- Therefore:
  Best case (balanced tree): O(n log n)
  Worst case (skewed tree): O(n²)

### Space Complexity:

- O(n) as max recrsion depth n(skewed tree) & set size also O(n)

## Optimization: (Based on prefix sum calculation, similar to array)

Here's the 3-line intuition for Path Sum III using prefix sums:

1. As we traverse down, keep a running sum and store all prefix sums we've seen in a hashmap (with their frequencies).
2. At each node, check if (currentSum - targetSum) exists in our prefix sums map, as this means we can remove that prefix to get a valid path of targetSum.
3. Use backtracking to remove prefix sums when going back up the tree to avoid counting wrong paths.

```c++
class Solution {
public:
    int dfs(TreeNode *node, int target, long sum, unordered_map<long,int>& prefixSums) {
        if(!node) return 0;

        sum += node->val;

        // Check if we can remove any prefix to get target sum
        int count = prefixSums[sum - target];

        // Add current sum to prefix sums
        prefixSums[sum]++;

        // Recurse on children
        count += dfs(node->left, target, sum, prefixSums);
        count += dfs(node->right, target,  sum, prefixSums);

        // Remove current sum before backtracking
        prefixSums[sum]--;
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long, int> prefixSums;
        prefixSums[0] = 1;
        return dfs(root, targetSum, 0, prefixSums);
    }
};
```

Time Complexity: O(N) where N is the number of nodes in the tree.
Let me explain why:

We visit each node exactly once in our DFS traversal
At each node, our operations are:

Updating currentSum: O(1)
Checking/updating the hashmap (prefixSums): O(1) average case since we're using an unordered_map
The backtracking step of removing from map: O(1)

So for N nodes, we do O(1) work N times = O(N) total time complexity. This is much more efficient than the O(N²) approach where we were trying every possible path start point separately.
