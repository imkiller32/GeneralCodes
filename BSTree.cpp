/*
General code For BinarySearchTree
Full Implementation
Using Struct
Func: insert,find,view(inorder,pre,post and lever order)
*/
#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root=NULL;

struct node *createNode(int val)
{
	struct node *temp=new node;
	temp->left=NULL;
	temp->right=NULL;
	temp->data=val;
}
void Insert()
{
	int value;
	cout<<"Enter a data to insert : ";
	cin>>value;
	struct node *temp=createNode(value);
	if(root==NULL)
	{
		root=temp;
		return;
	}
	struct node *t1=root;
	
	while(t1!=NULL)
	{
		if(t1->data < value)
			{
				if(t1->right==NULL)
					{
						t1->right=temp;
						break;
					}
				t1=t1->right;
			}
		else
			{
				if(t1->left==NULL)
				{
						t1->left=temp;
						break;
				}
				t1=t1->left;
			}
	}
	return;	
}
void Inorder(struct node *root)
{
	if(root==NULL)
	return;
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}
void PreOrder(struct node *root)
{
	if(root==NULL)
	return;
	cout<<root->data<<" ";
	PreOrder(root->left);
	PreOrder(root->right);
}
void PostOrder(struct node *root)
{
	if(root==NULL)
	return;
	PostOrder(root->left);
	PostOrder(root->right);
	cout<<root->data<<" ";
}

void LevelOrder(struct node *root)
{
	struct node *temp;
	queue<struct node *> q;
	if(root==NULL)
	return;
	q.push(root);
	while(!q.empty())
	{
		temp=q.front();
		q.pop();
		cout<<temp->data<<" ";
		if(temp->left)
		q.push(temp->left);
		if(temp->right)
		q.push(temp->right);
	}
}
void view()
{
	int choice;
	cout<<"1. Inorder View\n2. PreOrder View\n3. PostOrder View\n4. LevelOrder View\nEnter Your Choice:";
	cin>>choice;
	switch(choice)
	{
		case 1:
			cout<<"Inorder View-\n";
			Inorder(root);
			break;
		case 2:
			cout<<"PreOrder View-\n";
			PreOrder(root);
			break;
		case 3:
			cout<<"PostOrder View-\n";
			PostOrder(root);
			break;
		case 4:
			cout<<"LevelOrder View-\n";
			LevelOrder(root);
			break;
		default:
			cout<<"Invalid choice...\n";
	}
}
void Find()
{
	struct node *temp=root;
	int value;
	cout<<"\nEnter Value to find: ";
	cin>>value;
	while(temp!=NULL)
	{
		if(temp->data==value)
		{
			cout<<"\nValue Exist.\n";
			return;
		}
		else if(temp->data < value)
			temp=temp->right;
		else
			temp=temp->left;
	}
	cout<<"\nValue Not Found..\n";
}
int main()
{
	int choice;
	while(1)
	{
		cout<<"1. Insert\n2. Find\n3. View\n4. Exit\nEnter Your Choice : \n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				Insert();
				cout<<"Added Successfully.\n";
				break;
			case 2:
				Find();
				break;
			case 3:
				view();
				cout<<endl;
				break;
			case 4:
				return 0;
				break;
			default:
				cout<<"Enter a Valid Input..Try Again\n";
				break;
		}
	}
}
