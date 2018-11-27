#include <iostream>
#include <vector>
#include <climits>

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
    int minDiffInBST(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
        int min_diff = INT_MAX;
        for (size_t i = 1; i < nums.size(); ++i) {
            min_diff = min(min_diff, nums[i] - nums[i-1]);
        }
        return min_diff;
    }

    void inorder(TreeNode* root, vector<int> &nums) {
        if (!root) return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
};
