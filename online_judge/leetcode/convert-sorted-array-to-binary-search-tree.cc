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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return NULL;
        TreeNode *head = helper(nums, 0, nums.size()-1);
        return head;
    }

    TreeNode* helper(vector<int> &nums, int low, int high) {
        while (low <= high) {
            int mid = (low + high) / 2;
            TreeNode *root = new TreeNode(nums[mid]);
            root->right = helper(nums, mid+1, high);
            root->left = helper(nums, low, mid-1);
            return root;
        }
        return NULL;
    }
};
