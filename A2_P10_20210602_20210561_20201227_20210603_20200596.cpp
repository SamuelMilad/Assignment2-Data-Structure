#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node*left;
	Node*right;
};

Node*create_Node(int data)
{
	Node*node=new Node;
	node->left=NULL;
	node->right=NULL;
	node->data=data;
	return node;
}
Node*insert_node(Node*root,int value)
{
	if (root==NULL)
		return create_Node(value);
	if (root->data > value)
		root->left = insert_node(root->left,value);
	else if (root->data < value)
		root->right = insert_node(root->right,value);
	return root;
}

int find_smallest(Node*root,int k,int&counter)
{
	if (root==NULL)
		return 0;
	if (counter > k)
		return 0;
	int result=find_smallest(root->left,k,counter);
	if (counter >= k)
		return result;
	result+= root->data;
	counter++;
	if (counter >= k)
	return result;
	return result+find_smallest(root->right,k,counter);
}

int calculate_sum(Node*root,int k)
{
int counter=0;
find_smallest(root,k,counter);
}
int main()
{   cout<< "test case_1:"<<endl;
	Node*root= NULL;
	root=insert_node(root,54);
	root=insert_node(root,74);
	root=insert_node(root,51);
	root=insert_node(root,75);
	root=insert_node(root,85);
	root=insert_node(root,52);
	root=insert_node(root,49);
	int k=3;
	cout << calculate_sum(root,k)<<endl;
/////////////////////////////////////////////////////////
	 cout<< "test case_2:"<<endl;
	Node*root2=NULL;
	root2=insert_node(root2,40);
	root2=insert_node(root2,50);
	root2=insert_node(root2,60);
	root2=insert_node(root2,70);
	root2=insert_node(root2,80);
	root2=insert_node(root2,90);
	root2=insert_node(root2,100);
	 k=3;
	cout<< calculate_sum(root2,k)<<endl;
/////////////////////////////////////////////////////////
	 cout<< "test case_3:"<<endl;
	Node*root3=NULL;
	root3=insert_node(root3,20);
	root3=insert_node(root3,10);
	root3=insert_node(root3,51);
	root3=insert_node(root3,60);
	root3=insert_node(root3,85);
	root3=insert_node(root3,100);
	root3=insert_node(root3,49);
	 k=4;
	cout<< calculate_sum(root3,k)<<endl;
/////////////////////////////////////////////////////////
	 cout<< "test case_4:"<<endl;
	Node*root4=NULL;
	root4=insert_node(root4,54);
	root4=insert_node(root4,74);
	root4=insert_node(root4,51);
	root4=insert_node(root4,75);
	root4=insert_node(root4,85);
	root4=insert_node(root4,52);
	root4=insert_node(root4,49);
	 k=5;
	cout<<calculate_sum(root4,k)<<endl;
/////////////////////////////////////////////////////////
	 cout<< "test case_5:"<<endl;
	Node*root5=NULL;
	root5=insert_node(root5,30);
	root5=insert_node(root5,74);
	root5=insert_node(root5,300);
	root5=insert_node(root5,10);
	root5=insert_node(root5,202);
	root5=insert_node(root5,52);
	root5=insert_node(root5,24);
	 k=3;
	cout<<calculate_sum(root5,k)<<endl;
	return 0;
}
