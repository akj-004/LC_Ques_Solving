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

    int helper (TreeNode* node ,int ans , int nodeVal){
        if (node==NULL){
            return ans;
        }

        ans = max(ans, nodeVal);

        int left = helper (node->left , ans , nodeVal+1);
        int right = helper (node->right , ans , nodeVal+1);

        return max(left,right);
    }

    int maxDepth(TreeNode* root) {
        int ans = helper(root,0 ,1);
        return ans;
    }
};