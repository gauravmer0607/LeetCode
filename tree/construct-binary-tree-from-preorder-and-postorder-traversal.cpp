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
    unordered_map<int,int> mp;
    int preindex=0;

    TreeNode* build(vector<int>& preorder,int start,int end){
        if(start>end){
            return NULL;
        }
        int rootval=preorder[preindex++];
        TreeNode* root=new TreeNode(rootval);
        if(start==end){
            return root;
        }
        int leftroot=preorder[preindex];
        int pos=mp[leftroot];
        root->left=build(preorder,start,pos);
        root->right=build(preorder,pos+1,end-1);
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(int i=0;i<postorder.size();i++){
            mp[postorder[i]]=i;
        }    
        return build(preorder,0,postorder.size()-1);
    }
};