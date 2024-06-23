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

int solve(TreeNode<int> * root, int X,int &ans)
{
    if(root==NULL)
    {
        return ans;
    }

    if(root->val==X)
    {
        return ans=X;
    }


    if(root->val<X&&root->val>ans)
    {
        ans=root->val;
    }

    solve(root->left,X,ans);
    solve(root->right,X,ans);

    return ans;
}


int floorInBST(TreeNode<int> * root, int X)
{
    int ans=-1;
   return solve(root,X,ans);
}
