#include<iostream>
#include<queue>
using namespace std;

class node
{
    public:

    int data;
    node* left;
    node* right;

    node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }

};

node *insertInBST(node* &root,int data)
{
    if(root==NULL)
    {
        root=new node(data);
        return root;
    }
    if(data>root->data)
    {
        root->right=insertInBST(root->right,data);
    }
    else
    {
        root->left=insertInBST(root->left,data);
    }
    return root;
}

void takeInput(node* &root)
{
    int data;
    cin>>data;

    while(data !=-1)
    {
        root=insertInBST(root,data);
        cin>>data;
    }
}

void levelordertraversal(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node *temp=q.front();
        
        q.pop();

        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }

        
    }
}

int main()
{
    node*root=NULL;

    cout<<"Enter the data to create BST "<<endl;
    takeInput(root);

    levelordertraversal(root);


}
