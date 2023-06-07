// Problem 4
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


    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if ((left == NULL) && (right == NULL)) {
            return 1;
        }
        if ((left != NULL) && (right != NULL)) {
            return (left->val == right->val) &&
                isSymmetric(left->right, right->left) &&  isSymmetric(left->left, right->right);
        }
        return 0;
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return 1;
        }
        return isSymmetric(root->left, root->right);
    }
};

int main()
{
    //Case 1
    Solution O;
    int A = 1, B = 2, C = 2, D = 3, E = 4, F = 4, G = 3;
    TreeNode* T1 = new TreeNode(A);
    T1->left = new TreeNode(B);
    T1->right = new TreeNode(C);
    T1->left->left = new TreeNode(D);
    T1->left->right = new TreeNode(E);
    T1->right->left = new TreeNode(F);
    T1->right->right = new TreeNode(G);
    cout << A << " " << B << " " << C << " " << D << " " << E << " " << F << " " << G << endl;

    if (O.isSymmetric(T1))
        cout << "true";
    else
        cout << "false";

    
        //Case 2

    A = 1, B = 2, C = 2, D = NULL, E = 3, F = NULL, G = 3;   

    TreeNode* T2 = new TreeNode(A);
    T2->left = new TreeNode(B);
    T2->right = new TreeNode(C);
    T2->left->left = new TreeNode(D);
    T2->left->right = new TreeNode(E);
    T2->right->left = new TreeNode(F);
    T2->right->right = new TreeNode(G);
    cout << endl << A << " " << B << " " << C << " " << D << " " << E << " " << F << " " << G << endl;

    
    if (O.isSymmetric(T2))
        cout << "true";
    else
        cout << "false";  
        
}