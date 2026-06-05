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
    TreeNode* markparent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent,int target){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res=NULL;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->val==target){
                res=node;
            }
            if(node->left){
                parent[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right]=node;
                q.push(node->right);
            }
        }
        return res;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parent;
        TreeNode* target=markparent(root,parent,start);
        unordered_map<TreeNode*,bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target]=true;
        int time=0;
        while(!q.empty()){
            int size=q.size();
            bool burned=false;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    burned=true;
                    vis[node->left]=true;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]){
                    burned=true;
                    vis[node->right]=true;
                    q.push(node->right);
                }
                if(parent[node] && !vis[parent[node]]){
                    burned=true;
                    vis[parent[node]]=true;
                    q.push(parent[node]);
                }
            }
            if(burned){
                time+=1;
            }
        }
        return time;
    }
};