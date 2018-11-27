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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) return {};
        queue<TreeNode*> q;
        vector<vector<int>> res;
        q.push(root);
        int level_cnt = 1;
        while(!q.empty()) {
            vector<int> c;
            int next_level_cnt = 0;
            for (int i = 0; i < level_cnt; ++i) {
                TreeNode* node = q.front();
                q.pop();
                c.push_back(node->val);
                if(node->left) {
                    q.push(node->left);
                    ++next_level_cnt;
                }
                if(node->right) {
                    q.push(node->right);
                    ++next_level_cnt;
                }
            }
            level_cnt = next_level_cnt;
            res.push_back(c);
        }
        return res;
    }
};
