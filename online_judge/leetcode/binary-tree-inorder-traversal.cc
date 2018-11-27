#include <vector>
#include <stack>

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }

    void helper(TreeNode* root, vector<int> &res) {
        if (!root) return;
        helper(root->left, res);
        res.push_back(root->val);
        helper(root->right, res);
    }

    // iterative
    vector<int> inorderTraversal2(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;

        while(root) {
            if (root->left) {
                s.push(root);
                root = root->left;
            } else {
                res.push_back(root->val);
                while(!root->right && !s.empty()) {
                    root = s.top();
                    s.pop();
                    res.push_back(root->val);
                }
                root = root->right;
            }
        }
        return res;
    }
};
