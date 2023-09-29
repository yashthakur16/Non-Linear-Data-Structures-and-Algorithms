/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
    class BinaryTreeNode {
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
    
***********************************************************/
int inordertraversal(BinaryTreeNode<int> *root,int &count)
{
  if(root==NULL)
  {
    return 0;
  }
  inordertraversal(root->left,count);
  if(root->left==NULL && root->right==NULL)
  {
    count++;
  }
  inordertraversal(root->right,count);

  return count;
}

int noOfLeafNodes(BinaryTreeNode<int> *root)
{
  int count=0;
  return inordertraversal(root,count);
}
