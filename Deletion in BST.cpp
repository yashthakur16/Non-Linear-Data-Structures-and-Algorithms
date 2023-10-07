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

void inorderT(node* root)
{
    if(root==NULL)
    {
        return ;
    }
    inorderT(root->left);
    cout<<root->data<<" ";
    inorderT(root->right);

}


node* minval(node* root)
{
    node* current =root;

    while(current->left !=NULL)
    {
        current=current->left;
    }

    return current;

}

node* maxval(node* root)
{
    node* current =root;

    while(current->right !=NULL)
    {
        current=current->right;
    }

    return current;

}

node* deletefromBST(node* root,int val)
{
    if(root==NULL)
    {
        return NULL;
    }

    if(root->data==val)
    {
        // 0 child

        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            return NULL;
        }

        else if(root->left !=NULL && root->right==NULL)
        {
            node* temp=root->left;
            delete root;
            return temp;
        }

        else if(root->left==NULL && root->right !=NULL)
        {
            node* temp=root->right;
            delete root;
            return temp;
        }
        // 2 child

        else
        {
            int min=minval(root->right)->data;
            root->data=min;
            root->right=deletefromBST(root->right,min);
            return root;

        }
    }

    else if(root->data>val)
    {
        root->left=deletefromBST(root->left,val);
        return root;
    }
    else
    {
        root->right=deletefromBST(root->right,val);
        return root;
    }

}




int main()
{
    node*root=NULL;

    cout<<"Enter the data to create BST "<<endl;
    takeInput(root);

    levelordertraversal(root);

    cout<<endl;

    inorderT(root);

    cout<<endl;

    cout<<"Minimum Val is : "<<minval(root)->data<<endl;
    cout<<"Maximum Val is : "<<maxval(root)->data<<endl;

    root=deletefromBST(root,8);

    cout<<root->data<<endl;

    levelordertraversal(root);

    cout<<endl;

    inorderT(root);

    cout<<endl;

    cout<<"Minimum Val is : "<<minval(root)->data<<endl;
    cout<<"Maximum Val is : "<<maxval(root)->data<<endl;






}
