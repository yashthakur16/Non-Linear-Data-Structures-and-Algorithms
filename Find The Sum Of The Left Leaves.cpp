#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int solve(TreeNode<int> *root,bool l)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL && root->right==NULL && l==1)
    {
        return root->val;
    }
    int ans;
    ans=solve(root->left,1)+solve(root->right,0);

    return ans;

    
}

int sumOfLeftLeaves(TreeNode<int> *root)
{
    int ans=solve(root,0);
    return ans;
}
