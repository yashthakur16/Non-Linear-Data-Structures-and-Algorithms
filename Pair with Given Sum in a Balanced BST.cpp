//(Brute force used not optimal however,will pass all test cases)


#include <bits/stdc++.h> 
/***********************************************
	The structure of Binary tree is given below: 
	
	template <typename T>
	class BinaryTreeNode {
	public:
		T data;
		BinaryTreeNode<T>* left;
		BinaryTreeNode<T>* right;

		BinaryTreeNode(T data) {
			this->data = data;
			left = NULL;
			right = NULL;
		}
	};
***********************************************/

void insert(vector<int> &node,BinaryTreeNode<int>* root)
{
	if(root==NULL)
	{
		return;
	}
	insert(node,root->left);
	node.push_back(root->data);
	insert(node,root->right);

	return;

}
bool findTargetPair(BinaryTreeNode<int>* root, int target)
{
	vector<int> node;

	insert(node,root);

	int n=node.size();

	sort(node.begin(),node.end());

	int i=0;
	n=n-1;

	while(i<n)
	{
		if(node[i]+node[n]==target)
		{
			return true;
		}
		else if(node[i]+node[n]>target)
		{
			n--;
		}
		else
		{
			i++;
		}

	}

	return false;
}
