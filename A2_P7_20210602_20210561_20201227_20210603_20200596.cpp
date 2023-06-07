#include <iostream>
#include<string>
#include<bits/stdc++.h>

using namespace std;

class Node
{


public:
    int data;
     Node* left;
     Node* right;
 Node(int data)
{

    this->data = data;
    this->left = NULL;
    this->right = NULL;


}
};
/*
So the tree...
    1
    / \
    2 3
   / \
   4 5

is changed to...
    1
    / \
    3  2
      / \
      5 4
*/
class BT
{
public:
    Node* root;
    BT()
    {
        root =NULL;
    }
void mirror( Node* r )
{
    if (r == NULL)
        return;
    else
    {
         Node* temp;

        mirror(r->left);
        mirror(r->right);

        temp     = r->left;
        r->left = r->right;
        r->right = temp;
    }
}
void mirror()
{
    mirror(root);
}

void Preorder( Node* node)// root->left->right
{
         if(node==NULL)
            return;
         cout << node->data <<"\t";
         Preorder(node->left);
         Preorder(node->right);
}
void inOrder( Node* node)// left->root->right
{
    if (node == NULL)
        return;

    inOrder(node->left);
    cout << node->data << " \t";
    inOrder(node->right);
}
void Postorder( Node* node)// left->right->root
{
         if(node==NULL)
            return;

         Postorder(node->left);
         Postorder(node->right);
         cout << node->data <<" \t";

}
};

