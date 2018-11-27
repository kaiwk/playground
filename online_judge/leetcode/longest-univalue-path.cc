#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        int res = longestOneSide(root->right, root->val) + longestOneSide(root->left, root->val);
        return max(res, max(longestUnivaluePath(root->left), longestUnivaluePath(root->right)));
    }

    int longestOneSide(TreeNode* root, int parent_val) {
        if (!root) return 0;
        int l = (parent_val == root->val) ? 1 + longestOneSide(root->left, parent_val) : 0;
        int r = (parent_val == root->val) ? 1 + longestOneSide(root->right, parent_val) : 0;
        return max(l, r);
    }
};
