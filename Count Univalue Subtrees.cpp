/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
BinaryTreeNode<int> *solve(BinaryTreeNode<int> *root,int &count)
{
    if(root==NULL)
    {
        return NULL;
    }
    
    
    BinaryTreeNode<int> *leftAns=solve(root->left, count);
    BinaryTreeNode<int> *rightAns=solve(root->right, count);

    if(leftAns !=NULL && leftAns->data==root->data && (root->right==NULL))
    {
        count ++;
        return leftAns;
    }
    else if (rightAns !=NULL && rightAns->data==root->data && (root->left==NULL))
    {
        count ++;
        return rightAns;
    }
    else if(leftAns !=NULL && rightAns !=NULL && leftAns->data==rightAns->data && root->data==leftAns->data)
    {
        count++;
        return leftAns;
    }
    else if(root->left==NULL && root->right==NULL)
    {
        count++;
        return root;
    }
    else
    {
        return NULL;
    }

    

}



int countUnivalTrees(BinaryTreeNode<int> *root)
{
    int count=0;
    BinaryTreeNode<int> *ans=solve(root,count);
    return count;
}
