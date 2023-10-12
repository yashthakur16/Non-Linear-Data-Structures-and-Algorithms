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

    int totalcount(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int ans=totalcount(root->left)+totalcount(root->right)+1;
        return ans;
    }

    bool isCBT(TreeNode* root,int index,int count)
    {
        if(root==NULL)
        {
            return true;
        }
        if(index>=count)
        {
            return false;
        }

        bool left=isCBT(root->left,index*2+1,count);
        bool right=isCBT(root->right,index*2+2,count);

        if(left && right)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isCompleteTree(TreeNode* root) 
    {
        int index=0;
        int count=totalcount(root);
        return isCBT(root,index,count);
    }
};
