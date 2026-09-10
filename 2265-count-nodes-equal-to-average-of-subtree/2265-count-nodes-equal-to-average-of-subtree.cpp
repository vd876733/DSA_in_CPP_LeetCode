/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int matchingNodes = 0;

    // Returns pair<sum, count> for the subtree rooted at 'node'
    std::pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};

        // Get subtree info from left and right children
        auto left = dfs(node->left);
        auto right = dfs(node->right);

        // Aggregate total sum and count for the current node's subtree
        int currentSum = left.first + right.first + node->val;
        int currentCount = left.second + right.second + 1;

        // Check if the current node's value equals the integer-divided average
        if (currentSum / currentCount == node->val) {
            matchingNodes++;
        }

        return {currentSum, currentCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        matchingNodes = 0;
        dfs(root);
        return matchingNodes;
    }
};