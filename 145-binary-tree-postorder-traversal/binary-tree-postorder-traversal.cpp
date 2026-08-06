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

    void solve(TreeNode* curr, vector<int>& result)
    {
        if(curr==NULL)
        {
            return;
        }
        solve(curr->left,result);
        solve(curr->right,result);
        result.push_back(curr->val);
    }


    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr=root;

        solve(curr,result);
        return result;
    }
};