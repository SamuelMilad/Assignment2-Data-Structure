// Problem 5
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left),
        right(right) {}
};


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ((p && !q) || (!p && q))
            return false;
        else if (p && q)
        {
            if (p->val != q->val)
                return false;
            else
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        else return true;
    }
};


int main()
{
    //  Case 1
    
    int x,y,z;
    cout << "Tree 1 "<<endl;
    x = 1;
    y = 2;
    z = 3;
        TreeNode* tree1 = new TreeNode(x);
        tree1->left = new TreeNode(y);
        tree1->right = new TreeNode(z);       
        cout << x << "  " << y << "  " << z << endl;
    int A,B,C;
    cout << "Tree 2"<<endl;
    A = 1;
    B = 2;
    C = 3;
        TreeNode* tree2 = new TreeNode(A);
        tree2->left = new TreeNode(B);
        tree2->right = new TreeNode(C);
        cout << A << "  " << B << "  " << C << endl;
    Solution s;
    if (s.isSameTree(tree1, tree2))
        cout << "Ture";
    else
        cout << "False";
        
   

    //   Case 2
    
    int i,k;
    cout << endl << "Tree 1 " << endl;
    i = 1;
    k = 2;
        TreeNode* t1 = new TreeNode(i);
        t1->left = new TreeNode(k);    
        cout << i << "  " << k << endl;
    int a,b,c;
    cout << "Tree 2"<<endl;
    a = 1;
    b = NULL;
    c = 3;
        TreeNode* t2 = new TreeNode(a);
        t2->left = new TreeNode(b);
        t2->right = new TreeNode(c);
        cout << a << "  " << b << "  " << c << endl;
    if (s.isSameTree(t1, t2))
        cout << "Ture";
    else
        cout << "False";


    //   Case 3
    
    int p,w,e;
    cout << endl << "Tree 1 "<<endl;
    p = 1;
    w = 2;
    e = 1;
        TreeNode* T1 = new TreeNode(p);
        T1->left = new TreeNode(w);
        T1->right = new TreeNode(e);       
        cout << p << "  " << w << "  " << e << endl;
    int q,r,d;
    cout << "Tree 2"<<endl;
    q = 1;
    r = 1;
    d = 2;
        TreeNode* T2 = new TreeNode(q);
        T2->left = new TreeNode(r);
        T2->right = new TreeNode(d);
        cout << q << "  " << r << "  " << d << endl;
    if (s.isSameTree(T1, T2))
        cout << "Ture";
    else
        cout << "False";
}











