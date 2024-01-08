// 938. Range Sum of BST

void solve(TreeNode *root, int low, int high, int &sum)
{
    if (root == NULL)
    {
        return;
    }

    if (root->val >= low && root->val <= high)
    {
        sum += root->val;
    }
    solve(root->right, low, high, sum);
    solve(root->left, low, high, sum);
}
int rangeSumBST(TreeNode *root, int low, int high)
{
    int sum = 0;
    solve(root, low, high, sum);
    return sum;
}