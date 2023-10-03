//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

int findPos(int in[],int element,int inStart,int inEnd)
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

Node *solve(int in[], int post[], int &index, int inStart, int inEnd, int n)
{
    if(index < 0 || inStart > inEnd)
    {
        return NULL;
    }
    
    int element=post[index--];
    Node *root=new Node(element);
    int position=findPos(in,element,inStart,inEnd);
    
    
    root->right=solve(in,post,index,position+1,inEnd,n);
    root->left=solve(in,post,index,inStart,position-1,n);
    
    return root;
}

//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) 
{
    int index=n-1;
    Node *ans=solve(in,post,index,0,n-1,n);
    
    return ans;
}
