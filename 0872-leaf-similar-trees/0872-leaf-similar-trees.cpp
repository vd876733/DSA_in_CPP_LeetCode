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
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr || root2 == nullptr) return false;
        vector<int> m,n;
        Tree(root1,m);
        Tree(root2,n);
        if(m.size()-n.size() != 0) return false;
        for(int i = 0; i < min(m.size(),n.size()); i++){
            if(m[i] != n[i]) return false;
        }
        return true;
    }
    void Tree(TreeNode *root, vector<int> &v){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr){
            v.push_back(root->val);
            return;
        }
        Tree(root->left,v);
        Tree(root->right,v); 
    }
};