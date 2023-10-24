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
    vector<int> largestValues(TreeNode* root) 
    {
        if(root==NULL)
        {
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> ans;
        int sum=root->val;
        ans.push_back(sum);
        sum=INT_MIN;

        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp==NULL)
            {
                ans.push_back(sum);
                sum=INT_MIN;
                if(!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                if(temp->left)
                {
                    q.push(temp->left);
                    sum=max(sum,temp->left->val);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                    sum=max(sum,temp->right->val);
                }
            }
        }
        ans.pop_back();

        return ans;
    }
};
