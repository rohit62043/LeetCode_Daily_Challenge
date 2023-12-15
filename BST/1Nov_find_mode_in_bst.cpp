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

    void f(TreeNode* root){
        if(root==NULL){
            return;
        }
        mp[root->val]++;
        if(root->left!=NULL){
            f(root->left);
        }
        if(root->right!=NULL){
            f(root->right);
        }
    }


    vector<int> findMode(TreeNode* root) {
      vector<int> ans;
      f(root);

      int maxi=INT_MIN;

      for(auto x:mp){
          maxi=max(maxi,x.second);
      }

      for(auto x:mp){
          if(x.second==maxi){
              ans.push_back(x.first);
          }
      }
     
     return ans;
    }
};