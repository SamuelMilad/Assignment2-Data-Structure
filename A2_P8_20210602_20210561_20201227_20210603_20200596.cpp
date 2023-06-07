#include <iostream>
#include <string>
using namespace std;
class binary_tree {
public:
    char root = 0;
    binary_tree* left = NULL;
    binary_tree* right = NULL;

};
int D = 0;
void search(binary_tree* t, string preorder, const string& inorder) {


    if (t == NULL)
        return;


    t->root = preorder[D++];

    if (inorder.find(preorder[D - 1]) % 2 == 1) {
        t->left = new binary_tree;
        t->right = new binary_tree;
    }
    search(t->left, preorder, inorder);
    search(t->right, preorder, inorder);

}
void print(binary_tree* t) {
    if (t == nullptr)
        return;
    print(t->left);
    print(t->right);
    cout << t->root << " ";
}

void printPostOrder(string preorder, const string& inorder) {
    auto* t = new binary_tree;
    search(t, preorder, inorder);
    print(t);
}


int main() {

      //Case 1
    /*
             A
           /   \
          /     \
         B       C
        /  \
       /    \
      F      G


      PostOrder-->F G B C A

    */


    string preorder = "ABFGC";
    string inorder = "FBGAC";
    printPostOrder(preorder, inorder);
    


    // Case2
    /*
             A
           /   \
          /     \
         C       B
               /   \
              /     \
             E       F


       PostOrder--> C E F B A
    */
    /*
    string pre = "ACBEF";
    string in = "CAEBF";
    printPostOrder(pre, in);
    */



    //case 3
    /*
             A
           /   \
          /     \
         B       C
               /   \
              /     \
             D       E
            / \
           F   G

       PostOrder--> B F G D E C A

    */

    /*
    string pre = "ABCDFGE";
    string in = "ECGDFAB";
    printPostOrder(pre, in);
    */



    //Case 4
    /*
             A
           /   \
          /     \
         B       C
        /  \
       /    \
      D      E
            / \
           F   G


      PostOrder--> D F G E B C A
    */


    /*string pre = "ABDEFGC";
    string in = "CAGEFBD";
    printPostOrder(pre, in);
    */





    //Case 5
    /*
             A
           /   \
          /     \
         B       C
        / \     / \
       D   E   F   G


      PostOrder-->  D E B F G C A
    */

    /*
    string pre = "ABDECFG";
    string in = "GCFAEBD";
    printPostOrder(pre, in);
    */



}