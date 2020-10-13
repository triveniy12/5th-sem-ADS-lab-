#include<iostream>

using namespace std;

class node
{
	public:
		int data;
		node* npx;
	
};

node* XOR(node* a, node* b)
{
	return (node*) ((uintptr_t) (a) ^ (uintptr_t) (b)); 
}

void insert_at_begin(node **first, int data)
{
	node *new_node=new node();
	new_node->data=data;
	new_node->npx=*first;
	if(*first!=NULL)
	{
		(*first)->npx = XOR(new_node , (*first)->npx);
	}
	*first=new_node;
}

void insert_at_end(node **first,int data)
{
	
	node *prev=NULL;
	node *curr=*first;
	node *next=XOR(prev,curr->npx);
	while(next)
	{
		prev=curr;
		curr=next;
		next=XOR(prev,curr->npx);
	}
	next=new node();
	next->data=data;
	next->npx=XOR(curr,NULL);
	curr->npx=XOR(curr->npx,next);
}

void printList (node *first)  
{  
    node *curr = first;  
    node *prev = NULL;  
    node *next;  
  
  
    while (curr != NULL)  
    {  
      
        cout<<curr->data<<" ";  
		next = XOR (prev, curr->npx);  
		prev = curr;  
        curr = next;  
    }  
} 

int main ()  
{  
   
    node *first = NULL;  
    insert_at_begin(&first, 10);  
    insert_at_begin(&first, 20);  
    insert_at_begin(&first, 30);  
    insert_at_begin(&first, 40); 
	cout<<"Nodes inserted using insert_at_beg function\n"<<endl;  
    printList (first);  
    
    insert_at_end(&first, 10);
    insert_at_end(&first, 20);
    insert_at_end(&first, 30);
    insert_at_end(&first, 40);
    cout<<"\nNodes inserted at end using insert_at_end function\n"<<endl;
    printList(first);
  
    return (0);  
}  
