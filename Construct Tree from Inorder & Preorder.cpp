//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    
    int findPos(int in[], int element,int inStart,int inEnd)
    {
        for(int i=inStart;i<=inEnd;i++)
        {
            if(in[i]==element)
            {
                return i;
            }
        }
        return -1;
    }
    
    
    Node* solve(int in[],int pre[], int &n, int &index, int inStart, int inEnd)
    {
        if(index>=n || inStart > inEnd)
        {
            return NULL;
        }
        
        int element=pre[index++];
        Node *root=new Node(element);
        int position=findPos(in,element,inStart,inEnd);
        
        root->left=solve(in,pre,n,index,inStart,position-1);
        root->right=solve(in,pre,n,index,position+1,inEnd);
        
        return root;
    }
    
    
    
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        int index=0;
        Node *ans=solve(in,pre,n,index,0,n-1);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
// } Driver Code Ends
