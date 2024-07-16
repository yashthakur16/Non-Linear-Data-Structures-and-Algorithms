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
    
    void finds(TreeNode* root, int q,string &ans, string &final1)
    {
         if(root==NULL)
        {
            return;
        }
       
        
        if(root->val==q)
        {
            final1=ans;
            return ;
        }
        
        ans.push_back('U');
        finds(root->left,q,ans,final1);
        ans.pop_back();
        
        ans.push_back('U');
        finds(root->right,q,ans,final1);
        ans.pop_back();
        
        return ;
    }
    
    
    void traverse(TreeNode* root, int q,string &ans, string &final1)
    {
        if(root==NULL)
        {
            return;
        }
        
        if(root->val==q)
        {
            final1=ans;
            
            return ;
        }
        
        ans.push_back('L');
        traverse(root->left,q,ans,final1);
        ans.pop_back();
        
        ans.push_back('R');
        traverse(root->right,q,ans,final1);
        ans.pop_back();
        
        return ;
        
    }
    
    
     TreeNode* solve(TreeNode* root, int p, int q)
    {
        if(root==NULL)
        {
            return NULL;
        }
        if(root->val==p||root->val==q)
        {
            return root;
        }
        
        TreeNode* leftAns=solve(root->left,p,q);
        TreeNode* rightAns=solve(root->right,p,q);
        
        if(leftAns==NULL && rightAns==NULL)
        {
            return NULL;
        }
        else if(leftAns==NULL && rightAns!=NULL)
        {
            return rightAns;
        }
        else if(leftAns!=NULL && rightAns==NULL)
        {
            return leftAns;
        }
        else
        {
            return root;
        }
        
        return NULL;
    }
    
    
    string getDirections(TreeNode* root, int startValue, int destValue) 
    {
        TreeNode* lca=solve(root,startValue,destValue);
        
        string ans="";
        string final1="";
        

        
      
      
            finds(lca,startValue,ans,final1);

    
       
        
        string dir=final1;
        ans="";
        final1="";
        
         traverse(lca,destValue,ans,final1);
        
        dir.append(final1);
        
        
        return dir;
        
    }
};
