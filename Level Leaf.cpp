#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
bool isequal(TreeNode<int> *root,int &level,int n)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->left==NULL && root->right==NULL)
    {
        if(level==0)
        {
            level=n;
            return true;
        }
        else if(level==n)
        {
            return true;
        }
        else
        {
            return false;
        }


    }

    bool left=isequal(root->left,level,n+1);
    bool right=isequal(root->right,level,n+1);

    if(left && right)
    {
        return true;
    }
    else
    {
        return false;
    }
}




int levelLeaf(TreeNode<int> *root) 
{
    int level=0;
    int n=0;
    bool ans=isequal(root,level,n);

    if(ans)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
