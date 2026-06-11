/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class NodeValue {
public:
    int minVal;
    int maxVal;
    int sum;
    NodeValue(int minVal, int maxVal, int sum) {
        this->minVal = minVal;
        this->maxVal = maxVal;
        this->sum = sum;
    }
};

class Solution {
public:
    int maxsum = 0;

    NodeValue solve(TreeNode* root) {
        if (!root)
            return NodeValue(INT_MAX, INT_MIN, 0);
        auto left = solve(root->left);
        auto right = solve(root->right);
        if (left.maxVal < root->val && root->val < right.minVal) {
            int currsum = left.sum + right.sum + root->val;
            maxsum = max(maxsum, currsum);
            return NodeValue(min(root->val, left.minVal),
                             max(root->val, right.maxVal), currsum);
        }
        return NodeValue(INT_MIN, INT_MAX, 0);
    }

    int maxSumBST(TreeNode* root) {
        solve(root);
        return maxsum;
    }
};