#include<iostream>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};
node*newNode(int data)
{
    node* Node= new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}

bool is_node_Same(node* l, node* r)
{
    if (l == NULL && r == NULL) {
        return true;
    }
    if (l != NULL && r != NULL && is_node_Same(l->left, r->right) && is_node_Same(l->right, r->left)) {
        return true;
    }

    return false;
}

bool is_Foldable(node* root)
{
    bool res;
    if (root == NULL)
        return true;
    return is_node_Same(root->left, root->right);
}

int main(void)
 {  cout<< "test case_1:";
    /*
        1
       /  \
      4    2
       \   /
        5  3
    */
    node* root = newNode(1);
    root->left = newNode(4);
    root->right = newNode(2);
    root->right->left = newNode(3);
    root->left->right = newNode(5);

    if (is_Foldable(root))
        cout << "\n tree is foldable \n";
    else
        cout << "\n tree is not foldable \n";
/////////////////////////////////////////////////
 cout<<endl;
 cout<< "test case_2:";
    /*
        1
       /  \
      2    3
     /      \
    4        5
    */
    node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->right->right = newNode(5);
    root2->left->left = newNode(4);

    if (is_Foldable(root2))
        cout << "\n tree is foldable \n";
    else
        cout << "\n tree is not foldable \n";
/////////////////////////////////////////////////
 cout<<endl;
 cout<< "test case_3:";
    /*
        1
       /  \
      2    3
      /\    \
     4  6    5

    */
    node* root3 = newNode(1);
    root3->left = newNode(2);
    root3->right = newNode(3);
    root3->right->right = newNode(5);
    root3->left->left = newNode(4);
    root3->left->right=newNode(6);

    if (is_Foldable(root3))
        cout << "\n tree is foldable \n";
    else
        cout << "\n tree is not foldable \n";
/////////////////////////////////////////////////
 cout<<endl;
 cout<< "test case_4:";
   //is empty
    node* root4 = newNode(NULL);
    if (is_Foldable(root4))
        cout << "\n tree is foldable \n";
    else
        cout << "\n tree is not foldable \n";
/////////////////////////////////////////////////
 cout<<endl;
 cout<< "test case_5:";
    /*
         1
          \
           3
            \
             5
    */
    node* root5 = newNode(1);
    root5->right = newNode(3);
    root5->right->right = newNode(5);
    if (is_Foldable(root5))
        cout << "\n tree is foldable \n";
    else
        cout << "\n tree is not foldable \n";


    return 0;
}

