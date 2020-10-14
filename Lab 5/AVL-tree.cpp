#include<bits/stdc++.h>
#include<iostream>
using namespace std;
 
class Node
{
	public:
		int key;
		Node *lft;
		Node *rgt;
		int height;
};

int height(Node *n)
{
	if(n == NULL)
		return 0;
	return n->height;
}
int max(int a,int b)
{
	return (a>b)? a : b;
}
Node* newNode(int key)
{
	Node* node= new Node();
	node->key=key;
	node->lft=NULL;
	node->rgt=NULL;
	node->height=1;
	return(node);
}
Node *leftrotate(Node *x)
{
	Node *y=x->rgt;
	Node *t=y->lft;
	
	y->lft=x;
	x->rgt=t;
	
	x->height=max(height(x->lft),height(x->rgt))+1;
	y->height=max(height(y->lft),height(y->rgt))+1;
	
	return y;
}

Node *rightrotate(Node *y)
{
	Node *x=y->lft;
	Node *t=x->rgt;
	
	x->rgt=y;
	y->lft=t;
	
	y->height=max(height(y->lft), height(y->rgt))+1;
	x->height=max(height(x->lft), height(x->rgt))+1;
	return x;
}

int get_Balance(Node *N)
{
	if(N == NULL)
		return 0;
	return height(N->lft) - height(N->rgt);
}
Node* min_node(Node* node)
{
	Node *curr=node;
	while(curr->lft!=NULL)
	{
	
		curr=curr->lft;
	}
	return curr;
}
Node* insert(Node* node,int key)
{
	if(node == NULL)
		return(newNode(key));
	if(key < node->key)
		node->lft = insert(node->lft,key);
	else if(key > node->key)
		node->rgt = insert(node->rgt,key);
	else
		return node;
	
	node->height = 1+ max(height(node->lft),height(node->rgt));
	
	int b_factor = get_Balance(node);
	
	if(b_factor > 1 && key < node->lft->key)
		return rightrotate(node);
		
	if(b_factor < -1 && key > node->rgt->key)
		return leftrotate(node);
		
	if(b_factor > 1 && key > node->lft->key)
	{
		node->lft = leftrotate(node->lft);
		return rightrotate(node);
	}
	
	if(b_factor < -1 && key < node->rgt->key)
	{
		node->rgt = rightrotate(node->rgt);	
		return leftrotate(node);
	}
	return node;	
}

Node* deleteNode(Node* root, int key)
{
	if(root == NULL)
		return root;
	
	if(key < root->key)
		root->lft = deleteNode(root->lft,key);
	else if(key > root->key)
		root->rgt = deleteNode(root->rgt,key);
	else
	{
		if(root->lft == NULL || root->rgt == NULL)
		{
			Node *temp = root->lft? root->lft :root->rgt;
			if(temp == NULL)
			{
				temp=root;
				root=NULL;
			}
			else
				*root = *temp;
				free(temp);
		}
		else
		{
			Node* temp=min_node(root->rgt);
			root->key=temp->key;
			root->rgt=deleteNode(root->rgt,key);
		}
	}
	if(root == NULL)
		return root;
	
	root->height = 1 + max(height(root->lft),height(root->rgt));
	
	int b_factor = get_Balance(root);
	
	if(b_factor > 1 && get_Balance(root->lft) >= 0 )
		return rightrotate(root);
		
	if(b_factor < -1 && get_Balance(root->rgt) <= 0)
		return leftrotate(root);
		
	if(b_factor > 1 && get_Balance(root->lft) < 0)
	{
		root->lft = leftrotate(root->lft);
		return rightrotate(root);
	}
	
	if(b_factor < -1 && get_Balance(root->rgt) > 0)
	{
		root->rgt = rightrotate(root->rgt);	
		return leftrotate(root);
	}
	return root;
	
}
void preorder(Node *root)
{	
	if(root!=NULL)
	{
		cout<<root->key<< "-->";
		preorder(root->lft);
		preorder(root->rgt);
	}
}
 
int main()
{
	Node *root=NULL;
	int num,a[num];
	int del;
	cout<<"Enter the total numbers of nodes:";
	cin>>num;
	cout<<"Enter the nodes to be inserted"<<endl;
	for(int i=0;i<num;i++)
	{
		cin>>a[i];
		root = insert(root,a[i]);
	}
	cout<<"Before deleting the node Traversal of tree is\n"<<endl;
	preorder(root);
	cout<<"\n\n"<<endl;
	cout<<"Enter the node to be deleted:"<<endl;
	cin>>del;
	root=deleteNode(root,del);
	cout<<"After deleting the node"<< del << "traversal of tree is"<<endl;
	preorder(root);
	return 0;
}



