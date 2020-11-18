 #include<bits/stdc++.h>
 #include<iostream>
 using namespace std;
 
 enum Color {Red,Black};
 struct Node
 {
 	int data;
 	bool color;
 	Node *left, *right, *parent;
 	Node(int data)
 	{
 		this->data = data;
 		left = right = parent = NULL;
 		this->color= Red;
	}
 };
 
 class RBTree
 {
 	private:
 		Node *root;
 	protected:
 		void leftRotate(Node *&, Node *&);
 		void rightRotate(Node *&, Node *&);
 		void fixViolation(Node *&, Node *&);
 	public:
 		RBTree() {
 			root =NULL;
		 }
		 void insert(const int &n);
		 void inorder();
		 void levelOrder();
};

void inorderHelp(Node *root)
{
	if (root == NULL)
		return;
	inorderHelp(root->left);
	cout << root->data << "-->";
	inorderHelp(root->right);
}

Node* BSTInsert(Node* root, Node *pt)
{
	if(root == NULL)
		return pt;
	if(pt->data < root->data)
	{
		root->left = BSTInsert(root->left ,pt);
		root->left->parent = root;
	}
	else if (pt->data > root->data)
	{
		root->right = BSTInsert(root->right,pt);
		root->right->parent = root;
	}
	
	return root;
}

void levelOrderHelp(Node *root)
{
	if(root == NULL)
		return;
	std::queue<Node *> q;
	q.push(root);
	while(!q.empty())
	{
		Node *temp = q.front();
		cout<< temp->data << "-->";
		q.pop();
		if(temp->left != NULL)
			q.push(temp->left);
		if(temp->right != NULL)
			q.push(temp->right);
	}
}

void RBTree::leftRotate(Node *&root , Node *&pt)
{
	Node *pt_right= pt->right;
	pt->right = pt_right->left;
	if(pt->right != NULL)
		pt->right->parent = pt;
	pt_right->parent = pt->parent;
	
	if(pt->parent == NULL)
		root = pt_right;
	else if(pt == pt->parent->left)
		pt->parent->left = pt_right;
	else
		pt->parent->right = pt_right;
	pt_right->left = pt;
	pt->parent = pt_right;
	
}

void RBTree::rightRotate(Node *&root, Node *&pt)
{
	Node *pt_left = pt->left;
	pt->left = pt_left->right;
	if(pt->left != NULL)
		pt->left->parent = pt;
	pt_left->parent = pt->parent;
	
	if(pt->parent == NULL)
		root = pt->left;
	else if(pt == pt->parent->left)
		pt->parent->left = pt_left;
	else
		pt->parent->right = pt_left;
	pt_left->right = pt;
	pt->parent = pt_left;
		
}

void RBTree::fixViolation(Node *&root, Node *&pt)
{
	Node *parent_pt = NULL;
	Node *grd_parent_pt = NULL;
	while((pt != root) && (pt->color != Black) && (pt->parent->color == Red))
	{
		parent_pt = pt->parent;
		grd_parent_pt = pt->parent->parent;
		
		if(parent_pt == grd_parent_pt->left)
		{
			Node *uncle_pt = grd_parent_pt->right;
			if(uncle_pt != NULL && uncle_pt->color == Red)
			{
				grd_parent_pt->color = Red;
				parent_pt->color = Black;
				pt = grd_parent_pt;
			}
			else
			{
				if(pt == parent_pt->right)
				{
					leftRotate(root,parent_pt);
					pt = parent_pt;
					parent_pt = pt->parent;
				}
				rightRotate(root,grd_parent_pt);
				swap(parent_pt->color,grd_parent_pt->color);
				pt = parent_pt;
			}
		}
		else
		{
			Node *uncle_pt = grd_parent_pt->left;
			if((uncle_pt != NULL) && (uncle_pt->color == Red))
			{
				grd_parent_pt->color = Black;
				uncle_pt->color = Black;
				pt = grd_parent_pt;
			}
			else
			{
				if(pt == parent_pt->left)
				{
					rightRotate(root,parent_pt);
					pt = parent_pt;
					parent_pt = pt->parent;
				}
				leftRotate(root,grd_parent_pt);
				swap(parent_pt->color, grd_parent_pt->color);
				pt = parent_pt;
			}
		}
	}
	root->color = Black;
}

void RBTree::insert(const int &data)
{
	Node *pt = new Node(data);
	root = BSTInsert(root,pt);
	fixViolation(root,pt);
	
}
void RBTree::inorder()
{
	inorderHelp(root);
}
void RBTree::levelOrder()
{
	levelOrderHelp(root);
}

int main()
{
	RBTree tree;
	int n,a[10000];
	cout<<"Enter the total number of nodes to be inserted:"<<endl;
	cin>>n;
	cout<<"Enter " << n << " elements ";
	for(int i = 0;i<n;i++)
	{
		cin>>a[i];
		tree.insert(a[i]);
	}
	cout<<"Inorder traversal of the Created tree:\n";
	tree.inorder();
	cout<<"\n";
	cout<<"Level order traversal of the created tree:\n";
	tree.levelOrder();
	return 0;
	
	
}
