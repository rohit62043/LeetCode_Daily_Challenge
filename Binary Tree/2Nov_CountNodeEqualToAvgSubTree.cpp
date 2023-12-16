// 2265. Count Nodes Equal to Average of Subtree
class Solution {
public:
    pair<int,int> solve(TreeNode*root,int& ans){
        if(root==NULL){
            return {0,0};
        }

        auto leftVal=solve(root->left,ans);
        auto rightVal=solve(root->right,ans);

        int current_sum=root->val+leftVal.first+rightVal.first;
        int current_count=1+leftVal.second+rightVal.second;

        if(current_sum/current_count==root->val){
            ans++;
        }

        return {current_sum,current_count};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        solve(root,ans);

        return ans;
    }
};

//Similar Problem
// 1080. Insufficient Nodes in Root to Leaf Paths
class Solution {
public:
    bool solve(TreeNode*root,int limit,int&sum){
        if(root->left==NULL && root->right==NULL){
            sum=sum+root->val;
            if(sum>=limit){
                 sum=sum-root->val;
                return true;
            }
             sum=sum-root->val;

            return false;
        }
        sum=sum+root->val;
        bool leftAns=true;
        if(root->left!=NULL){
            leftAns=solve(root->left,limit,sum);
        }
        bool rightAns=true;
        if(root->right!=NULL){
            rightAns=solve(root->right,limit,sum);
        }
        sum=sum-root->val;
        if(leftAns==false && rightAns==false){
            return false;
        }
        if(leftAns==false && rightAns==true){
            if(root->right!=NULL){
                root->left=NULL;
                return true;
            }
            return false;
        }
        if(leftAns==true && rightAns==false){
            if(root->left!=NULL){
                 root->right=NULL;
                return true;
            }
            return false;
        }

        return true;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
       int sum=0;
       bool ans= solve(root,limit,sum);
       if(ans==false){
           root=NULL;
       }
        return root;
    }
};