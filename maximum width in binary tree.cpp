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
void levelordertraversal(TreeNode<int> *root,int &maxi)
{
   int count=0;

    queue<TreeNode<int> *> q;
    q.push(root);
    maxi++;
    q.push(NULL);

    while(!q.empty())
    {
        TreeNode<int> *temp=q.front();
        q.pop();

        if(temp==NULL)
        {
            maxi=max(count,maxi);
            count=0;
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
                count++;
            }
            if(temp->right)
            {
                q.push(temp->right);
                count++;
            }

        }
    }
}


int getMaxWidth(TreeNode<int> *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int maxi=0;
   levelordertraversal(root,maxi);

   return maxi;
}
