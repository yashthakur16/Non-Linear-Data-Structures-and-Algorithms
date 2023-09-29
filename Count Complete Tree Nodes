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
    int inordertraversal(TreeNode* root,int &count)
    {
        if(root==NULL)
        {
            return 0;
        }
        inordertraversal(root->left,count);
        count++;
        inordertraversal(root->right,count);

        return count;

    }
    int countNodes(TreeNode* root) 
    {
        int count=0;
        return inordertraversal(root,count);
    }
};
