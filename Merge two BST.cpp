/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/
void solve(TreeNode *root,vector<int> &arr)
{
    if(root==NULL)
    {
        return;
    }

    solve(root->left,arr);
    arr.push_back(root->data);
    solve(root->right, arr);

}


vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
   vector<int> arr1;
   vector<int> arr2;
   solve(root1,arr1);
   solve(root2,arr2);

   int n=arr2.size();

   for(int i=0;i<n;i++)
   {
       arr1.push_back(arr2[i]);
   }
   sort(arr1.begin(),arr1.end()); 

   return arr1;


   

}
