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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) 
    {
        unordered_map <int,TreeNode*> mpp;
        unordered_map <int,bool> hasParent;
        
        for(auto desc : descriptions)
        {
            int parent=desc[0];
            int child=desc[1];
            bool isleft=desc[2];
            TreeNode* parentNode=nullptr;
            TreeNode* childNode=nullptr;
            
            if(mpp.find(parent)!=mpp.end())
            {
                parentNode=mpp[parent];
            }
            else
            {
                parentNode= new TreeNode(parent);
            }
            
            
             if(mpp.find(child)!=mpp.end())
            {
                childNode=mpp[child];
            }
            else
            {
                childNode= new TreeNode(child);
            }
            
            if(isleft)
            {
                parentNode->left=childNode;
            }
            else
            {
                parentNode->right=childNode;
            }
            
            hasParent[child]=true;
            mpp[parent]=parentNode;
            mpp[child]=childNode;
            
        }
        
        for(auto i: mpp)
        {
            if(hasParent[i.first]!=true)
            {
                return i.second;
            }
        }
        
        return NULL;
    }
};