int main()
{
    BT t1, t2, t3, t4, t5, t6;

    t1.root=new Node(1);
    t1.root->left = new Node(2);
    t1.root->right = new Node(3);
    t1.root->left->left =  new Node(4);
    t1.root->left->right = new Node(5);

    cout << "Preorder traversal of the constructed"
         << "original tree is" << endl;
    t1.Preorder(t1.root);
    t1.mirror(t1.root);
    cout << "\nPreorder traversal of the new tree"
         << " is \n";
    t1.Preorder(t1.root);
    cout << "\nInorder traversal of the constructed"
         << " original tree is" << endl;
    t1.inOrder(t1.root);
    t1.mirror(t1.root);
    cout << "\nInorder traversal of the new tree"
         << " is \n";
    t1.inOrder(t1.root);

    cout << "\nPostorder traversal of the constructed"
         << " original tree is" << endl;
    t1.Postorder(t1.root);
    t1.mirror(t1.root);
    cout << "\nPostorder traversal of the new tree"
         << " is \n";
    t1.Postorder(t1.root);

cout<< "\n----------------------------------------------------------------------------------------------------------\n"<<endl;

// full binary tree
    t2.root = new Node(1);
    t2.root->left = new Node(2);
    t2.root->right = new Node(3);
    t2.root->left->left = new Node(4);
    t2.root->left->right = new Node(5);
    t2.root->right->left = new Node(6);

    cout << "Preorder traversal of the constructed"
         << "original tree is" << endl;
    t2.Preorder(t2.root);
    t2.mirror(t2.root);
    cout << "\nPreorder traversal of the new tree"
         << " is \n";
    t2.Preorder(t2.root);
    cout << "\nInorder traversal of the constructed"
         << " original tree is" << endl;
    t2.inOrder(t2.root);
    t2.mirror(t2.root);
    cout << "\nInorder traversal of the new tree"
         << " is \n";
    t2.inOrder(t2.root);

    cout << "\nPostorder traversal of the constructed"
         << " original tree is" << endl;
    t2.Postorder(t2.root);
    t2.mirror(t2.root);
    cout << "\nPostorder traversal of the new tree"
         << " is \n";
    t2.Postorder(t2.root);

cout<< "\n----------------------------------------------------------------------------------------------------------\n"<<endl;
//complete binary tree
    t3.root = new Node(1);
    t3.root->left = new Node(2);
    t3.root->right = new Node(3);
    t3.root->left->left = new Node(4);
    t3.root->left->right = new Node(5);
    t3.root->left->left->left = new Node(8);
    t3.root->right->left = new Node(6);
    t3.root->right->right = new Node(7);

    cout << "Preorder traversal of the constructed"
         << "original tree is" << endl;
    t3.Preorder(t3.root);
    t3.mirror(t3.root);
    cout << "\nPreorder traversal of the new tree"
         << " is \n";
    t3.Preorder(t3.root);
    cout << "\nInorder traversal of the constructed"
         << " original tree is" << endl;
    t3.inOrder(t3.root);
    t3.mirror(t3.root);
    cout << "\nInorder traversal of the new tree"
         << " is \n";
    t3.inOrder(t3.root);

    cout << "\nPostorder traversal of the constructed"
         << " original tree is" << endl;
    t3.Postorder(t3.root);
    t3.mirror(t3.root);
    cout << "\nPostorder traversal of the new tree"
         << " is \n";
    t3.Postorder(t3.root);

cout<< "\n----------------------------------------------------------------------------------------------------------\n"<<endl;

//perfect binary tree
    t4.root = new Node(1);
    t4.root->left = new Node(2);
    t4.root->right = new Node(3);
    t4.root->left->left = new Node(4);
    t4.root->left->right = new Node(5);
    t4.root->right->left = new Node(6);
    t4.root->right->right = new Node(7);

    cout << "Preorder traversal of the constructed"
         << "original tree is" << endl;
    t4.Preorder(t4.root);
    t4.mirror(t4.root);
    cout << "\nPreorder traversal of the new tree"
         << " is \n";
    t4.Preorder(t4.root);
    cout << "\nInorder traversal of the constructed"
         << " original tree is" << endl;
    t4.inOrder(t4.root);
    t4.mirror(t4.root);
    cout << "\nInorder traversal of the new tree"
         << " is \n";
    t4.inOrder(t4.root);

    cout << "\nPostorder traversal of the constructed"
         << " original tree is" << endl;
    t4.Postorder(t4.root);
    t4.mirror(t4.root);
    cout << "\nPostorder traversal of the new tree"
         << " is \n";
    t4.Postorder(t4.root);

cout<< "\n----------------------------------------------------------------------------------------------------------\n"<<endl;

//balanced binary tree
    t5.root = new Node(3);
    t5.root->left = new Node(9);
    t5.root->right = new Node(20);
    t5.root->right->left = new Node(15);
    t5.root->right->right = new Node(7);

    cout << "Preorder traversal of the constructed"
         << "original tree is" << endl;
    t5.Preorder(t5.root);
    t5.mirror(t5.root);
    cout << "\nPreorder traversal of the new tree"
         << " is \n";
    t5.Preorder(t5.root);
    cout << "\nInorder traversal of the constructed"
         << " original tree is" << endl;
    t5.inOrder(t5.root);
    t5.mirror(t5.root);
    cout << "\nInorder traversal of the new tree"
         << " is \n";
    t5.inOrder(t5.root);

    cout << "\nPostorder traversal of the constructed"
         << " original tree is" << endl;
    t5.Postorder(t5.root);
    t5.mirror(t5.root);
    cout << "\nPostorder traversal of the new tree"
         << " is \n";
    t5.Postorder(t5.root);

cout<< "\n----------------------------------------------------------------------------------------------------------\n"<<endl;

//A degenerate binary tree
    t6.root = new Node(1);
    t6.root->left = new Node(2);
    t6.root->left->right = new Node(3);
    t6.root->left->right->left = new Node(4);

    cout << "Preorder traversal of the constructed"
         << "original tree is" << endl;
    t6.Preorder(t6.root);
    t6.mirror(t6.root);
    cout << "\nPreorder traversal of the new tree"
         << " is \n";
    t6.Preorder(t6.root);
    cout << "\nInorder traversal of the constructed"
         << " original tree is" << endl;
    t6.inOrder(t6.root);
    t6.mirror(t6.root);
    cout << "\nInorder traversal of the new tree"
         << " is \n";
    t6.inOrder(t6.root);

    cout << "\nPostorder traversal of the constructed"
         << " original tree is" << endl;
    t6.Postorder(t6.root);
    t6.mirror(t6.root);
    cout << "\nPostorder traversal of the new tree"
         << " is \n";
    t6.Postorder(t6.root);

cout<< "\n----------------------------------------------------------------------------------------------------------\n"<<endl ;
    return 0;
}

















