#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template<class t>
class bstnode
{
public:
    t key;
    bstnode* left;
    bstnode* right;
public:
    bstnode()
    {
        right = NULL;
        left = NULL;
    }
    bstnode(t data, bstnode* right = 0, bstnode* left = 0)
    {
        key = data;
        this->right = right;
        this->left = left;
    }
    bstnode* getright()
    {
        return right;
    }
    bstnode* getleft()
    {
        return left;
    }
    t getkey()
    {
        return key;
    }
};
template<class t2>
int height(bstnode<t2>* node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + max(height(node->left), height(node->right));
    }
}
template<class t2>
bool isbalanced(bstnode<t2>* root)
{
    int lh;
    int rh;
    if (root == NULL)
    {
        return 1;
    }
    lh = height(root->left);
    rh = height(root->right);
    if (abs(lh - rh) <= 1 && isbalanced(root->left) && isbalanced(root->right))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
template<class t>
class bstfci
{
public:
    bstnode<t>* root;
public:
    bstfci()
    {
        root = NULL;
    }
    bstfci(t data)
    {
        root->key = data;
        root->left = root->right = NULL;
    }
    bstnode<t>* Insert_Node(t DATA, bstnode<t>* node)
    {
        if (node == NULL)
        {
            node = new bstnode<t>;
            node->key = DATA;
            node->left = node->right = NULL;
        }

        else if (DATA > node->key)
            node->right = Insert_Node(DATA, node->right);

        else if (DATA < node->key)
            node->left = Insert_Node(DATA, node->left);

        return node;
    }


    void Insert(t DATA)
    {
        root = Insert_Node(DATA, root);
    }

    void PrintTreeInOrder(bstnode<t>* node)
    {
        if (node != NULL)
        {
            PrintTreeInOrder(node->left);
            cout << node->key << endl;
            PrintTreeInOrder(node->right);
        }
    }

    //Function to call PrintTreeInOrder function.
    void PrintTreeInOrder()
    {
        PrintTreeInOrder(root);
        cout << endl << endl;
    }

};
template<class t2>
bool issubtree(bstnode<t2>* t, bstnode<t2>* s)
{
    if (s == NULL)
        return true;
    if (t == NULL)
        return false;
    return issubtree(t->left, s) || issubtree(t->right, s);
}
template<class t2>
bool issubtree(bstfci<t2>* tt1, bstfci<t2>* tt2)
{
    return issubtree(tt1->root, tt2->root);
}
template <typename t2>
void printrange(bstnode<t2>* root, int k1, int k2)
{
    if (root == NULL)
    {
        return;
    }
    if (k1 < root->key)
    {
        printrange(root->left, k1, k2);
    }
    if (k1 <= root->key && k2 >= root->key)
    {
        cout << root->key << " ";
    }
    if (k2 > root->key)
    {
        printrange(root->right, k1, k2);
    }
}

int main()
{
    bstfci <int>* test1 = new bstfci <int>();
    bstfci <int>* test2 = new bstfci <int>();
    bstfci <int>* test3 = new bstfci <int>();
    bstfci <int>* test4 = new bstfci <int>();
    bstfci <int>* test5 = new bstfci <int>();

// is balanced test cases
    test1->Insert(20);
    test1->Insert(8);
    test1->Insert(22);
    test1->Insert(4);
    test1->Insert(12);
    cout<<"this is balanced test cases :"<<endl;
    cout<<"first test case "<<endl;
    //test1->PrintTreeInOrder();
    if (!isbalanced(test1->root))
        cout << "\nNOT Balanced" << endl << endl;
    else
        cout << "\nBalanced" << endl << endl;


    test2->Insert(6);
    test2->Insert(7);
    test2->Insert(3);
    test2->Insert(2);
    test2->Insert(5);
    cout<<"second test case "<<endl;
   // test2->PrintTreeInOrder();
    if (!isbalanced(test2->root))
        cout << "\nNOT Balanced" << endl << endl;
    else
        cout << "\nBalanced" << endl << endl;

    test3->Insert(13);
    test3->Insert(4);
    test3->Insert(3);
    test3->Insert(7);
    test3->Insert(6);

    cout<<"third test case "<<endl;
   // test3->PrintTreeInOrder();
    if (!isbalanced(test3->root))
        cout << "\nNOT Balanced" << endl << endl;
    else
        cout << "\nBalanced" << endl << endl;


    test4->Insert(5);
    cout<<"fouth test case "<<endl;
    //test4->PrintTreeInOrder();
    if (!isbalanced(test4->root))
        cout << "\nNOT Balanced" << endl << endl;
    else
        cout << "\nBalanced" << endl << endl;

    cout<<"fifth test case "<<endl;
    if (!isbalanced(test5->root))
        cout << "\nNOT Balanced" << endl << endl;
    else
        cout << "\nBalanced" << endl << endl;


    cout << endl;



    cout<<"testing subtrees : "<<endl;
    cout<<endl;
    cout<<"testing subtree between tree 1 and tree 2 : ";
    cout << issubtree(test1, test3) << endl << endl;
    cout<<"testing subtree between tree 2 and tree 3 : ";
    cout << issubtree(test2, test3) << endl << endl;
    cout<<"testing subtree between tree 3 and tree 4 : ";
    cout << issubtree(test3, test4) << endl << endl;
    cout<<"testing subtree between tree 4 and tree 5 : ";
    cout << issubtree(test4, test5) << endl << endl;
    cout<<"testing subtree between tree 5 and tree 1 : ";
    cout << issubtree(test5, test1) << endl << endl;

    cout<<endl;
    cout<<"testing print range : "<<endl;
    cout<<endl;
    cout<<"tree 1 "<<endl;
    printrange(test1->root, 10, 25);
    cout<<endl;
    cout<<"tree 2 "<<endl;
    printrange(test2->root, 3, 8);
    cout<<endl;
    cout<<"tree 3 "<<endl;
    printrange(test3->root, 5, 9);
    cout<<endl;
    cout<<"tree 4 "<<endl;
    printrange(test4->root, 1, 10);
    cout<<endl;
    cout<<"tree 5 "<<endl;
    printrange(test5->root, 1, 10);
    cout<<endl;

}
